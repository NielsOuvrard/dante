/*
** EPITECH PROJECT, 2022
** gen recursive
** File description:
** recursive
*/

#include "my.h"
#include "gen_sol_header.h"


int is_okay_to_dig_n_next(char **maze, three_tree *three,
int ntw_w, int ntw_n)
{
    if (maze[three->y - 1][three->x] == '*')
        return 0;
    if (!ntw_w && maze[three->y - 1][three->x - 1] == '*')
        return 0;
    if (!ntw_n && !ntw_w && maze[three->y - 2][three->x - 1] == '*')
        return 0;
    if (!ntw_n && maze[three->y - 2][three->x] == '*')
        return 0;
    return 1;
}

int is_okay_to_dig_n(char **maze, three_tree *three, sfVector2i infos)
{
    if (three->y == 0)
        return 0;
    int ntw_n = 0, ntw_e = 0, ntw_w = 0;
    if (three->y == 1)
        ntw_n = 1;
    if (three->x == infos.x)
        ntw_e = 1;
    else if (three->x == 0)
        ntw_w = 1;
    if (!ntw_n && !ntw_e && maze[three->y - 2][three->x + 1] == '*')
        return 0;
    if (!ntw_e && maze[three->y - 1][three->x + 1] == '*')
        return 0;
    return is_okay_to_dig_n_next(maze, three, ntw_w, ntw_n);
}

int is_okay_to_dig_s_next(char **maze, three_tree *three,
int ntw_s, int ntw_w)
{
    if (!ntw_w && maze[three->y + 1][three->x - 1] == '*')
        return 0;
    if (!ntw_s && maze[three->y + 2][three->x] == '*')
        return 0;
    if (maze[three->y + 1][three->x] == '*')
        return 0;
    if (!ntw_s && !ntw_w && maze[three->y + 2][three->x - 1] == '*')
        return 0;
    return 1;
}

int is_okay_to_dig_s(char **maze, three_tree *three, sfVector2i infos)
{
    if (three->y >= infos.y - 1)
        return 0;
    int ntw_s = 0, ntw_e = 0, ntw_w = 0;
    if (three->y == infos.y - 2)
        ntw_s = 1;
    if (three->x >= infos.x)
        ntw_e = 1;
    else if (three->x == 0)
        ntw_w = 1;
    if (!ntw_s && !ntw_e && maze[three->y + 2][three->x + 1] == '*')
        return 0;
    if (!ntw_e && maze[three->y + 1][three->x + 1] == '*')
        return 0;
    return is_okay_to_dig_s_next(maze, three, ntw_s, ntw_w);
}
