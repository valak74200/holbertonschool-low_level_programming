#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <windows.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64
#define MAX_HISTORY 1000

// Couleurs pour Windows
#define COLOR_RED     12
#define COLOR_GREEN   10
#define COLOR_YELLOW  14
#define COLOR_BLUE    9
#define COLOR_RESET   7

typedef struct {
    char *name;
    char *value;
} EnvVar;

EnvVar env_vars[100];
int env_var_count = 0;

void set_console_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

char **tokenize(char *line) {
    char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
    char *token = strtok(line, " \t\n");
    int i = 0;

    while (token != NULL && i < MAX_NUM_TOKENS) {
        tokens[i] = _strdup(token);
        i++;
        token = strtok(NULL, " \t\n");
    }
    tokens[i] = NULL;
    return tokens;
}

void execute_command(char **args) {
    // Simplified for Windows
    system(args[0]);
}

void set_env_var(char *name, char *value) {
    for (int i = 0; i < env_var_count; i++) {
        if (strcmp(env_vars[i].name, name) == 0) {
            free(env_vars[i].value);
            env_vars[i].value = _strdup(value);
            return;
        }
    }
    env_vars[env_var_count].name = _strdup(name);
    env_vars[env_var_count].value = _strdup(value);
    env_var_count++;
}

char* get_current_dir() {
    static char cwd[1024];
    if (_getcwd(cwd, sizeof(cwd)) != NULL) {
        return cwd;
    } else {
        perror("getcwd() error");
        return "unknown";
    }
}

void prompt() {
    set_console_color(COLOR_GREEN);
    printf("%s", getenv("USERNAME"));
    set_console_color(COLOR_BLUE);
    printf(" %s ", get_current_dir());
    set_console_color(COLOR_YELLOW);
    printf("$ ");
    set_console_color(COLOR_RESET);
}

int main() {
    char input[MAX_INPUT_SIZE];
    char **tokens;
    int i;

    while (1) {
        prompt();
        if (fgets(input, sizeof(input), stdin) == NULL) break;

        input[strcspn(input, "\n")] = 0; // Remove newline

        if (strlen(input) == 0) continue;

        tokens = tokenize(input);

        if (tokens[0] == NULL) {
            free(tokens);
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0) {
            set_console_color(COLOR_YELLOW);
            printf("Au revoir !\n");
            set_console_color(COLOR_RESET);
            break;
        }

        if (strcmp(tokens[0], "export") == 0) {
            char *eq = strchr(tokens[1], '=');
            if (eq) {
                *eq = '\0';
                set_env_var(tokens[1], eq + 1);
                set_console_color(COLOR_GREEN);
                printf("Variable d'environnement définie : %s=%s\n", tokens[1], eq + 1);
                set_console_color(COLOR_RESET);
            }
        } else {
            execute_command(tokens);
        }

        for (i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }

    // Libération des variables d'environnement
    for (i = 0; i < env_var_count; i++) {
        free(env_vars[i].name);
        free(env_vars[i].value);
    }

    return 0;
}
