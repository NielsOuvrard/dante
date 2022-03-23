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

    if (three->y >= 2 && three->x >= 1 && infos.x >= three->x + 1 && infos.y > three->y + 1 &&
    maze[three->y - 1][three->x + 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
    maze[three->y - 2][three->x + 1] != '*' && maze[three->y - 2][three->x - 1] != '*' &&
    maze[three->y - 1][three->x] != '*' &&
    maze[three->y - 2][three->x] != '*') {
        return 1;
    }
    return 0;
}

int is_okay_to_dig_s (char **maze, three_tree *three, sfVector2i infos)
{
    if (infos.y > three->y + 2 && three->x >= 1 && three->y >= 1 && infos.x >= three->x + 1 &&
    maze[three->y + 1][three->x + 1] != '*' && maze[three->y + 1][three->x - 1] != '*' &&
    maze[three->y + 2][three->x + 1] != '*' && maze[three->y + 2][three->x - 1] != '*' &&
    maze[three->y + 1][three->x] != '*' &&
    maze[three->y + 2][three->x] != '*') {
        return 1;
    }
    return 0;
}

int is_okay_to_dig_e (char **maze, three_tree *three, sfVector2i infos)
{
    if (infos.x >= three->x + 2 && infos.y > three->y + 1 && three->x >= 1 && three->y >= 1 &&
    maze[three->y + 1][three->x + 1] != '*' && maze[three->y - 1][three->x + 1] != '*' &&
    maze[three->y + 1][three->x + 2] != '*' && maze[three->y - 1][three->x + 2] != '*' &&
    maze[three->y][three->x + 1] != '*' &&
    maze[three->y][three->x + 2] != '*') {
        return 1;
    }
    return 0;
}

int is_okay_to_dig_w (char **maze, three_tree *three, sfVector2i infos)
{
    if (three->x >= 2 && three->y >= 1 && infos.x >= three->x + 1 && infos.y > three->y + 1 &&
    maze[three->y + 1][three->x - 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
    maze[three->y + 1][three->x - 2] != '*' && maze[three->y - 1][three->x - 2] != '*' &&
    maze[three->y][three->x - 1] != '*' &&
    maze[three->y][three->x - 2] != '*') {
        return 1;
    }
    return 0;
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
