/*
** EPITECH PROJECT, 2022
** gen recursive
** File description:
** recursive
*/

#include "my.h"
#include "gen_sol_header.h"

int is_okay_to_dig (char **maze, three_tree *three, char direction,
sfVector2i infos)
{
    // int max_cols = my_strlen(maze[0]), max_lignes = my_arraylen(maze);
    if (direction == 'n') {
        if (three->y >= 2 && three->x >= 1 && infos.x >= three->x + 1 && infos.y > three->y + 1 &&
        maze[three->y - 1][three->x + 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
        maze[three->y - 2][three->x + 1] != '*' && maze[three->y - 2][three->x - 1] != '*' &&
        maze[three->y - 1][three->x] != '*' &&
        maze[three->y - 2][three->x] != '*') {
            return 1;
        }
    } else if (direction == 's') {
        if (infos.y > three->y + 2 && three->x >= 1 && three->y >= 1 && infos.x >= three->x + 1 &&
        maze[three->y + 1][three->x + 1] != '*' && maze[three->y + 1][three->x - 1] != '*' &&
        maze[three->y + 2][three->x + 1] != '*' && maze[three->y + 2][three->x - 1] != '*' &&
        maze[three->y + 1][three->x] != '*' &&
        maze[three->y + 2][three->x] != '*') {
            return 1;
        }
    }
    if (direction == 'w') {
        if (three->x >= 2 && three->y >= 1 && infos.x >= three->x + 1 && infos.y > three->y + 1 &&
        maze[three->y + 1][three->x - 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
        maze[three->y + 1][three->x - 2] != '*' && maze[three->y - 1][three->x - 2] != '*' &&
        maze[three->y][three->x - 1] != '*' &&
        maze[three->y][three->x - 2] != '*') {
            return 1;
        }
    } else if (direction == 'e') {
        if (infos.x >= three->x + 2 && infos.y > three->y + 1 && three->x >= 1 && three->y >= 1 &&
        maze[three->y + 1][three->x + 1] != '*' && maze[three->y - 1][three->x + 1] != '*' &&
        maze[three->y + 1][three->x + 2] != '*' && maze[three->y - 1][three->x + 2] != '*' &&
        maze[three->y][three->x + 1] != '*' &&
        maze[three->y][three->x + 2] != '*') {
            return 1;
        }
    }
    return 0;
}
