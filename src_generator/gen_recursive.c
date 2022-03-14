/*
** EPITECH PROJECT, 2022
** gen recursive
** File description:
** recursive
*/

#include "my.h"
#include "gen_sol_header.h"

int is_okay_to_dig (char **maze, three_tree *three, char direction)
{
    int max_cols = my_strlen(maze[0]), max_lignes = my_arraylen(maze);
    if (direction == 'n') {
        if (three->y >= 2 && three->x >= 1 && max_cols >= three->x + 1 && max_lignes > three->y + 1 &&
        maze[three->y - 1][three->x + 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
        maze[three->y - 2][three->x + 1] != '*' && maze[three->y - 2][three->x - 1] != '*' &&
        maze[three->y - 1][three->x] != '*' &&
        maze[three->y - 2][three->x] != '*') {
            return 1;
        }
    } else if (direction == 's') {
        if (max_lignes > three->y + 2 && three->x >= 1 && three->y >= 1 && max_cols >= three->x + 1 &&
        maze[three->y + 1][three->x + 1] != '*' && maze[three->y + 1][three->x - 1] != '*' &&
        maze[three->y + 2][three->x + 1] != '*' && maze[three->y + 2][three->x - 1] != '*' &&
        maze[three->y + 1][three->x] != '*' &&
        maze[three->y + 2][three->x] != '*') {
            return 1;
        }
    }
    if (direction == 'w') {
        if (three->x >= 2 && three->y >= 1 && max_cols >= three->x + 1 && max_lignes > three->y + 1 &&
        maze[three->y + 1][three->x - 1] != '*' && maze[three->y - 1][three->x - 1] != '*' &&
        maze[three->y + 1][three->x - 2] != '*' && maze[three->y - 1][three->x - 2] != '*' &&
        maze[three->y][three->x - 1] != '*' &&
        maze[three->y][three->x - 2] != '*') {
            return 1;
        }
    } else if (direction == 'e') {
        if (max_cols >= three->x + 2 && max_lignes > three->y + 1 && three->x >= 1 && three->y >= 1 &&
        maze[three->y + 1][three->x + 1] != '*' && maze[three->y - 1][three->x + 1] != '*' &&
        maze[three->y + 1][three->x + 2] != '*' && maze[three->y - 1][three->x + 2] != '*' &&
        maze[three->y][three->x + 1] != '*' &&
        maze[three->y][three->x + 2] != '*') {
            return 1;
        }
    }
    return 0;
}

void dump_three (three_tree *three)
{
    my_putstr("THREE :\n");
    my_printf("en x : %d\n", three->x);
    my_printf("en y : %d\n", three->y);
    my_printf("north : %c\n", three->north ? 'Y' : 'N');
    my_printf("south : %c\n", three->south ? 'Y' : 'N');
    my_printf("east : %c\n", three->east ? 'Y' : 'N');
    my_printf("west : %c\n", three->west ? 'Y' : 'N');
    my_printf("prev : %c\n", three->prev);
}

three_tree *looking_for_new_way (char **maze, three_tree *three)
{
    while (three && !is_okay_to_dig(maze, three, 'w') &&
    !is_okay_to_dig(maze, three, 'e') && !is_okay_to_dig(maze, three, 'n') &&
    !is_okay_to_dig(maze, three, 's')) {
        if (three->prev == 'n') {
            three->north->south = NULL;
            three_tree *tmp = three;
            three = three->north;
            free(tmp);
        } else if (three->prev == 's') {
            three->south->north = NULL;
            three_tree *tmp = three;
            three = three->south;
            free(tmp);
        } else if (three->prev == 'e') {
            three->east->west = NULL;
            three_tree *tmp = three;
            three = three->east;
            free(tmp);
        } else {
            three->west->east = NULL;
            three_tree *tmp = three;
            three = three->west;
            free(tmp);
        }
        // dump_three(three);
        // my_printf("test\n");
        if (three && three->x == 1 && three->y == 1)
            return NULL;
    }
    if (!three)
        return NULL;
    return three; //recursive_dig(maze, three);
}

// recursive backtracker

three_tree *recursive_dig (char **maze, three_tree *three)
{
    if (!three)
        return three;
    // dump_three(three);
    // my_printf("rando : %d\n", rando);
    while (three && three->prev) {
        // my_printf("a\n");
        // my_show_word_array(maze);
        int rando = random_int(1, 2);
        if (three->prev == 'n') {
            if (rando == 1)
                three = east_dir(maze, three);
            else if (rando == 2)
                three = south_dir(maze, three);
            else
                three = west_dir(maze, three);
        } else if (three->prev == 's') {
            if (rando == 1)
                three = north_dir(maze, three);
            else if (rando == 2)
                three = east_dir(maze, three);
            else
                three = west_dir(maze, three);
        } else if (three->prev == 'e') {
            if (rando == 1)
                three = north_dir(maze, three);
            else if (rando == 2)
                three = south_dir(maze, three);
            else
                three = west_dir(maze, three);
        } else if (three->prev == 'w') {
            if (rando == 1)
                three = north_dir(maze, three);
            else if (rando == 2)
                three = east_dir(maze, three);
            else
                three = south_dir(maze, three);
        }
    }
    return NULL;
}

// php 7.4.27
