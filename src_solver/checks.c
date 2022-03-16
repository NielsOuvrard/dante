/*
** EPITECH PROJECT, 2022
** a_star
** File description:
** checks
*/

#include "solver.h"

int is_accessible(t_par *par, int x, int y)
{
    if (x < 0 || y < 0)
        return 0;
    if (!par->arr[y] || !par->arr[y][x])
        return 0;
    if (par->arr[y][x] == '*')
        return 1;
    else
        return 0;
}

void check_allsquares (t_par *par, int x, int y)
{
    check_up(x, y, par);
    check_down(x, y, par);
    check_left(x, y, par);
    check_right(x, y, par);
}
