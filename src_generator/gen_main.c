/*
** EPITECH PROJECT, 2022
** gen_main.c
** File description:
** gen_main
*/

#include "my.h"
#include "gen_sol_header.h"

// X = wall
// * = free spaces

char **fully_maze (int lignes, int cols)
{
    char **maze = malloc(sizeof(char *) * (lignes + 1));
    maze[lignes] = NULL;
    for (int i = 0; i < lignes; i++) {
        maze[i] = malloc(sizeof(char) * (cols + 1));
        my_memset(maze[i], cols, 'X');
        maze[i][cols] = '\0';
    }
    return maze;
}

// recursive backtracker

void dig_the_wall (char **maze)
{
    char space = '*';
    maze[0][0] = space;
    if (random_int(0, 1)) {
        maze[0][1] = space;
    } else {
        maze[1][0] = space;
    }
}

void create_maze (char **av)
{
    int perfect = 0, lignes, cols;
    if (my_arraylen(av) > 3)
        perfect = 1;
    lignes = my_getnbr(av[1]);
    cols = my_getnbr(av[2]);
    char **maze = fully_maze(lignes, cols);

    dig_the_wall(maze);

    my_show_word_array(maze);
    free_my_arr(maze);
}

int main (int ac, char **av)
{
    srand(time(NULL));
    if (gestion_erreur(ac, av))
        return 84;
    create_maze(av);
    // my_putstr("no solution found\n");        // solver
    return 0;
}
