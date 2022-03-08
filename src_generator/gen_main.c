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

void dig_the_wall (char **maze)
{
    maze[0][0] = '*';
    int max_cols = my_strlen(maze[0]), max_lignes = my_arraylen(maze);
    if (my_arraylen(maze) >= 2 && my_strlen(maze[0]) >= 2) {
        maze[0][1] = '*';
        maze[1][1] = '*';
        three_tree *three = NULL;
        three = my_put_in_list(three, 1, 1, 'n');
        my_putchar('a');
        recursive_dig(maze, three, max_lignes, max_cols);
        free_linked_list_tt(three);
    }
    // int max_cols = my_strlen(maze[0]), max_lignes = my_arraylen(maze);
    // maze[max_cols - 2][max_lignes] = '*';                                    // last *
}

int create_maze (char **av)
{
    srand(time(NULL));
    int perfect = 0, lignes, cols;
    if (my_arraylen(av) > 3)
        perfect = 1;
    lignes = my_getnbr(av[1]);
    cols = my_getnbr(av[2]);
    char **maze = fully_maze(lignes, cols);
    dig_the_wall(maze);
    my_show_word_array(maze);
    free_my_arr(maze);
    return 0;
}

int main (int ac, char **av)
{
    if (gestion_erreur(ac, av))
        return 84;
    return create_maze(av);
}

// my_putstr("no solution found\n");        // solver