/*
** EPITECH PROJECT, 2022
** gen recursive
** File description:
** recursive
*/

#include "my.h"
#include "gen_sol_header.h"

three_tree *recursive_dig_n (char **maze, three_tree *three,
int rando, sfVector2i infos)
{
    if (rando == 1)
        three = east_dir(maze, three, infos);
    else if (rando == 2)
        three = south_dir(maze, three, infos);
    else
        three = west_dir(maze, three, infos);
    return three;
}

three_tree *recursive_dig_s (char **maze, three_tree *three,
int rando, sfVector2i infos)
{
    if (rando == 1)
        three = north_dir(maze, three, infos);
    else if (rando == 2)
        three = east_dir(maze, three, infos);
    else
        three = west_dir(maze, three, infos);
    return three;
}

three_tree *recursive_dig_e (char **maze, three_tree *three,
int rando, sfVector2i infos)
{
    if (rando == 1)
        three = north_dir(maze, three, infos);
    else if (rando == 2)
        three = south_dir(maze, three, infos);
    else
        three = west_dir(maze, three, infos);
    return three;
}

three_tree *recursive_dig_w (char **maze, three_tree *three,
int rando, sfVector2i infos)
{
    if (rando == 1)
        three = north_dir(maze, three, infos);
    else if (rando == 2)
        three = east_dir(maze, three, infos);
    else
        three = south_dir(maze, three, infos);
    return three;
}

//tcsetpgrp
three_tree *test_test (char **maze, three_tree *three, sfVector2i infos)
{
    int rando = random_int(1, 2);
    if (three->prev == 'n')
        return recursive_dig_n(maze, three, rando, infos);
    if (three->prev == 's')
        return recursive_dig_s(maze, three, rando, infos);
    if (three->prev == 'e')
        return recursive_dig_e(maze, three, rando, infos);
    if (three->prev == 'w')
        return recursive_dig_w(maze, three, rando, infos);
}

three_tree *recursive_dig (char **maze, three_tree *three, sfVector2i infos)
{
    if (!three)
        return three;
    while (three && three->prev)
        three = test_test(maze, three, infos);
    return NULL;
}

// php 7.4.27
