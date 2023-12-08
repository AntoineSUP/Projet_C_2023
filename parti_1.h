
#ifndef CALENDAR_PARTI_1_H
#define CALENDAR_PARTI_1_H
#include <stdlib.h>
#include <stdio.h>

typedef struct s_sk_cell
{
    int value;
    int level;
    struct s_sk_cell **tab_niv_next;
} t_sk_cell;


typedef struct s_sk_list
{
    int max_level;
    t_sk_cell **tab_niv_head;
} t_sk_list;



t_sk_cell* create_cell(int val,int niv);
t_sk_list* create_list(int max_level);

void add_cell_head_in_list(t_sk_list * list, t_sk_cell* cell);
void display_level_list(t_sk_list list ,int level);
void display_list(t_sk_list list);
void add_cell_in_list(t_sk_list * list, t_sk_cell* cell);


#endif //CALENDAR_PARTI_1_H
