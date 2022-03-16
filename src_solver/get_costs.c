/*
** EPITECH PROJECT, 2022
** a_star
** File description:
** get_hcost
*/

#include "solver.h"

void get_hcost(t_par *par, int x, int y)
{
    par->nodes[y][x].h_cost = ((par->end_y - y) + (par->end_x - x)) * 10;
}

void get_gcost(t_par *par, int x, int y)
{
    par->nodes[y][x].g_cost = par->nodes[y][x].parent->g_cost + 10;
}

void get_fcosts(t_par *par, int x, int y)
{
    par->nodes[y][x].f_cost = par->nodes[y][x].g_cost +
    par->nodes[y][x].h_cost;
}
