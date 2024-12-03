#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <windows.h>
#include <io.h>
#include <conio.h>
#include <process.h>
#include <time.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64
#define MAX_PATH 260
#define MAX_HISTORY 100
#define MAX_ALIASES 50

// Couleurs pour Windows
#define COLOR_RED     12
#define COLOR_GREEN   10
#define COLOR_YELLOW  14
#define COLOR_BLUE    9
#define COLOR_MAGENTA 13
#define COLOR_CYAN    11
#define COLOR_WHITE   15
#define COLOR_RESET   7

typedef struct {
    char *name;
    char *value;
} EnvVar;

typedef struct {
    char *name;
    char *command;
} Alias;

EnvVar env_vars[100];
int env_var_count = 0;

char history[MAX_HISTORY][MAX_INPUT_SIZE];
int history_count = 0;
int history_index = 0;

Alias aliases[MAX_ALIASES];
int alias_count = 0;

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

void add_to_history(const char *command) {
    if (history_count < MAX_HISTORY) {
        strcpy(history[history_count++], command);
    } else {
        for (int i = 1; i < MAX_HISTORY; i++) {
            strcpy(history[i-1], history[i]);
        }
        strcpy(history[MAX_HISTORY-1], command);
    }
    history_index = history_count;
}

void display_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%3d  %s\n", i + 1, history[i]);
    }
}

void add_alias(const char *name, const char *command) {
    if (alias_count < MAX_ALIASES) {
        aliases[alias_count].name = _strdup(name);
        aliases[alias_count].command = _strdup(command);
        alias_count++;
        printf("Alias ajouté : %s='%s'\n", name, command);
    } else {
        printf("Nombre maximum d'alias atteint.\n");
    }
}

char *get_alias(const char *name) {
    for (int i = 0; i < alias_count; i++) {
        if (strcmp(aliases[i].name, name) == 0) {
            return aliases[i].command;
        }
    }
    return NULL;
}

void list_aliases() {
    for (int i = 0; i < alias_count; i++) {
        printf("%s='%s'\n", aliases[i].name, aliases[i].command);
    }
}

// Déclaration de la fonction matrix_animation avant son utilisation
void matrix_animation(int* running_flag);

