#include <stdio.h>
#include "parti_2.h"
#include "timer.h"
#include<math.h>


int main() {

    t_sk_cell* p0,*p1,*p2,*p3,*p4; // création des pointeur de cellule
    p0 = create_cell(73,3); // création de la premiere cellule
    p1 = create_cell(123,6);// création de la seconde cellule
    p2 = create_cell(63,4);// création de la troisième cellule
    p3 = create_cell(84,7);// création de la quatrième cellule
    p4 = create_cell(11,2);// création de la cinquième cellule
    t_sk_list* list ;
    list = create_list(7); // création de la liste
    display_list(*list); // affichage de la list
    printf("\n");

    add_cell_in_list(list , p0);
    add_cell_in_list(list , p1); // ajout des cellules dans la list de façon à avoir une liste trier
    add_cell_in_list(list , p2);

    display_list(*list);
    add_cell_head_in_list(list,p4); // ajout en tête de liste
    printf("\n");
    add_cell_in_list(list,p3);
    display_list(*list);
    printf("\n");
    display_level_list(*list,3); // affichage de la liste pour le troisième niveau
    printf("\n");

    t_sk_list * list2 =create_list_number(7); // création de la liste de nombre avec 7 niveaux
    int n=0, x =0;
    display_list(*list2);
    printf("\n");
    n = research_n_head_0(*list2,11); // si n = 1 la valeur à été trouver sinon n=0
    x = research_n(*list2,11);
    printf("La recherche en 0 : %d & la recherche avancée : %d\n",n,x); // affichage du resultat des 2 recherche

    t_sk_list* list_de_nombre = NULL ;
    int niveau = 7; // démonstration de la différence de complexité entre les 2 méthodes de recherche
    startTimer();
    for(int i =niveau ; i< 15 ; i++) {
        list_de_nombre = create_list_number(i);
        startTimer();
        int puissance_i = pow(2,i)-1;
        for (int j = 0; j < 100000; j++) { // on fait 100 000 fois 1 recherche avec un nombre different dans la list
            int val = rand() %puissance_i + 1; // le nombre rechercher est choisit au hasard
            research_n_head_0(*list_de_nombre, val); // recherche classique
        }
        stopTimer();
        displayTime();
        startTimer();
        for (int j = 0; j < 100000; j++) {// on fait 100 000 fois 1 recherche avec un nombre different dans la list
            int val = rand() %puissance_i + 1;// le nombre rechercher est choisit au hasard
            research_n(*list_de_nombre, val);// recherche avancé
        }
        stopTimer();
        displayTime();
        printf("n = %d\n",i);
    }
    return 0;
}
