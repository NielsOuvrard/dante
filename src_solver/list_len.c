/*
** EPITECH PROJECT, 2022
** src_solver
** File description:
** list_len
*/

#include "solver.h"

int list_len (t_par *par)
{
    int i = 0;
    t_open *tmp = par->open;
    while (tmp) {
        i++;
        tmp = tmp->next;
    }
    return i;
}
