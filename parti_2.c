#include "parti_2.h"
#include<math.h>
t_sk_list* create_list_number(int val) // création d'une liste a partir du nombre de niveau de la list
{

    t_sk_list* list = create_list(val);
    t_sk_cell* new_cell;
    int niveau = pow(2,val);
    int T[niveau];
    for(int i =0; i< niveau ; i++) // création du tableau pour connaitre les niveaux
    {
        T[i]=0;
    }

    for(int j = 1 ; j< val ; j++) // remplissage du tableau en fonction du niveau attendu dans la list
    {
        int j_carrer = pow(2,j);
        for(int i =1; i< niveau/j_carrer ; i++)
        {
            T[i*j_carrer-1]++;
        }
    }

    for(int i=0 ;i < niveau-1 ; i++)// création de la liste graçe au tableau précédent
    {
        new_cell = create_cell(i+1,T[i]+1);
        add_cell_in_list(list,new_cell);
    }
    return list;
}

int research_n_head_0(t_sk_list list, int val) // recherche à partir du niveau = 0
{
    t_sk_cell* temp = list.tab_niv_head[0];

    while(temp->value != val && temp != NULL) // parcours de la list jusqu'à trouver la valeur
    {
        temp = temp->tab_niv_next[0];
    }
    if(temp->value == val)
    {
        return 1;
    } else
        return 0;
}

int research_n(t_sk_list list, int val) { // recherche avancée
    int niveau = list.max_level-1;
    t_sk_cell* temp;
    t_sk_cell* prev = NULL;

    temp = list.tab_niv_head[niveau];

    while (niveau >= 0) { // faire la recherche sur tout les niveaux si il le faut
        while (temp != NULL && temp->value < val) { // recherche d'une valeur supérieur
            prev = temp; // cellule qui sera la dernière valeur < à val
            temp = temp->tab_niv_next[niveau];
        }

        if (temp != NULL && temp->value == val) { // vérification si on à trouvés la valeur
            return 1;
        }

        niveau--; // décrementation de niveau
        if (niveau >= 0) {
            if (prev != NULL)
            {
                temp = prev->tab_niv_next[niveau]; // on descend d'un niveau pour continuer la recherche après
            }
            else
            {
                temp = list.tab_niv_head[niveau]; // on descend d'un niveau et on prend la recherhce depuis le début du niveau
            }
        }
    }
    return 0;
}
