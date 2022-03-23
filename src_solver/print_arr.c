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
        write(1, par->arr[i], par->str_len);
        if (i < par->end_y - 1) {
            write(1, "\n", 1);
        }
        i++;
    }
}
