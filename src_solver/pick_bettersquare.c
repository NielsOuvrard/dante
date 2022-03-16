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
    remove_open(par, par->current_x, par->current_y);
    par->nodes[par->current_y][par->current_x].visited = 1;
    t_open **temp = &par->open;
    t_open *tmp = *temp;
    while (tmp != NULL) {
        if (par->nodes[tmp->y][tmp->x].f_cost < fcost) {
            x = tmp->x;
            y = tmp->y;
        }
        tmp = tmp->next;
    }
    par->current_x = x;
    par->current_y = y;
    par->nodes[par->current_y][par->current_x].visited = 1;
    remove_open(par, x, y);
    return;
}
