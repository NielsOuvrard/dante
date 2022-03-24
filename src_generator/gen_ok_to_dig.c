/*
** EPITECH PROJECT, 2022
** gen recursive
** File description:
** recursive
*/

#include "my.h"
#include "gen_sol_header.h"


int is_okay_to_dig_n (char **maze, three_tree *three, sfVector2i infos)
{
    // if (three->y >= 2 && three->x >= 1 && infos.x >= three->x + 1 && infos.y > three->y + 1 &&
    // maze[three->y - 1][three->x + 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
    // maze[three->y - 2][three->x + 1] != '*' && maze[three->y - 2][three->x - 1] != '*' &&
    // maze[three->y - 1][three->x] != '*' &&
    // maze[three->y - 2][three->x] != '*') {
    //     return 1;
    // }
    if (three->y == 0)
        return 0;

    int ntw_n = 0, ntw_e = 0, ntw_w = 0;
    if (three->y == 1)              // ?
        ntw_n = 1;
    if (three->x == infos.x)
        ntw_e = 1;
    else if (three->x == 0)
        ntw_w = 1;
    // * ...
    // if (three->y >= 2 && three->x >= 1 && infos.x >= three->x + 1 && infos.y > three->y + 1)
    //     return 0;
    if (maze[three->y - 1][three->x] == '*')
        return 0;
    if (!ntw_e && maze[three->y - 1][three->x + 1] == '*')
        return 0;
    if (!ntw_w && maze[three->y - 1][three->x - 1] == '*')
        return 0;
    if (!ntw_n && !ntw_e && maze[three->y - 2][three->x + 1] == '*')
        return 0;
    if (!ntw_n && !ntw_w && maze[three->y - 2][three->x - 1] == '*')
        return 0;
    if (!ntw_n && maze[three->y - 2][three->x] == '*')
        return 0;
    return 1;
}

int is_okay_to_dig_s (char **maze, three_tree *three, sfVector2i infos)
{
    // if (infos.y > three->y + 2 && three->x >= 1 && three->y >= 1 && infos.x >= three->x + 1 &&
    // maze[three->y + 1][three->x + 1] != '*' && maze[three->y + 1][three->x - 1] != '*' &&
    // maze[three->y + 2][three->x + 1] != '*' && maze[three->y + 2][three->x - 1] != '*' &&
    // maze[three->y + 1][three->x] != '*' &&
    // maze[three->y + 2][three->x] != '*') {
    //     return 1;
    // }
    if (three->y >= infos.y - 1)// || three->y == infos.y - 1)
        return 0;

    int ntw_s = 0, ntw_e = 0, ntw_w = 0;
    if (three->y == infos.y - 2)
        ntw_s = 1;
    if (three->x >= infos.x)
        ntw_e = 1;
    else if (three->x == 0)
        ntw_w = 1;


    // if (infos.y > three->y + 2 && three->x >= 1 && three->y >= 1 && infos.x >= three->x + 1)
    //     return 0;

    // my_show_word_array(maze);
    // my_printf("infos y : %d\n", infos.y);
    // my_printf("three y : %d\n", three->y);
    if (maze[three->y + 1][three->x] == '*')
        return 0;
    if (!ntw_e && maze[three->y + 1][three->x + 1] == '*')
        return 0;
    if (!ntw_w && maze[three->y + 1][three->x - 1] == '*')
        return 0;
    if (!ntw_s && maze[three->y + 2][three->x] == '*')
        return 0;
    if (!ntw_s && !ntw_e && maze[three->y + 2][three->x + 1] == '*')  // ?
        return 0;
    if (!ntw_s && !ntw_w && maze[three->y + 2][three->x - 1] == '*')
        return 0;
    return 1;
}

