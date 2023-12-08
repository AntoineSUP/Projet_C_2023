#include "parti_1.h"


t_sk_cell* create_cell(int val,int niv) //Créer une cellule : on donne sa valeur et le nombre de niveaux que possède cette cellule, pour obtenir un pointeur vers cette cellule
{
    t_sk_cell* new_cell = malloc(sizeof(t_sk_cell) );
    new_cell->value = val;
    new_cell->level = niv;
    new_cell->tab_niv_next = (t_sk_cell**)malloc(niv*sizeof(t_sk_cell*));
    for(int i =0 ; i<niv ; i++) // tout les nexts de chaque niveaux sont NULL
    {
        new_cell->tab_niv_next[i] = NULL;
    }
    return new_cell;
}

t_sk_list* create_list(int max_level) // création de list
{
    t_sk_list* list = malloc(sizeof(t_sk_list) );
    if (list == NULL) // vérification de malloc
    {
        return NULL;
    }
    list->max_level = max_level;
    list->tab_niv_head = (t_sk_cell **)malloc(max_level * sizeof(t_sk_cell*));
    if (list->tab_niv_head== NULL)
    {   // Gestion d'erreur : échec de l'allocation mémoire
        free(list);// Libérer la mémoire déjà allouée
        return NULL;
    }
    // Initialisation des pointeurs à NULL
    for (int i = 0; i < max_level; i++) {
        list->tab_niv_head[i] = NULL;
    }
    return list;
}

void add_cell_head_in_list(t_sk_list * list, t_sk_cell* cell) // ajout d'une cellule en tête de list
{
    if(cell->level > list->max_level) // vérification de la hauteur de la cellule
    {
        printf("niveaux de cell trop haut ");
        return;
    }
    if(list->tab_niv_head[0] == NULL) // cas pour list vide
    {
        for (int i = 0; i < cell->level; i++) {
            list->tab_niv_head[i] = cell;
        }
    }
    else // cas pour list non vide
    {
        for(int i = 0 ; i< cell->level ; i++)
        {
            cell->tab_niv_next[i] = list->tab_niv_head[i];
            list->tab_niv_head[i] = cell;
        }
    }
}

void display_level_list(t_sk_list list ,int level) // affichage de la list pour un nivrau précis
{
    t_sk_cell* temp = list.tab_niv_head[level-1];
    printf("list head_%d @-]-->",level-1);
    while (temp != NULL) {
        printf("[ %d |@- ]-->", temp->value);
        temp = temp->tab_niv_next[level - 1];
    }
    if(temp == NULL)
    {
        printf("NULL\n");
    }
}

void display_list(t_sk_list list) // affichage de la list
{
    t_sk_cell* temp ;
    for(int i =0 ; i<list.max_level ; i++)  //i incrémenter pour chaque niveau
    {
        temp = list.tab_niv_head[i];
        printf("list head_%d @-]-->",i);
        while (temp != NULL)
        {
            printf("[ %d |@- ]-->", temp->value);
            temp = temp->tab_niv_next[i];
        }
        if(temp == NULL)
        {
            printf("NULL\n");
        }
    }
}

void add_cell_in_list(t_sk_list * list, t_sk_cell* cell) { // ajout de cellule et la liste reste trier

    for (int i = 0; i < cell->level; i++) {
        t_sk_cell *temp = list->tab_niv_head[i];
        t_sk_cell *prev = temp;
        if (list->tab_niv_head[i] == NULL) { // cas d'ajout quand liste head == NULL
            list->tab_niv_head[i] = cell;
        }
        else
        {
            if (temp->value > cell->value) { // cas d'ajout quand cell est inséré en tête de liste
                cell->tab_niv_next[i] = temp;
                list->tab_niv_head[i] = cell;
            }
            else {
                while (temp->value < cell->value && temp->tab_niv_next[i] != NULL) { // parcour la list pour trouver le lieu de l'ajout
                    prev = temp;
                    temp = temp->tab_niv_next[i];
                }
                if (temp->tab_niv_next[i] == NULL && temp->value < cell->value) //Permet d'ajouter une valeur en fin de liste
                {
                    temp->tab_niv_next[i] = cell;

                }
                else //Permet d'ajouter une valeur en millieu de liste
                {
                    cell->tab_niv_next[i] = temp;
                    prev->tab_niv_next[i] = cell;
                }

            }
        }
    }
}