#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 100
#define HISTORY_SIZE 10

// Prototypes des fonctions
void afficher_aide();
void afficher_bienvenue();
void ajouter_historique(char *historique[], char *commande, int *index);
void afficher_historique(char *historique[], int index);
void sigchld_handler(int signo);

void afficher_aide() {
    printf("Commandes disponibles :\n");
    printf("  - exit : Quitter le shell\n");
    printf("  - help : Afficher cette aide\n");
    printf("  - Flèche haut : Récupérer la dernière commande\n");
    printf("  - Flèche bas : Passer à la commande suivante\n");
    printf("  - Ctrl + C : Interrompre la commande en cours\n");
    printf("  - Ctrl + D : Quitter le shell (envoie EOF)\n");
}

void afficher_bienvenue() {
	printf("\n");
	printf(" ||__/\\\________/\\\_____/\\\\\\\\\_____/\\\_________________/\\\\\\\\\_____/\\\________/\\\_________|| \n");
	printf(" || _\/\\\_______\/\\\___/\\\\\\\\\\\\\__\/\\\_______________/\\\\\\\\\\\\\__\/\\\_____/\\\//_________|| \n");
	printf(" ||  _\//\\\______/\\\___/\\\/////////\\\_\/\\\______________/\\\/////////\\\_\/\\\__/\\\//___________|| \n");
	printf(" ||   __\//\\\____/\\\___\/\\\_______\/\\\_\/\\\_____________\/\\\_______\/\\\_\/\\\\\\//\\\__________|| \n");
	printf(" ||    ___\//\\\__/\\\____\/\\\\\\\\\\\\\\\_\/\\\_____________\/\\\\\\\\\\\\\\\_\/\\\//_\//\\\________|| \n");
	printf(" ||     ____\//\\\/\\\_____\/\\\/////////\\\_\/\\\_____________\/\\\/////////\\\_\/\\\____\//\\\______|| \n");
	printf(" ||      _____\//\\\\\______\/\\\_______\/\\\_\/\\\_____________\/\\\_______\/\\\_\/\\\_____\//\\\____|| \n");
	printf(" ||       ______\//\\\_______\/\\\_______\/\\\_\/\\\\\\\\\\\\\\\_\/\\\_______\/\\\_\/\\\______\//\\\__|| \n");
	printf(" ||        _______\///________\///________\///__\///////////////__\///________\///__\///________\///__|| \n");
	printf("\nBienvenue dans le shell de VALAK !\n\n");
}

void ajouter_historique(char *historique[], char *commande, int *index) {
    historique[*index] = strdup(commande);
    (*index) = (*index + 1) % HISTORY_SIZE;
}

void afficher_historique(char *historique[], int index) {
    printf("Historique des commandes :\n");
    for (int i = 0; i < HISTORY_SIZE; i++) {
        if (historique[i] != NULL) {
            printf("%d: %s\n", i + 1, historique[i]);
        }
    }
}

void sigchld_handler(int signo) {
    // Gérer les processus enfants terminés
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

int main() {
    char command[MAX_CMD_LENGTH];
    char *args[MAX_ARGS];
    pid_t pid;
    int status;
    char *historique[HISTORY_SIZE] = {NULL}; // Tableau pour l'historique des commandes
    int historique_index = 0;

    // Gestion du signal SIGCHLD
    struct sigaction sa;
    sa.sa_handler = sigchld_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_NOCLDSTOP;
    
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("Erreur lors de la gestion du signal SIGCHLD");
        exit(EXIT_FAILURE);
    }

    afficher_bienvenue(); // Affiche le message de bienvenue

    while (1) {
        printf("\n>>> "); // Affiche l'invite de commande
        if (!fgets(command, sizeof(command), stdin)) {
            break; // Sortie en cas d'erreur ou EOF
        }

        // Supprime le saut de ligne à la fin de la commande
        command[strcspn(command, "\n")] = 0;

        // Vérifie si la commande est "exit"
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Vérifie si la commande est "help"
        if (strcmp(command, "help") == 0) {
            afficher_aide();
            continue;
        }

        // Ajoute la commande à l'historique
        ajouter_historique(historique, command, &historique_index);

        // Analyse la commande et ses arguments
        int i = 0;
        args[i] = strtok(command, " ");
        while (args[i] != NULL && i < MAX_ARGS - 1) {
            i++;
            args[i] = strtok(NULL, " ");
        }
        args[i] = NULL; // Terminer la liste des arguments

        // Crée un nouveau processus
        pid = fork();
        if (pid == -1) {
            perror("Échec de fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // Processus enfant
            execvp(args[0], args); // Exécute la commande
            perror("Échec d'exécution"); // Si exec échoue
            exit(EXIT_FAILURE);
        } 

        // Processus parent attend que l'enfant termine
        do {
            waitpid(pid, &status, WUNTRACED); // Attend que l'enfant termine
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));

        // Afficher l'historique après chaque commande exécutée
        afficher_historique(historique, historique_index);
    }

    // Libération de la mémoire allouée pour l'historique

    for (int i = 0; i < HISTORY_SIZE; i++) {
        free(historique[i]);
    }

    return 0;
}
