/*
** EPITECH PROJECT, 2022
** sol_ok_to_navigate.c
** File description:
** sol_ok_to_navigate
*/

#include "my.h"
#include "gen_sol_header.h"

int ok_to_north (char **maze, list_solve *solve)
{
    if (solve->y > 0 && maze[solve->y - 1][solve->x] == '*')
        return 1;
    return 0;
}

int ok_to_south (char **maze, list_solve *solve)
{
    int max_lignes = my_arraylen(maze);
    if (solve->y + 1 < max_lignes && maze[solve->y][solve->x + 1] == '*')
        return 1;
    return 0;
}

int ok_to_east (char **maze, list_solve *solve)
{
    int max_cols = my_strlen(maze[0]);
    if (solve->x + 1 < max_cols && maze[solve->y][solve->x + 1] == '*')
        return 1;
    return 0;
}

int ok_to_west (char **maze, list_solve *solve)
{
    if (solve->x > 0 && maze[solve->y][solve->x - 1] == '*')
        return 1;
    return 0;
}
