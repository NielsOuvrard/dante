/*
** EPITECH PROJECT, 2022
** a_star
** File description:
** add_toopen
*/

#include "my.h"

void add_toopen (t_open **open, int x, int y)
{
    t_open *new_node = malloc(sizeof(t_open));
    new_node->x = x;
    new_node->y = y;
    // printf("y %d, x %d \n", x, y);
    new_node->next = NULL;
    if (!(*open)) {
        *open = new_node;
    } else {
        t_open *tmp = *open;
          while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
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

void remove_open (t_par *par, int x, int y)
{
    int position = get_pos(par, x, y);
    if (position < 0) {
        return;
    }
    t_open **open_list = &par->open;
    t_open *node = *open_list;
    t_open *tmp = node->next;
    if (position == 0) {
        (*open_list) = (*open_list) ->next;
        return;
    }
    for (int i = 0; i < position - 1; i++) {
        node = node->next;
        tmp = tmp->next;
    }
    node->next = tmp->next;
    free(tmp);
}
