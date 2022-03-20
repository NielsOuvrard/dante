/*
** EPITECH PROJECT, 2022
** src_solver
** File description:
** initialize_node
*/

#include "solver.h"

void initialize_nodes(t_par *par)
{
    int y = 0;
    int x = 0;
    while (y != par->end_y) {
        while (x != par->end_x) {
            par->nodes[y][x].parent = NULL;
            par->nodes[y][x].visited = 0;
            par->nodes[y][x].opened = 0;
            x++;
        }
        x = 0;
        y++;
    }
}
