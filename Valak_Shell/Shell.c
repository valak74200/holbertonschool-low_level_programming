#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64
#define MAX_HISTORY 1000

// Couleurs ANSI
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"

typedef struct {
    char *name;
    char *value;
} EnvVar;

EnvVar env_vars[100];
int env_var_count = 0;

char **tokenize(char *line) {
    char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
    char *token = strtok(line, " \t\n");
    int i = 0;

    while (token != NULL && i < MAX_NUM_TOKENS) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, " \t\n");
    }
    tokens[i] = NULL;
    return tokens;
}

void execute_command(char **args, int input_fd, int output_fd) {
    pid_t pid = fork();

    if (pid == 0) { // Child process
        if (input_fd != STDIN_FILENO) {
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
        }
        if (output_fd != STDOUT_FILENO) {
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);
        }

        for (int i = 0; args[i] != NULL; i++) {
            if (args[i][0] == '$') {
                for (int j = 0; j < env_var_count; j++) {
                    if (strcmp(args[i] + 1, env_vars[j].name) == 0) {
                        args[i] = env_vars[j].value;
                        break;
                    }
                }
            }
        }

        execvp(args[0], args);
        fprintf(stderr, COLOR_RED "Erreur: Commande non trouvée: %s\n" COLOR_RESET, args[0]);
        exit(1);
    } else if (pid < 0) {
        perror("fork");
    } else {
        wait(NULL);
    }
}

void handle_pipe(char **args1, char **args2) {
    int pipefd[2];
    pipe(pipefd);

    execute_command(args1, STDIN_FILENO, pipefd[1]);
    close(pipefd[1]);
    execute_command(args2, pipefd[0], STDOUT_FILENO);
    close(pipefd[0]);
}

void set_env_var(char *name, char *value) {
    for (int i = 0; i < env_var_count; i++) {
        if (strcmp(env_vars[i].name, name) == 0) {
            free(env_vars[i].value);
            env_vars[i].value = strdup(value);
            return;
        }
    }
    env_vars[env_var_count].name = strdup(name);
    env_vars[env_var_count].value = strdup(value);
    env_var_count++;
}

char* get_current_dir() {
    static char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        return cwd;
    } else {
        perror("getcwd() error");
        return "unknown";
    }
}

char* prompt() {
    static char prompt_str[1024];
    snprintf(prompt_str, sizeof(prompt_str), COLOR_GREEN "%s" COLOR_BLUE " %s " COLOR_YELLOW "$ " COLOR_RESET,
             getenv("USER"), get_current_dir());
    return prompt_str;
}

char** command_completion(const char* text, int start, int end) {
    rl_attempted_completion_over = 1;
    return rl_completion_matches(text, rl_filename_completion_function);
}

int main() {
    char *input;
    char **tokens;
    int i;

    // Configuration de readline
    rl_attempted_completion_function = command_completion;
    
    using_history();
    read_history(".shell_history");

    while (1) {
        input = readline(prompt());
        
        if (!input) break;  // EOF (Ctrl+D)

        // Ajout à l'historique si la commande n'est pas vide
        if (*input) add_history(input);

        tokens = tokenize(input);

        if (tokens[0] == NULL) {
            free(input);
            free(tokens);
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0) {
            printf(COLOR_YELLOW "Au revoir !\n" COLOR_RESET);
            break;
        }

        if (strcmp(tokens[0], "export") == 0) {
            char *eq = strchr(tokens[1], '=');
            if (eq) {
                *eq = '\0';
                set_env_var(tokens[1], eq + 1);
                printf(COLOR_GREEN "Variable d'environnement définie : %s=%s\n" COLOR_RESET, tokens[1], eq + 1);
            }
            free(input);
            for (i = 0; tokens[i] != NULL; i++) free(tokens[i]);
            free(tokens);
            continue;
        }

        int input_fd = STDIN_FILENO;
        int output_fd = STDOUT_FILENO;
        char **cmd = tokens;

        for (i = 0; tokens[i] != NULL; i++) {
            if (strcmp(tokens[i], ">") == 0) {
                tokens[i] = NULL;
                output_fd = open(tokens[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                break;
            } else if (strcmp(tokens[i], "<") == 0) {
                tokens[i] = NULL;
                input_fd = open(tokens[i+1], O_RDONLY);
                break;
            } else if (strcmp(tokens[i], "|") == 0) {
                tokens[i] = NULL;
                handle_pipe(cmd, &tokens[i+1]);
                goto cleanup;
            }
        }

        execute_command(cmd, input_fd, output_fd);

        if (input_fd != STDIN_FILENO)
            close(input_fd);
        if (output_fd != STDOUT_FILENO)
            close(output_fd);

cleanup:
        free(input);
        for (i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }

    // Sauvegarde de l'historique
    write_history(".shell_history");

    // Libération des variables d'environnement
    for (i = 0; i < env_var_count; i++) {
        free(env_vars[i].name);
        free(env_vars[i].value);
    }

    return 0;
}
