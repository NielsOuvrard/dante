/*
** EPITECH PROJECT, 2022
** gen recursive
** File description:
** recursive
*/

#include "my.h"
#include "gen_sol_header.h"

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

three_tree * free_the_last_next (three_tree *three)
{
    if (three->prev == 'e') {
        three->east->west = NULL;
        three_tree *tmp = three;
        three = three->east;
        free(tmp);
        return three;
    }
    if (three->prev == 'w') {
        three->west->east = NULL;
        three_tree *tmp = three;
        three = three->west;
        free(tmp);
        return three;
    }
    return three;
}

three_tree * free_the_last (three_tree *three)
{
    if (three->prev == 'n') {
        three->north->south = NULL;
        three_tree *tmp = three;
        three = three->north;
        free(tmp);
        return three;
    }
    if (three->prev == 's') {
        three->south->north = NULL;
        three_tree *tmp = three;
        three = three->south;
        free(tmp);
        return three;
    }
    return free_the_last_next(three);
}

three_tree *looking_for_new_way (char **maze, three_tree *three,
sfVector2i infos)
{
    while (three && !is_okay_to_dig(maze, three, 'w', infos) &&
    !is_okay_to_dig(maze, three, 'e', infos) &&
    !is_okay_to_dig(maze, three, 'n', infos) &&
    !is_okay_to_dig(maze, three, 's', infos)) {
        three = free_the_last(three);
        if (three && three->x == 1 && three->y == 1)
            return NULL;
    }
    if (!three)
        return NULL;
    return three;
}
