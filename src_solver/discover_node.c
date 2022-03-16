/*
** EPITECH PROJECT, 2022
** a_star
** File description:
** discover_node
*/

#include "my.h"

void discover_node(t_par *par, int x, int y, t_node *parent)
{
    par->nodes[y][x].parent = parent;
    get_hcost(par, x, y);
    get_gcost(par, x, y);
    get_fcosts(par, x, y);
    par->arr[par->current_y][par->current_x] = 'O';
    add_toopen(par->open, x, y);
}

int is_inopen(t_par *par, int x, int y)
{
    t_open **temp = &par->open;
    t_open *tmp = *temp;
    while (tmp != NULL) {
        if (tmp->x == x && tmp->y == y) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

void update_node(t_par *par, t_node *parent, int x, int y)
{
    par->nodes[y][x].parent = parent;
    get_hcost(par, x, y);
    get_gcost(par, x, y);
    get_fcosts(par, x, y);
}

void check_cost(t_par *par, t_node *parent, int x, int y)
{
    int tmp = parent->g_cost + 10;
    if (tmp > par->nodes[y][x].g_cost) {
        update_node(par, parent, x, y);
    }
}