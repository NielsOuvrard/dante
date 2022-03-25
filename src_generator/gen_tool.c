/*
** EPITECH PROJECT, 2022
** gen_tool.c
** File description:
** gen tool
*/

#include "my.h"
#include "gen_sol_header.h"

int random_int (int min, int max)
{
    int retour = min + (rand() % (max + 1));
    return retour;
}

int gestion_erreur (int ac, char **av)
{
    if (ac < 2 || ac > 4)
        return 1;
    if (!my_isnbr(av[1]) || !my_isnbr(av[2]))
        return 2;
    if (ac == 4 && my_strvcmp(av[3], "perfect"))
        return 3;
    return 0;
}

void random_dig(char **maze, int i, int size)
{
    for (int j = 0; maze[i][j]; j++) {
        int val = random_int(0, size / size);
        if (val == 0) {
            maze[i][j] = '*';
        }
    }
}

int lignes_solo (int lignes, int cols)
{
    if (lignes == 1) {
        for (int i = 0; i < cols; i++)
            my_putchar('*');
        return 0;
    } else if (cols == 1) {
        for (int i = 0; i < lignes; i++)
            my_putchar('*');
        return 0;
    }
    return 1;
}