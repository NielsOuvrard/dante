/*
** EPITECH PROJECT, 2022
** gen recursive
** File description:
** recursive
*/

#include "my.h"
#include "gen_sol_header.h"


int is_okay_to_dig_e_next (char **maze, three_tree *three,
int ntw_n, int ntw_e)
{
    if (maze[three->y][three->x + 1] == '*')
        return 0;
    if (!ntw_e && maze[three->y][three->x + 2] == '*')
        return 0;
    if (!ntw_e && !ntw_n && maze[three->y - 1][three->x + 2] == '*')
        return 0;
    if (!ntw_n && maze[three->y - 1][three->x + 1] == '*')
        return 0;
    return 1;
}

int is_okay_to_dig_e (char **maze, three_tree *three, sfVector2i infos)
{
    if (infos.x - 1 <= three->x)
        return 0;
    int ntw_e = 0, ntw_s = 0, ntw_n = 0;;
    if (infos.x - 2 == three->x)
        ntw_e = 1;
    if (three->y >= infos.y - 1)
        ntw_s = 1;
    if (three->y <= 0)
        ntw_n = 1;
    if (!ntw_e && !ntw_s && maze[three->y + 1][three->x + 2] == '*')
        return 0;
    if (!ntw_s && maze[three->y + 1][three->x + 1] == '*')
        return 0;
    return is_okay_to_dig_e_next(maze, three, ntw_n, ntw_e);
}

int is_okay_to_dig_w_next (char **maze, three_tree *three,
int ntw_w, int ntw_s)
{
    if (maze[three->y][three->x - 1] == '*')
        return 0;
    if (!ntw_s && maze[three->y + 1][three->x - 1] == '*')
        return 0;
    if (!ntw_w && maze[three->y][three->x - 2] == '*')
        return 0;
    if (!ntw_w && !ntw_s && maze[three->y + 1][three->x - 2] == '*')
        return 0;
    return 1;
}

int is_okay_to_dig_w (char **maze, three_tree *three, sfVector2i infos)
{
    if (three->x == 0)
        return 0;
    int ntw_w = 0, ntw_s = 0, ntw_n = 0;
    if (three->x == 1)
        ntw_w = 1;
    if (three->y == infos.y - 1)
        ntw_s = 1;
    if (three->y == 0)
        ntw_n = 1;
    if (!ntw_n && maze[three->y - 1][three->x - 1] == '*')
        return 0;
    if (!ntw_w && !ntw_n && maze[three->y - 1][three->x - 2] == '*')
        return 0;
    return is_okay_to_dig_w_next(maze, three, ntw_w, ntw_s);
}

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
