#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <process.h>
#include <direct.h>
#include <conio.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGS 100
#define MAX_PATH_LENGTH 1000
#define MAX_ENV_VARS 100
#define MAX_JOBS 10

typedef struct {
    char *name;
    char *value;
} EnvVar;

typedef struct {
    PROCESS_INFORMATION pi;
    char command[MAX_COMMAND_LENGTH];
} Job;

EnvVar env_vars[MAX_ENV_VARS];
int env_var_count = 0;

Job jobs[MAX_JOBS];
int job_count = 0;

char current_dir[MAX_PATH_LENGTH];

void print_prompt() {
    _getcwd(current_dir, sizeof(current_dir));
    printf("\033[1;34m%s>\033[0m ", current_dir);
}

void set_env_var(char *name, char *value) {
    for (int i = 0; i < env_var_count; i++) {
        if (strcmp(env_vars[i].name, name) == 0) {
            free(env_vars[i].value);
            env_vars[i].value = _strdup(value);
            return;
        }
    }
    if (env_var_count < MAX_ENV_VARS) {
        env_vars[env_var_count].name = _strdup(name);
        env_vars[env_var_count].value = _strdup(value);
        env_var_count++;
    }
}

char *get_env_var(char *name) {
    for (int i = 0; i < env_var_count; i++) {
        if (strcmp(env_vars[i].name, name) == 0) {
            return env_vars[i].value;
        }
    }
    return NULL;
}

void expand_wildcards(char *arg, char **expanded_args, int *expanded_count) {
    WIN32_FIND_DATA find_data;
    HANDLE hFind = FindFirstFile(arg, &find_data);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            expanded_args[(*expanded_count)++] = _strdup(find_data.cFileName);
        } while (FindNextFile(hFind, &find_data) != 0);
        FindClose(hFind);
    } else {
        expanded_args[(*expanded_count)++] = _strdup(arg);
    }
}

void parse_command(char *input, char **args, int *arg_count) {
    char *token = strtok(input, " \t\n");
    *arg_count = 0;
    char *expanded_args[MAX_ARGS * 10];
    int expanded_count = 0;

    while (token != NULL && *arg_count < MAX_ARGS - 1) {
        if (strchr(token, '*') || strchr(token, '?')) {
            expand_wildcards(token, expanded_args, &expanded_count);
        } else {
            expanded_args[expanded_count++] = _strdup(token);
        }
        token = strtok(NULL, " \t\n");
    }

    for (int i = 0; i < expanded_count && *arg_count < MAX_ARGS - 1; i++) {
        args[(*arg_count)++] = expanded_args[i];
    }
    args[*arg_count] = NULL;
}

void execute_command(char **args) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    char command_line[MAX_COMMAND_LENGTH] = "";
    for (int i = 0; args[i] != NULL; i++) {
        strcat(command_line, args[i]);
        strcat(command_line, " ");
    }

    if (CreateProcess(NULL, command_line, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        printf("Erreur lors de l'exécution de la commande.\n");
    }
}

void execute_background(char **args) {
    if (job_count >= MAX_JOBS) {
        printf("Nombre maximum de jobs atteint.\n");
        return;
    }

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    char command_line[MAX_COMMAND_LENGTH] = "";
    for (int i = 0; args[i] != NULL; i++) {
        strcat(command_line, args[i]);
        strcat(command_line, " ");
    }

    if (CreateProcess(NULL, command_line, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
        jobs[job_count].pi = pi;
        strcpy(jobs[job_count].command, command_line);
        job_count++;
        printf("[%d] %d\n", job_count, pi.dwProcessId);
    } else {
        printf("Erreur lors de l'exécution de la commande en arrière-plan.\n");
    }
}

void list_jobs() {
    for (int i = 0; i < job_count; i++) {
        DWORD exit_code;
        if (GetExitCodeProcess(jobs[i].pi.hProcess, &exit_code)) {
            if (exit_code == STILL_ACTIVE) {
                printf("[%d] Running %s\n", i + 1, jobs[i].command);
            } else {
                printf("[%d] Done %s\n", i + 1, jobs[i].command);
                CloseHandle(jobs[i].pi.hProcess);
                CloseHandle(jobs[i].pi.hThread);
                for (int j = i; j < job_count - 1; j++) {
                    jobs[j] = jobs[j + 1];
                }
                job_count--;
                i--;
            }
        }
    }
}

void complete_command(char *partial_command) {
    DIR *dir;
    struct dirent *entry;
    char *last_slash = strrchr(partial_command, '\\');
    char dir_path[MAX_PATH_LENGTH] = ".";
    char file_prefix[MAX_PATH_LENGTH] = "";

    if (last_slash) {
        strncpy(dir_path, partial_command, last_slash - partial_command + 1);
        dir_path[last_slash - partial_command + 1] = '\0';
        strcpy(file_prefix, last_slash + 1);
    } else {
        strcpy(file_prefix, partial_command);
    }

    dir = opendir(dir_path);
    if (dir) {
        while ((entry = readdir(dir)) != NULL) {
            if (strncmp(entry->d_name, file_prefix, strlen(file_prefix)) == 0) {
                printf("%s\n", entry->d_name);
            }
        }
        closedir(dir);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    int arg_count;

    while (1) {
        print_prompt();
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0) continue;

        if (input[strlen(input) - 1] == '&') {
            input[strlen(input) - 1] = '\0';
            parse_command(input, args, &arg_count);
            execute_background(args);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else if (strncmp(input, "cd ", 3) == 0) {
            _chdir(input + 3);
        } else if (strcmp(input, "jobs") == 0) {
            list_jobs();
        } else if (strncmp(input, "export ", 7) == 0) {
            char *eq = strchr(input + 7, '=');
            if (eq) {
                *eq = '\0';
                set_env_var(input + 7, eq + 1);
            }
        } else if (input[strlen(input) - 1] == '\t') {
            input[strlen(input) - 1] = '\0';
            complete_command(input);
        } else {
            parse_command(input, args, &arg_count);
            execute_command(args);
        }

        for (int i = 0; i < arg_count; i++) {
            free(args[i]);
        }
    }

    for (int i = 0; i < env_var_count; i++) {
        free(env_vars[i].name);
        free(env_vars[i].value);
    }

    return 0;
}
