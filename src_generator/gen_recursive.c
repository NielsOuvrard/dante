/*
** EPITECH PROJECT, 2022
** gen recursive
** File description:
** recursive
*/

#include "my.h"
#include "gen_sol_header.h"

three_tree *recursive_dig (char **maze, three_tree *three, int max_lignes, int max_cols);

three_tree *north_dir (char **maze, three_tree *three, int max_lignes, int max_cols)
{
    if (three->y >= 2 && three->x >= 1 && max_cols >= three->x + 1 && max_lignes > three->y + 1 &&
    maze[three->y - 1][three->x + 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
    maze[three->y - 1][three->x] != '*' && maze[three->y - 1][three->x] != '*' &&
    maze[three->y - 2][three->x] != '*') {
        my_putstr("n\t");
        maze[three->y - 1][three->x] = '*';
        my_put_end_list(three, three->x, three->y - 1, 'n');
        return recursive_dig(maze, three->north, max_lignes, max_cols);
    }
    return three;
}

three_tree *east_dir (char **maze, three_tree *three, int max_lignes, int max_cols)
{
    if (three->x >= 2 && three->y >= 1 && max_cols >= three->x + 1 && max_lignes > three->y + 1 &&
    maze[three->y + 1][three->x - 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
    maze[three->y][three->x - 1] != '*' &&
    maze[three->y][three->x - 2] != '*') {
        my_putstr("e\t");
        maze[three->y][three->x - 1] = '*';
        my_put_end_list(three, three->x - 1, three->y, 'e');
        return recursive_dig(maze, three->east, max_lignes, max_cols);
    }
    return three;
}

three_tree *south_dir (char **maze, three_tree *three, int max_lignes, int max_cols)
{
    if (max_lignes > three->y + 2 && three->x >= 1 && three->y >= 1 && max_cols >= three->x + 1 &&
    maze[three->y + 1][three->x + 1] != '*' && maze[three->y + 1][three->x - 1] != '*' &&
    maze[three->y + 1][three->x] != '*' &&
    maze[three->y + 2][three->x] != '*') {
        my_putstr("s\t");
        maze[three->y + 1][three->x] = '*';
        my_put_end_list(three, three->x, three->y + 1, 's');
        return recursive_dig(maze, three->south, max_lignes, max_cols);
    }
    return three;
}

three_tree *west_dir (char **maze, three_tree *three, int max_lignes, int max_cols)
{
    if (max_cols >= three->x + 2 && max_lignes > three->y + 1 && three->x >= 1 && three->y >= 1 &&
    maze[three->y + 1][three->x + 1] != '*' && maze[three->y - 1][three->x + 1] != '*' &&
    maze[three->y][three->x + 1] != '*' &&
    maze[three->y][three->x + 2] != '*') {
        my_putstr("w\t");
        maze[three->y][three->x + 1] = '*';
        my_put_end_list(three, three->x + 1, three->y, 'w');
        return recursive_dig(maze, three->west, max_lignes, max_cols);
    }
    return three;
}

// recursive backtracker

three_tree *recursive_dig (char **maze, three_tree *three, int max_lignes, int max_cols)
{
    if (!three)
        return three;
    int rando = random_int(1, 3);
    if (three->prev == 'n') {
        my_putchar('n');
        my_printf("rnado : %d\n", rando);
        if (rando == 1)
            return east_dir(maze, three->west, max_lignes, max_cols);
        else if (rando == 2)
            return south_dir(maze, three->west, max_lignes, max_cols);
        else
            return west_dir(maze, three->west, max_lignes, max_cols);
    } else if (three->prev == 's') {
        if (rando == 1)
            return north_dir(maze, three->west, max_lignes, max_cols);
        else if (rando == 2)
            return east_dir(maze, three->west, max_lignes, max_cols);
        else
            return west_dir(maze, three->west, max_lignes, max_cols);
    }
    if (three->prev == 'e') {
        if (rando == 1)
            return north_dir(maze, three->west, max_lignes, max_cols);
        else if (rando == 2)
            return south_dir(maze, three->west, max_lignes, max_cols);
        else
            return west_dir(maze, three->west, max_lignes, max_cols);
    } else if (three->prev == 'w') {
        if (rando == 1)
            return north_dir(maze, three->west, max_lignes, max_cols);
        else if (rando == 2)
            return east_dir(maze, three->west, max_lignes, max_cols);
        else
            return south_dir(maze, three->west, max_lignes, max_cols);
    }
    return three;
}

    // my_show_word_array(maze);
    // if (rando == 1) {
        // ? north
        // return north_dir(maze, three->west, max_lignes, max_cols);
        // if (three->y >= 2 && three->x >= 1 && max_cols >= three->x + 1 && max_lignes > three->y + 1 &&
        // maze[three->y - 1][three->x + 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
        // maze[three->y - 1][three->x] != '*' && maze[three->y - 1][three->x] != '*' &&
        // maze[three->y - 2][three->x] != '*') {
        //     // my_putstr("n\t");
        //     maze[three->y - 1][three->x] = '*';
        //     my_put_end_list(three, three->x, three->y - 1, 'n');
        //     return recursive_dig(maze, three->north, max_lignes, max_cols);
        // }
    // } else if (rando == 2) {
        // ? east
        // return east_dir(maze, three->west, max_lignes, max_cols);
        // if (three->x >= 2 && three->y >= 1 && max_cols >= three->x + 1 && max_lignes > three->y + 1 &&
        // maze[three->y + 1][three->x - 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
        // maze[three->y][three->x - 1] != '*' &&
        // maze[three->y][three->x - 2] != '*') {
        //     // my_putstr("e\t");
        //     maze[three->y][three->x - 1] = '*';
        //     my_put_end_list(three, three->x - 1, three->y, 'e');
        //     return recursive_dig(maze, three->east, max_lignes, max_cols);
        // }
    // }
    // if (rando == 3) {
        // ? south
        // return south_dir(maze, three->west, max_lignes, max_cols);
        // if (max_lignes > three->y + 2 && three->x >= 1 && three->y >= 1 && max_cols >= three->x + 1 &&
        // maze[three->y + 1][three->x + 1] != '*' && maze[three->y + 1][three->x - 1] != '*' &&
        // maze[three->y + 1][three->x] != '*' &&
        // maze[three->y + 2][three->x] != '*') {
        //     // my_putstr("s\t");
        //     maze[three->y + 1][three->x] = '*';
        //     my_put_end_list(three, three->x, three->y + 1, 's');
        //     return recursive_dig(maze, three->south, max_lignes, max_cols);
        // }
    // } else if (rando == 4) {
        // ? WEST
        // return west_dir(maze, three->west, max_lignes, max_cols);
        // if (max_cols >= three->x + 2 && max_lignes > three->y + 1 && three->x >= 1 && three->y >= 1 &&
        // maze[three->y + 1][three->x + 1] != '*' && maze[three->y - 1][three->x + 1] != '*' &&
        // maze[three->y][three->x + 1] != '*' &&
        // maze[three->y][three->x + 2] != '*') {
        //     // my_putstr("w\t");
        //     maze[three->y][three->x + 1] = '*';
        //     my_put_end_list(three, three->x + 1, three->y, 'w');
        //     return recursive_dig(maze, three->west, max_lignes, max_cols);
        // }
    // }
    // if (three->prev == 'w')
    //     recursive_dig(maze, three->west, max_lignes, max_cols);
    // if (three->prev == 'n')
    //     recursive_dig(maze, three->north, max_lignes, max_cols);
    // if (three->prev == 's')
    //     recursive_dig(maze, three->south, max_lignes, max_cols);
    // if (three->prev == 'e')
    //     recursive_dig(maze, three->east, max_lignes, max_cols);
    // recursive_dig(maze, three->)
    // my_putstr("0\n");
//     return 0;
// }
