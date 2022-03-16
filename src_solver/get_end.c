/*
** EPITECH PROJECT, 2022
** a_star
** File description:
** get_end
*/

#include "solver.h"

void get_endpos(t_par *par)
{
    par->end_y = par->arr_len;
    par->end_x = par->str_len;
}
