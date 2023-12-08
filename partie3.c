#include "partie3.h"


char *scanstring(void)
{
    char * p_char;
    scanf("%s",p_char);
    return p_char;
}

name_sk_list* calendar(void)
{
    name_sk_list* a = malloc(sizeof (name_sk_list));
    a->max_level = 4;
    a->tab_niv_head = NULL;
    FILE * fichier=NULL;
    char* chaine[100000000];

    printf("%s",chaine);
    fichier = fopen("noms2008nat_txt.txt","r");
    while(fgets(chaine,100000000,fichier)!=NULL)
    printf("%s \n",chaine);

    fclose(fichier);

    return a;
}

char* format_nom(const char* nom_complet) {
    // Estimation de la longueur nécessaire pour la nouvelle chaîne
    // +2 pour le caractère de soulignement et le caractère nul de fin de chaîne
    int longueur = strlen(nom_complet) + 2;
    char* nom_format = (char*)malloc(longueur * sizeof(char));

    if (!nom_format) {
        perror("Allocation mémoire échouée");
        exit(EXIT_FAILURE);
    }

    // Pointeurs pour parcourir le prénom et le nom
    const char *ptr_prenom, *ptr_nom;
    ptr_nom = strtok((char*)nom_complet, " "); // On commence par le prénom
    ptr_prenom = strtok(NULL, " ");            // Ensuite on récupère le nom

    // Copie et conversion du prénom en minuscules
    int i = 0;
    while (ptr_nom[i]) {
        nom_format[i] = tolower((unsigned char)ptr_nom[i]);
        i++;
    }

    nom_format[i++] = '_'; // Ajout du caractère de soulignement

    // Copie et conversion du nom en minuscules
    int j = 0;
    while (ptr_prenom[j]) {
        nom_format[i + j] = tolower((unsigned char)ptr_prenom[j]);
        j++;
    }
    nom_format[i + j] = '\0'; // Ajout du caractère nul de fin de chaîne

    return nom_format;
}

// Fonction pour créer un nouveau contact
name_sk_cell* create_name_sk_cell(const char* name, int level) {
    name_sk_cell* cell = malloc(sizeof(name_sk_cell));
    if (cell == NULL) {
        perror("Allocation mémoire échouée pour name_sk_cell");
        exit(EXIT_FAILURE);
    }
    cell->name = strdup(name);
    cell->level = level;
    cell->rdv = NULL; // Supposons qu'il n'y a pas de rdv pour le moment
    cell->tab_niv_next = malloc((level + 1) * sizeof(name_sk_cell*));
    if (cell->tab_niv_next == NULL) {
        perror("Allocation mémoire échouée pour tab_niv_next");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i <= level; i++) {
        cell->tab_niv_next[i] = NULL;
    }
    return cell;
}

// Fonction pour insérer un contact dans la liste à niveaux
void insert_name_sk_cell(name_sk_list* list, name_sk_cell* cell) {
    name_sk_cell* update[list->max_level + 1];
    memset(update, 0, sizeof(name_sk_cell*) * (list->max_level + 1));

    for (int i = list->max_level; i >= 0; i--) {
        name_sk_cell* current = list->tab_niv_head[i];
        while (current != NULL && strcmp(current->name, cell->name) < 0) {
            update[i] = current;
            current = current->tab_niv_next[i];
        }
    }

    for (int i = 0; i <= cell->level; i++) {
        cell->tab_niv_next[i] = update[i] ? update[i]->tab_niv_next[i] : list->tab_niv_head[i];
        if (update[i]) {
            update[i]->tab_niv_next[i] = cell;
        } else {
            list->tab_niv_head[i] = cell;
        }
    }
}

// Fonction pour initialiser la liste à niveaux
name_sk_list* create_name_sk_list(int max_level) {
    name_sk_list* list = malloc(sizeof(name_sk_list));
    if (list == NULL) {
        perror("Allocation mémoire échouée pour name_sk_list");
        exit(EXIT_FAILURE);
    }
    list->max_level = max_level;
    list->tab_niv_head = calloc(max_level + 1, sizeof(name_sk_cell*));
    if (list->tab_niv_head == NULL) {
        perror("Allocation mémoire échouée pour tab_niv_head");
        exit(EXIT_FAILURE);
    }
    return list;
}