void execute_command(char **args) {
    char *alias_command = get_alias(args[0]);
    
    if (alias_command) { // Exécuter l'alias si trouvé
        char full_command[MAX_INPUT_SIZE] = "";
        strcat(full_command, alias_command);
        for (int i = 1; args[i] != NULL; i++) {
            strcat(full_command, " ");
            strcat(full_command, args[i]);
        }
        system(full_command);
        return;
    }

    if (strcmp(args[0], "cd") == 0) { // Implémentation de cd
        if (args[1] == NULL) { // Aller au répertoire personnel si aucun argument n'est fourni
            _chdir(getenv("USERPROFILE"));
        } else { // Changer de répertoire avec gestion des espaces dans le chemin
            if (_chdir(args[1]) != 0) { // Utilisation de _chdir pour changer de répertoire
                perror("cd");
            }
        }
    } else if (strcmp(args[0], "ls") == 0) { // Implémentation de ls
        WIN32_FIND_DATA findFileData;
        HANDLE hFind = FindFirstFile("*", &findFileData);
        
        if (hFind == INVALID_HANDLE_VALUE) {
            printf("Error in FindFirstFile\n");
            return;
        }

        do {
            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                set_console_color(COLOR_BLUE); // Couleur pour les répertoires
            } else {
                set_console_color(COLOR_WHITE); // Couleur pour les fichiers
            }
            printf("%s\n", findFileData.cFileName);
        } while (FindNextFile(hFind, &findFileData) != 0);

        FindClose(hFind);
        set_console_color(COLOR_RESET); // Réinitialiser la couleur
    } else if (strcmp(args[0], "pwd") == 0) { // Implémentation de pwd
        char cwd[MAX_PATH];
        
        if (_getcwd(cwd, sizeof(cwd)) != NULL) { 
            printf("%s\n", cwd); 
        } else { 
            perror("getcwd"); 
        } 
    } else if (strcmp(args[0], "echo") == 0) { // Implémentation de echo
        for (int i = 1; args[i] != NULL; i++) { 
            printf("%s ", args[i]); 
        } 
        printf("\n"); 
    } else if (strcmp(args[0], "touch") == 0) { // Implémentation de touch pour créer un fichier
        if (args[1] != NULL) { // Vérifiez si un nom de fichier est fourni
            FILE *file = fopen(args[1], "a"); // Ouvrir le fichier en mode ajout
            
            if (file != NULL) { // Si l'ouverture réussit 
                fclose(file); // Fermer le fichier immédiatement pour le créer 
                printf("Fichier '%s' créé.\n", args[1]); 
            } else { 
                perror("touch"); 
            } 
        } else { 
            printf("Usage: touch <nom_du_fichier>\n"); 
        } 
	} else if (strcmp(args[0], "matrix") == 0) { // Implémentation de l'animation Matrix
		int running = 1;

		// Créer un thread pour gérer l'animation.
		_beginthread((void(*)(void*))matrix_animation, 0, &running);

		while (running) {
			char input[MAX_INPUT_SIZE];
			if (_kbhit()) { // Vérifier si une touche a été pressée.
				fgets(input, sizeof(input), stdin); // Lire l'entrée.
				if (strncmp(input, "stop", 4) == 0) { // Si l'utilisateur tape "stop".
					running = 0; // Arrêter l'animation.
				}
			}
			Sleep(100); // Petite pause pour éviter d'utiliser trop de CPU.
		}
		
		printf("\nAnimation arrêtée.\n");
		
	} else if (strcmp(args[0], "history") == 0) { // Afficher l'historique des commandes
		display_history(); 
	} else if (strcmp(args[0], "vi") == 0 || strcmp(args[0], "emacs") == 0) { // Intégration d'éditeurs vi et emacs
		if (args[1] != NULL) { // Vérifiez si un nom de fichier est fourni
			char command[MAX_INPUT_SIZE];
			snprintf(command, sizeof(command), "%s %s", args[0], args[1]); // Construire la commande complète.
			system(command); // Exécuter l'éditeur avec le fichier.
		} else {
			printf("Usage: %s <nom_du_fichier>\n", args[0]); // Indiquer comment utiliser la commande.
		}
	} else if (strcmp(args[0], "history") == 0) { // Afficher l'historique des commandes
		display_history(); 
	} else if (strcmp(args[0], "alias") == 0) { // Gérer les alias
		if (args[1] == NULL) { 
			list_aliases(); 
		} else { 
			char *eq = strchr(args[1], '='); 
			
			if (eq) { 
				*eq = '\0'; 
				add_alias(args[1], eq + 1); 
			} else { 
				printf("Usage: alias name='command'\n"); 
			} 
		} 
	} else if (strcmp(args[0], "help") == 0) { // Afficher l'aide sur les commandes disponibles
		printf("Commandes disponibles:\n"); 
		printf("  cd [dir]     - Changer de répertoire\n"); 
		printf("  ls           - Lister les fichiers\n"); 
		printf("  pwd          - Afficher le répertoire courant\n"); 
		printf("  echo [text]  - Afficher du texte\n"); 
		printf("  touch [file] - Créer un fichier\n"); 
	    printf("  vi [file]    - Ouvrir un fichier avec vi\n");
	    printf("  emacs [file] - Ouvrir un fichier avec emacs\n");
	    printf("  matrix       - Démarrer l'animation Matrix\n");
	    printf("  history      - Afficher l'historique des commandes\n"); 
	    printf("  alias [name='command'] - Gérer les alias\n");
	    printf("  help         - Afficher cette aide\n");
	    printf("  exit         - Quitter le shell\n");
	} else { // Pour d'autres commandes, utiliser system()
	    char command[MAX_INPUT_SIZE] = "";
		
	    // Concaténer les arguments pour former la commande complète.
	    for (int i = 0; args[i] != NULL; i++) {
	        strcat(command, args[i]);
	        strcat(command, " ");
	    }
		
	    system(command); // Exécuter la commande externe.
	}
}

