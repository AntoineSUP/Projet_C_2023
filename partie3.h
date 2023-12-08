#ifndef CALENDAR_PARTIE3_H
#define CALENDAR_PARTIE3_H

#include "parti_2.h"
#include "stdio.h"
#include <string.h>
#include <ctype.h>

typedef struct rdv
{
    int date;
    int heure_rdv;
    int temps_rdv;
    char* objet_rdv;

} rdv_info;

typedef struct n_sk_cell
{
    char* name;
    rdv_info **rdv;
    int level;
    struct n_sk_cell **tab_niv_next;
} name_sk_cell;


typedef struct n_sk_list
{
    int max_level;
    name_sk_cell **tab_niv_head;
} name_sk_list;

char *scanstring(void);
name_sk_list* calendar(void);
char* format_nom(const char* nom_complet);
name_sk_cell* create_name_sk_cell(const char* name, int max_level);
void insert_name(name_sk_list* list, const char* name);
name_sk_list* create_name_sk_list(int max_level);
void insert_name_sk_cell(name_sk_list* list, name_sk_cell* cell);

#endif
