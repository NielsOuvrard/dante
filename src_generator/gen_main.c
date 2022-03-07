/*
** EPITECH PROJECT, 2022
** gen_main.c
** File description:
** gen_main
*/

#include "my.h"
#include "gen_sol_header.h"

int gestion_erreur (int ac, char **av)                                          // others arguments ?
{
    if (ac < 2 || ac > 4)
        return 1;
    if (!my_isnbr(av[1]) || !my_isnbr(av[2]))
        return 2;
    if (ac == 4 && my_strvcmp(av[2], "perfect"))
        return 3;
    return 0;
}

// X = wall
// * = free spaces

char **fully_maze (int lignes, int cols)
{
    char **maze = malloc(sizeof(char *) * (lignes + 1));
    maze[lignes + 1] = NULL;
    for (int i = 0; i < lignes; i++) {
        maze[i] = malloc(sizeof(char) * (cols + 1));
        my_memset(maze[i], cols, 'X');
        maze[i][cols + 1] = '\0';
    }
    return maze;
}

void create_maze (char **av)
{
    int perfect = 0, lignes, cols;
    if (my_arraylen(av) > 2)
        perfect = 1;
    lignes = my_getnbr(av[1]);
    cols = my_getnbr(av[2]);
    char **maze = fully_maze(lignes, cols);
    my_show_word_array(maze);
    free_my_arr(maze);
}

int main (int ac, char **av)
{
    if (gestion_erreur(ac, av))
        return 84;
    create_maze(av);
    // my_putstr("no solution found\n");        // solver
    return 0;
}
