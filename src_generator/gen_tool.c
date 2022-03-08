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

int gestion_erreur (int ac, char **av)                                          // others arguments ?
{
    if (ac < 2 || ac > 4)
        return 1;
    if (!my_isnbr(av[1]) || !my_isnbr(av[2]))
        return 2;
    if (ac == 4 && my_strvcmp(av[3], "perfect"))
        return 3;
    return 0;
}
