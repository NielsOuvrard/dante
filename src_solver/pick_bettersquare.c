/*
** EPITECH PROJECT, 2022
** a_star
** File description:
** pick_bettersquare
*/

#include "solver.h"

void pick_square (t_par *par)
{
    int x = 0;
    int y = 0;
    int fcost = 21474836;
    int i = 0;
    int position = 0;
    t_open *tmp = par->open;
    t_open *final = tmp;
    while (i != par->list_len) {
        if (par->nodes[tmp->y][tmp->x].f_cost <= fcost) {
            x = tmp->x;
            y = tmp->y;
            position = i;
            final = tmp;
            fcost = par->nodes[tmp->y][tmp->x].f_cost;
        }
        i++;
        tmp = tmp->next;
    }
    par->current_x = x;
    par->current_y = y;
    par->nodes[par->current_y][par->current_x].visited = 1;
    remove_open(par, final->prev, final, position);
    return;
}
