/*
** EPITECH PROJECT, 2022
** gen_main.c
** File description:
** gen_main
*/

#include "my.h"
#include "gen_sol_header.h"

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
    sfVector2i infos;
    infos.x = my_strlen(maze[0]);
    infos.y = my_arraylen(maze);
    if (infos.y >= 2 && infos.x >= 2) {
        maze[0][1] = '*';
        maze[1][1] = '*';
        three_tree *three = NULL;
        three = my_put_in_list(three, 1, 1, 'n');
        three_tree *begin = three;
        recursive_dig(maze, three, infos);
        free_linked_list_tt(begin);
    }
    for (int i = 0; maze[infos.y - 2][infos.x - i] != '*'; i++)
        maze[infos.y - 1][infos.x - i - 1] = '*';
    maze[infos.y - 1][infos.x - 1] = '*';
}

void disp_the_maze (char **maze)
{
    for (int i = 0; maze[i] != NULL; i++) {
        my_putstr(maze[i]);
        if (maze[i + 1])
            my_putchar('\n');
    }
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
    if (!perfect) {
        maze[1][1] = '*';
        maze[0][1] = '*';
        maze[1][0] = '*';
    }
    disp_the_maze(maze);
    free_my_arr(maze);
    return 0;
}

int main (int ac, char **av)
{
    if (gestion_erreur(ac, av))
        return 84;
    return create_maze(av);
}
