/*
** EPITECH PROJECT, 2022
** src_solver
** File description:
** edit_map
*/

#include "solver.h"

void write_tomap(t_par *par)
{
    int tmp_y = par->current_y;
    int tmp_x = par->current_x;
    par->arr[tmp_y][tmp_x] = 'o';
    while (par->nodes[tmp_y][tmp_x].parent) {
        int x = par->nodes[tmp_y][tmp_x].parent->x;
        int y = par->nodes[tmp_y][tmp_x].parent->y;
        par->arr[y][x] = 'o';
        tmp_x = x;
        tmp_y = y;
    }
}
