/*
** EPITECH PROJECT, 2022
** gen recursive
** File description:
** recursive
*/

#include "my.h"
#include "gen_sol_header.h"

three_tree *recursive_dig (char **maze, three_tree *three, sfVector2i infos)
{
    if (!three)
        return three;
    while (three && three->prev)
        three = test_test(maze, three, infos);
    return NULL;
}

// php 7.4.27
