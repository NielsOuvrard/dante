/*
** EPITECH PROJECT, 2022
** sol_turn_to.c
** File description:
** sol_turn_to
*/

#include "my.h"
#include "gen_sol_header.h"


int turn_to_north (char **maze, list_solve *solve)
{
    my_put_end_solve(solve, solve->x, solve->y - 1, 'n');
    return recursive_solver(maze, solve->next);
}

int turn_to_south (char **maze, list_solve *solve)
{
    my_put_end_solve(solve, solve->x, solve->y + 1, 's');
    return recursive_solver(maze, solve->next);
}

int turn_to_east (char **maze, list_solve *solve)
{
    my_put_end_solve(solve, solve->x + 1, solve->y, 'e');
    return recursive_solver(maze, solve->next);
}

int turn_to_west (char **maze, list_solve *solve)
{
    my_put_end_solve(solve, solve->x - 1, solve->y, 'w');
    return recursive_solver(maze, solve->next);
}
