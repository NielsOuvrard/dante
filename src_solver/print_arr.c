/*
** EPITECH PROJECT, 2022
** src_solver
** File description:
** print_arr
*/

#include "solver.h"

void print_arr(t_par *par)
{
    int i = 0;
    while (par->arr[i] != NULL) {
        printf(par->arr[i]);
        if (i < par->end_y - 1) {
            printf("%c", '\n');
        }
        i++;
    }
}
