/*
** EPITECH PROJECT, 2022
** gen_nsew_dir.c
** File description:
** gen_nsew_dir.c
*/

#include "my.h"
#include "gen_sol_header.h"

three_tree *retry (char **maze, three_tree *three, sfVector2i infos)
{
    if (!three->north && is_okay_to_dig(maze, three, 'n', infos))
        return north_dir(maze, three, infos);
    if (!three->south && is_okay_to_dig(maze, three, 's', infos))
        return south_dir(maze, three, infos);
    if (!three->east && is_okay_to_dig(maze, three, 'e', infos))
        return east_dir(maze, three, infos);
    if (!three->west && is_okay_to_dig(maze, three, 'w', infos))
        return west_dir(maze, three, infos);
    return looking_for_new_way(maze, three, infos);
}

three_tree *north_dir (char **maze, three_tree *three, sfVector2i infos)
{
    if (is_okay_to_dig(maze, three, 'n', infos)) {
        maze[three->y - 1][three->x] = '*';
        my_put_end_list(three, three->x, three->y - 1, 'n');
        return three->north;
    }
    return retry(maze, three, infos);
}

three_tree *east_dir (char **maze, three_tree *three, sfVector2i infos)
{
    if (is_okay_to_dig(maze, three, 'e', infos)) {
        maze[three->y][three->x + 1] = '*';
        my_put_end_list(three, three->x + 1, three->y, 'e');
        return three->east;
    }
    return retry(maze, three, infos);
}

three_tree *south_dir (char **maze, three_tree *three, sfVector2i infos)
{
    if (is_okay_to_dig(maze, three, 's', infos)) {
        maze[three->y + 1][three->x] = '*';
        my_put_end_list(three, three->x, three->y + 1, 's');
        return three->south;
    }
    return retry(maze, three, infos);
}

three_tree *west_dir (char **maze, three_tree *three, sfVector2i infos)
{
    if (is_okay_to_dig(maze, three, 'w', infos)) {
        maze[three->y][three->x - 1] = '*';
        my_put_end_list(three, three->x - 1, three->y, 'w');
        return three->west;
    }
    return retry(maze, three, infos);
}
