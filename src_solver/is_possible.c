/*
** EPITECH PROJECT, 2022
** src_solver
** File description:
** is_possible
*/

#include "solver.h"

void is_possible(t_par *par)
{
    if (par->arr[par->arr_len - 1][par->str_len - 1] != '*')
        par->is_possible = 0;
    else
        par->is_possible = 1;
}
