/*
** EPITECH PROJECT, 2022
** a_star
** File description:
** check_square
*/

#include "my.h"

void check_right(int x, int y, t_par *par)
{
    if (is_accessible(par, x + 1, y) == 1 && is_inopen(par, x + 1, y) == 0) {
        discover_node(par, x + 1, y, &par->nodes[y][x]);
    } else
    if (is_accessible(par, x + 1, y))
        check_cost(par, &par->nodes[y][x], x + 1, y);
}

void check_left(int x, int y, t_par *par)
{
    if (is_accessible(par, x - 1, y) && is_inopen(par, x - 1, y) == 0) {
        discover_node(par, x + 1, y, &par->nodes[y][x]);
    } else
    if (is_accessible(par, x - 1, y))
        check_cost(par, &par->nodes[y][x], x - 1, y);
}

void check_up(int x, int y, t_par *par)
{
    if (y - 1 < 0)
        return;
    if (is_accessible(par, x, y - 1) && is_inopen(par, x, y - 1) == 0) {
        discover_node(par, x, y - 1, &par->nodes[y][x]);
    } else
    if (is_accessible(par, x, y - 1))
        check_cost(par, &par->nodes[y][x], x, y - 1);
}

void check_down(int x, int y, t_par *par)
{
    /*if (y + 1 < 0 || !par->arr[y + 1] || par->arr[y + 1][x] == '\0')
        return;*/
    if (is_accessible(par, x, y + 1) && is_inopen(par, x, y + 1) == 0) {
        discover_node(par, x, y + 1, &par->nodes[y][x]);
    } else
    if (is_accessible(par, x, y + 1))
        check_cost(par, &par->nodes[y][x], x, y + 1);
}