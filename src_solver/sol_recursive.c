/*
** EPITECH PROJECT, 2022
** sol_recursive.c
** File description:
** sol_recursive
*/

#include "my.h"
#include "gen_sol_header.h"

void dump_solve_list (list_solve *solve)
{
    my_putstr("NODE :\n");
    my_printf("x : %d\n", solve->x);
    my_printf("y : %d\n", solve->y);
    my_printf("dir : %c\n", solve->dir);
    my_printf("next : %c\n", solve->next ? 'Y' : 'N');
    my_printf("prev : %c\n", solve->prev ? 'Y' : 'N');
}

// int antother_way (char **maze, list_solve *solve)
// {
//     // int max_cols = my_strlen(maze[0]), max_lignes = my_arraylen(maze);
//     if (!solve || !solve->prev)
//         return 0;
//     if (solve->dir == 'n' && ok_to_north(maze, solve)) {
//         if (ok_to_east(maze, solve) || ok_to_west(maze, solve) || ok_to_south(maze, solve))
//             //

//     }
//     return 1;
// }

list_solve *looking_for_new_way_solver (char **maze, list_solve *solve)
{
    while (solve && solve->prev && solve->dir /* && other way */) {
        solve = solve->prev;
        if (solve && solve->x == 1 && solve->y == 1)
            return solve;
        // if (antother_way ...)
    }
    if (!solve)
        return NULL;
    return NULL;
}

// int check_in_front (char **maze, list_solve *solve, char direction)
// {
//     int max_cols = my_strlen(maze[0]), max_lignes = my_arraylen(maze);
//     if (direction != 's' && solve->y + 1 < max_lignes && maze[solve->y + 1][solve->x] == '*')
//         return 1;
//     if (direction != 'n' && solve->y > 0 && maze[solve->y - 1][solve->x] == '*')
//         return 2;
//     if (direction != 'w' && solve->x + 1 < max_cols && maze[solve->y][solve->x + 1] == '*')
//         return 3;
//     if (direction != 'e' && solve->x > 0 && maze[solve->y][solve->x - 1] == '*')
//         return 4;
//     return 0;
// }

// 1 N
// 2 S
// 3 E
// 4 W

int recursive_solver (char **maze, list_solve *solve)
{
    // dump_solve_list(solve);
    int max_cols = my_strlen(maze[0]), max_lignes = my_arraylen(maze);
    if (solve->x == max_cols && solve->y == max_lignes)
        return 0;
    maze[solve->y][solve->x] = 'o';
    int direction;
    if (solve->dir == 's') { // w / s / e
        if (ok_to_west(maze, solve))
            return turn_to_west(maze, solve);
        if (ok_to_south(maze, solve))
            return turn_to_south(maze, solve);
        if (ok_to_east(maze, solve))
            return turn_to_east(maze, solve);
    }
    if (solve->dir == 'e') { // s / e / n
        if (ok_to_south(maze, solve))
            return turn_to_south(maze, solve);
        if (ok_to_east(maze, solve))
            return turn_to_east(maze, solve);
        if (ok_to_north(maze, solve))
            return turn_to_north(maze, solve);
    }
    if (solve->dir == 'n') { // e / n / w
        if (ok_to_east(maze, solve))
            return turn_to_east(maze, solve);
        if (ok_to_north(maze, solve))
            return turn_to_north(maze, solve);
        if (ok_to_west(maze, solve))
            return turn_to_west(maze, solve);
    }
    if (solve->dir == 'w') { // n / w / s
        if (ok_to_north(maze, solve))
            return turn_to_north(maze, solve);
        if (ok_to_west(maze, solve))
            return turn_to_west(maze, solve);
        if (ok_to_south(maze, solve))
            return turn_to_south(maze, solve);
    }
    my_printf("go back motherf***\n");
    return 0;
}
