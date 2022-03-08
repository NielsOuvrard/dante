/*
** EPITECH PROJECT, 2022
** gen recursive
** File description:
** recursive
*/

#include "my.h"
#include "gen_sol_header.h"

three_tree *recursive_dig (char **maze, three_tree *three);

three_tree *north_dir (char **maze, three_tree *three);

three_tree *south_dir (char **maze, three_tree *three);

three_tree *east_dir (char **maze, three_tree *three);

three_tree *west_dir (char **maze, three_tree *three);

int is_okay_to_dig (char **maze, three_tree *three, char direction)
{
    int max_cols = my_strlen(maze[0]), max_lignes = my_arraylen(maze);
    if (direction == 'n') {
        if (three->y >= 2 && three->x >= 1 && max_cols >= three->x + 1 && max_lignes > three->y + 1 &&
        maze[three->y - 1][three->x + 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
        maze[three->y - 1][three->x] != '*' && maze[three->y - 1][three->x] != '*' &&
        maze[three->y - 2][three->x] != '*') {
            return 1;
        }
    } else if (direction == 's') {
        if (max_lignes > three->y + 2 && three->x >= 1 && three->y >= 1 && max_cols >= three->x + 1 &&
        maze[three->y + 1][three->x + 1] != '*' && maze[three->y + 1][three->x - 1] != '*' &&
        maze[three->y + 1][three->x] != '*' &&
        maze[three->y + 2][three->x] != '*') {
            return 1;
        }
    }
    if (direction == 'e') {
        if (three->x >= 2 && three->y >= 1 && max_cols >= three->x + 1 && max_lignes > three->y + 1 &&
        maze[three->y + 1][three->x - 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
        maze[three->y][three->x - 1] != '*' &&
        maze[three->y][three->x - 2] != '*') {
            return 1;
        }
    } else if (direction == 'w') {
        if (max_cols >= three->x + 2 && max_lignes > three->y + 1 && three->x >= 1 && three->y >= 1 &&
        maze[three->y + 1][three->x + 1] != '*' && maze[three->y - 1][three->x + 1] != '*' &&
        maze[three->y][three->x + 1] != '*' &&
        maze[three->y][three->x + 2] != '*') {
            return 1;
        }
    }
    return 0;
}

three_tree *retry (char **maze, three_tree *three)
{
    if ((three->prev == 'n' && three->north != NULL) || (three->prev == 's' && three->south != NULL)
    || (three->prev == 'e' && three->east != NULL) || (three->prev == 'w' && three->west != NULL)) {
        return three;
    }
    if (!three->north && is_okay_to_dig(maze, three, 'n')) {
        return north_dir(maze, three);
    } else if (!three->south && is_okay_to_dig(maze, three, 's')) {
        return south_dir(maze, three);
    }
    if (!three->east && is_okay_to_dig(maze, three, 'e')) {
        return east_dir(maze, three);
    } else if (!three->west && is_okay_to_dig(maze, three, 'w')) {
        return west_dir(maze, three);
    }
    return three;
}

three_tree *north_dir (char **maze, three_tree *three)
{
    if (is_okay_to_dig(maze, three, 'n')) {
        // my_putstr("n\t");
        maze[three->y - 1][three->x] = '*';
        my_put_end_list(three, three->x, three->y - 1, 'n');
        return recursive_dig(maze, three->north);
    }
    return retry(maze, three);
}

three_tree *east_dir (char **maze, three_tree *three)
{
    if (is_okay_to_dig(maze, three, 'e')) {
        // my_putstr("e\t");
        maze[three->y][three->x - 1] = '*';
        my_put_end_list(three, three->x - 1, three->y, 'e');
        return recursive_dig(maze, three->east);
    }
    return retry(maze, three);
}

three_tree *south_dir (char **maze, three_tree *three)
{
    if (is_okay_to_dig(maze, three, 's')) {
        // my_putstr("s\t");
        maze[three->y + 1][three->x] = '*';
        my_put_end_list(three, three->x, three->y + 1, 's');
        return recursive_dig(maze, three->south);
    }
    return retry(maze, three);
}

three_tree *west_dir (char **maze, three_tree *three)
{
    if (is_okay_to_dig(maze, three, 'w')) {
        // my_putstr("w\t");
        maze[three->y][three->x + 1] = '*';
        my_put_end_list(three, three->x + 1, three->y, 'w');
        return recursive_dig(maze, three->west);
    }
    return retry(maze, three);
}

// recursive backtracker

three_tree *recursive_dig (char **maze, three_tree *three)
{
    if (!three)
        return three;
    int rando = random_int(1, 3);
    my_printf("rando : %d\n", rando);
    if (three->prev == 'n') {
        if (rando == 1)
            return east_dir(maze, three);
        else if (rando == 2)
            return south_dir(maze, three);
        else
            return west_dir(maze, three);
    } else if (three->prev == 's') {
        if (rando == 1)
            return north_dir(maze, three);
        else if (rando == 2)
            return east_dir(maze, three);
        else
            return west_dir(maze, three);
    }
    if (three->prev == 'e') {
        if (rando == 1)
            return north_dir(maze, three);
        else if (rando == 2)
            return south_dir(maze, three);
        else
            return west_dir(maze, three);
    } else if (three->prev == 'w') {
        if (rando == 1)
            return north_dir(maze, three);
        else if (rando == 2)
            return east_dir(maze, three);
        else
            return south_dir(maze, three);
    }
    return three;
}