int is_okay_to_dig_e (char **maze, three_tree *three, sfVector2i infos)
{
    // if (infos.x >= three->x + 2 && infos.y > three->y + 1 && three->x >= 1 && three->y >= 1 &&
    // maze[three->y + 1][three->x + 1] != '*' && maze[three->y - 1][three->x + 1] != '*' &&
    // maze[three->y + 1][three->x + 2] != '*' && maze[three->y - 1][three->x + 2] != '*' &&
    // maze[three->y][three->x + 1] != '*' &&
    // maze[three->y][three->x + 2] != '*') {
    //     return 1;
    // }
    // return 0;

    // my_printf("infos y : %d\n", infos.y);
    // my_printf("infos x : %d\n\n", infos.x);
    // my_printf("three y : %d\n", three->y);
    // my_printf("three x : %d\n\n", three->x);
    if (infos.x - 1 <= three->x)
        return 0;

    int ntw_e = 0, ntw_s = 0, ntw_n = 0;;
    if (infos.x - 2 == three->x)
        ntw_e = 1;
    if (three->y >= infos.y - 1)
        ntw_s = 1;
    if (three->y <= 0)
        ntw_n = 1;

    // if (infos.x >= three->x + 2 && infos.y > three->y)
    // if (+ 1 && three->x >= 1 && three->y >= 1)
    // my_printf("ok\n");
    // my_show_word_array(maze);
    if (maze[three->y][three->x + 1] == '*')
        return 0;
    if (!ntw_s && maze[three->y + 1][three->x + 1] == '*')
        return 0;
    if (!ntw_n && maze[three->y - 1][three->x + 1] == '*')
        return 0;
    if (!ntw_e && maze[three->y][three->x + 2] == '*')
        return 0;
    if (!ntw_e && !ntw_s && maze[three->y + 1][three->x + 2] == '*')
        return 0;
    if (!ntw_e && !ntw_n && maze[three->y - 1][three->x + 2] == '*')
        return 0;
    return 1;
}

int is_okay_to_dig_w (char **maze, three_tree *three, sfVector2i infos)
{
    // if (three->x >= 2 && three->y >= 1 && infos.x >= three->x + 1 && infos.y > three->y + 1 &&
    // maze[three->y + 1][three->x - 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
    // maze[three->y + 1][three->x - 2] != '*' && maze[three->y - 1][three->x - 2] != '*' &&
    // maze[three->y][three->x - 1] != '*' &&
    // maze[three->y][three->x - 2] != '*') {
    //     return 1;
    // }
    if (three->x == 0)
        return 0;

    int ntw_w = 0, ntw_s = 0, ntw_n = 0;
    if (three->x == 1)
        ntw_w = 1;
    if (three->y == infos.y - 1)
        ntw_s = 1;
    if (three->y == 0)
        ntw_n = 1;
    // if (!(three->x >= 2 && three->y >= 1))
    //     return 0;
    // if (!(infos.x >= three->x + 1 && infos.y > three->y + 1))
    //     return 0;
    if (maze[three->y][three->x - 1] == '*')
        return 0;
    if (!ntw_s && maze[three->y + 1][three->x - 1] == '*')
        return 0;
    if (!ntw_n && maze[three->y - 1][three->x - 1] == '*')
        return 0;
    if (!ntw_w && maze[three->y][three->x - 2] == '*')
        return 0;
    if (!ntw_w && !ntw_n && maze[three->y - 1][three->x - 2] == '*')
        return 0;
    if (!ntw_w && !ntw_s && maze[three->y + 1][three->x - 2] == '*')
        return 0;
    return 1;
}
// faire if x return 0 ... return 0 ... else donc, return 1

int is_okay_to_dig (char **maze, three_tree *three, char direction,
sfVector2i infos)
{
    if (direction == 'n')
        return is_okay_to_dig_n(maze, three, infos);
    if (direction == 's')
        return is_okay_to_dig_s(maze, three, infos);
    if (direction == 'w')
        return is_okay_to_dig_w(maze, three, infos);
    if (direction == 'e')
        return is_okay_to_dig_e(maze, three, infos);
    return 0;
}
