/*
** EPITECH PROJECT, 2022
** src_solver
** File description:
** free
*/

#include "solver.h"

void free_list(t_par *par)
{
    free_arr(par);
    free(par->map);
    free_linked(par);
    free_nodes(par);
    free(par);
    exit(0);
}

void free_arr(t_par *par)
{
    int j = 0;
    for (int i = get_lines_str(par->map); i != 0 ; i--) {
        free(par->arr[j]);
        j++;
    }
    free(par->arr);
}

void free_linked(t_par *par)
{
    t_open **tmp = &par->open;
    t_open *tmp2 = *tmp;
    while (tmp2 != NULL) {
        t_open *next = tmp2->next;
        free(tmp2);
        tmp2 = next;
    }
}
