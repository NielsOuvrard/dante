/*
** EPITECH PROJECT, 2022
** a_star
** File description:
** malloc_list
*/

#include "solver.h"

void malloc_list(t_par *par)
{
    int j = 0;
    par->nodes = malloc(sizeof(t_node *) * (par->arr_len + 1));
    int arr_len = par->arr_len;
    while (j != arr_len) {
        par->nodes[j] = malloc(sizeof(t_node) * (par->str_len + 1));
        par->nodes[j]->parent = NULL;
        j++;
    }
    j = 0;
    int i = 0;
    par->nodes[0][0].visited = 0;
}

void free_nodes(t_par *par)
{
    int j = 0;
    int arr_len = par->arr_len;
    while (j != arr_len) {
        free(par->nodes[j]);
        j++;
    }
    free(par->nodes);
}
