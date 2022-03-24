/*
** EPITECH PROJECT, 2022
** a_star
** File description:
** add_toopen
*/

#include "solver.h"

void add_toopen (t_open **open, int x, int y, t_par *par)
{
    par->list_len += 1;
    t_open *new_node = malloc(sizeof(t_open));
    new_node->x = x;
    new_node->y = y;
    new_node->next = NULL;
    par->nodes[y][x].opened = 1;
    if (!(*open)) {
        new_node->prev = NULL;
        *open = new_node;
    } else {
        t_open *tmp = *open;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
        new_node->prev = tmp;
    }
}

int get_pos (t_par *par, int x, int y)
{
    int i = 0;
    t_open *tmp = par->open;
    while (tmp) {
        if (tmp->x == x && tmp->y == y)
            return i;
        i++;
        tmp = tmp->next;
    }
    return -1;
}

void remove_open (t_par *par, t_open *prev, t_open *old, int position)
{
    t_open **open_list = &par->open;
    par->list_len -= 1;
    if (*open_list == NULL || old == NULL)
        return;
    if (*open_list == old)
        *open_list = old->next;
    if (old->next != NULL)
        old->next->prev = old->prev;
    if (old->prev != NULL)
        old->prev->next = old->next;
    free(old);
}