void matrix_animation(int* running_flag) {
	srand(time(NULL)); // Initialiser le générateur de nombres aléatoires.

	while (*running_flag) {
	    int width;
	    CONSOLE_SCREEN_BUFFER_INFO csbi;
	    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	    width = csbi.srWindow.Right - csbi.srWindow.Left +1;

	    int random_char_count = width; // Remplir toute la largeur

	    for(int j=0; j<random_char_count; j++) {
	        int random_char_index = rand() % ('Z' - 'A' + 'Z' - 'A') + 'A';  
	        set_console_color(COLOR_GREEN);  
	        printf("%c", random_char_index);  
	    }

	    Sleep(10);   // Diminuer cette valeur rendra l'animation plus rapide.
	    
	    system("cls");   // Effacer l'écran après chaque itération.

	  }
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
	static char cwd[MAX_PATH]; 

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

	char input[MAX_INPUT_SIZE];     // Déclaration de la variable input ici.
	char **tokens;                  // Déclaration de la variable tokens ici.
	int i;

	system("cls");

	const char* ascii_art =
"   __   __       _______ _____   _______   __   _____ _    _ ______ _      _      \n"
" | \\ \\ / /   /\\|__   __| __ \\ |__   __| /\\ \\ / ____| | | | | ____| |    | |     \n"
" | \\ V /   /  \\ | | | | |__) | | |     /\\ \\| |___ | |__| | |__| | |__ | |____| |\n"
" | > <   / /\\ \\| | | | _ \\   | |     > < \\___ \\| __| | __| | __| |_|      \n"
" | . \\ / ____ \\| |_| || \\ \\_| |_||_| / . \\ ____) || |_| || |_| |_|_____|_____\n"
" |_| |_/_/\\_/\\_\\_| |_|\\_\\_____/_/ \\_\\_____/ |_||_|______|______|______|\n";

	int padding;
	
	padding = ((80 - strlen(ascii_art)) /2 );
	set_console_color(COLOR_CYAN);

	printf("%*s%s\n", padding,"", ascii_art);

	const char* welcome_msg = "Bienvenue sur le Shell interactif de Valak";
	padding = ((80 - strlen(welcome_msg)) /2 );
	
	for(int j=3;j>0;j--){
	  Sleep(500);
	  system("cls");
	  printf("%*s%s\n", padding,"", welcome_msg);
	  Sleep(500);
	  system("cls");
   }

	const char* start_msg = "Appuyez sur Entrée pour commencer...";
	padding = ((80 - strlen(start_msg)) /2 );
	
	for(int j=3;j>0;j--){
	  Sleep(500);
	  system("cls");
	  printf("%*s%s\n", padding,"", start_msg);
	  Sleep(500);
	  system("cls");
   }

	getchar(); 

	system("cls");

	printf("Shell Interactif de Valak\n");
	printf("Tapez 'help' pour voir les commandes disponibles.\n");
	printf("Tapez 'exit' pour quitter.\n\n");

	while (1) {  
	   prompt(); 
		
	   int pos = 0; 
		
	   input[0] = '\0'; 
		
	   while (1) {  
		   char c = _getch();  
			
		   if (c == '\r') {  
			   printf("\n");  
			   break;  
		   } else if (c == '\b') {  
			   if (pos > 0) {  
				   input[--pos] = '\0';  
				   printf("\b \b");  
			   }  
		   } else if (c == -32 || c == '\e') {  
			   c = _getch();  
				
			   if (c == 'H') {  
				   if (history_index > 0) {  
					   strcpy(input, history[--history_index]);  
					   pos = strlen(input);  
					   printf("\r");  
					   prompt();  
					   printf("%s", input);  
				   }  
			   } else if (c == 'P') {  
				   if (history_index < history_count - 1) {  
					   strcpy(input, history[++history_index]);  
					   pos = strlen(input);  
					   printf("\r");  
					   prompt();  
					   printf("%s", input);  
				   } else if (history_index == history_count - 1) {  
					   input[0] = '\0';   
					   pos = 0;  
					   printf("\r");   
					   prompt();   
				   }  
			   }
		   } else {   
			   input[pos++] = c;   
			   input[pos] = '\0';   
			   printf("%c", c);   
		   }
	   }

	   if(strlen(input)==0)
	       continue;

	   add_to_history(input);

	   tokens=tokenize(input);

	   if(tokens[0]==NULL){  
	       free(tokens);  
	       continue;  
	   }

	   if(strcmp(tokens[0],"exit")==0){  
	       set_console_color(COLOR_YELLOW);  
	       printf("Au revoir !\n");  
	       set_console_color(COLOR_RESET);  
	       break;  
	   }

	   if(strcmp(tokens[0],"export")==0){  

	       char *eq=strchr(tokens[1],'=');  

	       if(eq){  

	           *eq='\0';  

	           set_env_var(tokens[1],eq+1);  

	           set_console_color(COLOR_GREEN);  

	           printf("Variable d'environnement définie : %s=%s\n",tokens[1],eq+1);  

	           set_console_color(COLOR_RESET);  

	       }  

	   }else{  

	       execute_command(tokens);  

	   }

	   for(i=0;tokens[i]!=NULL;i++){  

	       free(tokens[i]);  

	   }

	   free(tokens);   
   }

   for(i=0;i<env_var_count;i++){
       free(env_vars[i].name);
       free(env_vars[i].value);
   }

   for(i=0;i<alias_count;i++){
       free(aliases[i].name);
       free(aliases[i].command);
   }

   return 0;  
}
