/*
** EPITECH PROJECT, 2022
** sol_main.c
** File description:
** sol_main.c
*/

#include "my.h"
#include "gen_sol_header.h"

int gestion_erreure (int ac, char **av)
{
    return 1;
}

int solve_the_maze (char **av)
{
    char **maze = filepath_to_arr(av[1]);
    list_solve *solve = malloc(sizeof(list_solve));
    if (maze[0][0] != '*') {
        my_putstr("no solution found\n");
        return 0;
    }
    solve->x = 0;
    solve->y = 0;
    solve->dir = 'n';
    solve->next = NULL;
    solve->prev = NULL;
    recursive_solver(maze, solve);
    my_show_word_array(maze);
    free_my_arr(maze);
    return 0;
}

int main (int ac, char **av)
{
    if (!gestion_erreure(ac, av))
        return 84;
    return solve_the_maze(av);
}

    // if (direction == 's') {
    //     if (solve->y + 1 < max_lignes && maze[solve->y + 1][solve->x] == '*')
    //         return 1;
    //     if (solve->x > 0 && maze[solve->y + 1][solve->x - 1] == '*')
    //         return 4;
    //     if (solve->x + 1 < max_cols && maze[solve->y][solve->x + 1] == '*')
    //         return 3;
    // } else if (direction == 'n') {
    //     if (solve->y > 0 && maze[solve->y - 1][solve->x] == '*')
    //         return 2;
    //     if (solve->x > 0 && maze[solve->y + 1][solve->x - 1] == '*')
    //         return 4;
    //     if (solve->x + 1 < max_cols && maze[solve->y][solve->x + 1] == '*')
    //         return 3;
    // }
    // if (direction == 'w') {
    //     if (solve->y + 1 < max_lignes && maze[solve->y + 1][solve->x] == '*')
    //         return 1;
    //     if (solve->y > 0 && maze[solve->y - 1][solve->x] == '*')
    //         return 2;
    //     if (solve->x + 1 < max_cols && maze[solve->y][solve->x + 1] == '*')
    //         return 3;
    // } else if (direction == 'e') {
    //     if (solve->y + 1 < max_lignes && maze[solve->y + 1][solve->x] == '*')
    //         return 1;
    //     if (solve->y > 0 && maze[solve->y - 1][solve->x] == '*')
    //         return 2;
    //     if (solve->x > 0 && maze[solve->y + 1][solve->x - 1] == '*')
    //         return 4;
    // }