/*
** EPITECH PROJECT, 2022
** sol_main.c
** File description:
** sol_main.c
*/

#include "my.h"
#include "gen_sol_header.h"

int gestion_erreure (int ac, char **av)
{
    return 1;
}

void dump_solve_list (list_solve *solve)
{
    my_putstr("NODE :\n");
    my_printf("x : %d\n", solve->x);
    my_printf("y : %d\n", solve->y);
    my_printf("dir : %c\n", solve->dir);
    my_printf("next : %c\n", solve->next ? 'Y' : 'N');
    my_printf("prev : %c\n", solve->prev ? 'Y' : 'N');
}

int check_in_front (char **maze, list_solve *solve, char direction)
{
    int max_cols = my_strlen(maze[0]), max_lignes = my_arraylen(maze);

    if (direction != 's' && solve->y + 1 < max_lignes   && maze[solve->y + 1][solve->x] == '*')
        return 1;
    if (direction != 'n' && solve->y > 0                && maze[solve->y - 1][solve->x] == '*')
        return 2;
    if (direction != 'w' && solve->x + 1 < max_cols     && maze[solve->y][solve->x + 1] == '*')
        return 3;
    if (direction != 'e' && solve->x > 0                && maze[solve->y][solve->x - 1] == '*')
        return 4;
    return 0;
}

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
        if (solve->x > 0 && maze[solve->y][solve->x - 1] == '*') {
            my_put_end_solve(solve, solve->x - 1, solve->y, 'w');
            return recursive_solver(maze, solve->next);
        }
        if (solve->y + 1 < max_lignes && maze[solve->y][solve->x + 1] == '*') {
            my_put_end_solve(solve, solve->x, solve->y + 1, 's');
            return recursive_solver(maze, solve->next);
        }
        if (solve->x + 1 < max_cols && maze[solve->y][solve->x + 1] == '*') {
            my_put_end_solve(solve, solve->x + 1, solve->y, 'e');
            return recursive_solver(maze, solve->next);
        }
    }
    if (solve->dir == 'e') { // s / e / n
        if (solve->y + 1 < max_lignes && maze[solve->y][solve->x + 1] == '*') {
            my_put_end_solve(solve, solve->x, solve->y + 1, 's');
            return recursive_solver(maze, solve->next);
        }
        if (solve->x + 1 < max_cols && maze[solve->y][solve->x + 1] == '*') {
            my_put_end_solve(solve, solve->x + 1, solve->y, 'e');
            return recursive_solver(maze, solve->next);
        }
        if (solve->y > 0 && maze[solve->y - 1][solve->x] == '*') {
            my_put_end_solve(solve, solve->x, solve->y - 1, 'n');
            return recursive_solver(maze, solve->next);
        }
    }
    if (solve->dir == 'n') { // e / n / w
        if (solve->x + 1 < max_cols && maze[solve->y][solve->x + 1] == '*') {
            my_put_end_solve(solve, solve->x + 1, solve->y, 'e');
            return recursive_solver(maze, solve->next);
        }
        if (solve->y > 0 && maze[solve->y - 1][solve->x] == '*') {
            my_put_end_solve(solve, solve->x, solve->y - 1, 'n');
            return recursive_solver(maze, solve->next);
        }
        if (solve->x > 0 && maze[solve->y][solve->x - 1] == '*') {
            my_put_end_solve(solve, solve->x - 1, solve->y, 'w');
            return recursive_solver(maze, solve->next);
        }
    }
    if (solve->dir == 'w') { // n / w / s
        if (solve->y > 0 && maze[solve->y - 1][solve->x] == '*') {
            my_put_end_solve(solve, solve->x, solve->y - 1, 'n');
            return recursive_solver(maze, solve->next);
        }
        if (solve->x > 0 && maze[solve->y][solve->x - 1] == '*') {
            my_put_end_solve(solve, solve->x - 1, solve->y, 'w');
            return recursive_solver(maze, solve->next);
        }
        if (solve->y + 1 < max_lignes && maze[solve->y][solve->x + 1] == '*') {
            my_put_end_solve(solve, solve->x, solve->y + 1, 's');
            return recursive_solver(maze, solve->next);
        }
    }
    my_printf("go back motherf***\n");
    return 0;
}

int solve_the_maze (char **av)
{
    char **maze = filepath_to_arr(av[1]);
    list_solve *solve = malloc(sizeof(list_solve));
    if (maze[0][0] != '*') {
        my_putstr("no solution found\n");
        return 0;
    }
    solve->x = 0;
    solve->y = 0;
    solve->dir = 'n';
    solve->next = NULL;
    solve->prev = NULL;
    // maze[solve->y][solve->x] = 'o';
    recursive_solver(maze, solve);

    // if (check_in_front(maze, solve, 'n')) {
    //     my_putstr("ok\n");
    // }


    my_show_word_array(maze);
    free_my_arr(maze);
    return 0;
}

int main (int ac, char **av)
{
    if (!gestion_erreure(ac, av))
        return 84;
    return solve_the_maze(av);
}

    // if (direction == 's') {
    //     if (solve->y + 1 < max_lignes && maze[solve->y + 1][solve->x] == '*')
    //         return 1;
    //     if (solve->x > 0 && maze[solve->y + 1][solve->x - 1] == '*')
    //         return 4;
    //     if (solve->x + 1 < max_cols && maze[solve->y][solve->x + 1] == '*')
    //         return 3;
    // } else if (direction == 'n') {
    //     if (solve->y > 0 && maze[solve->y - 1][solve->x] == '*')
    //         return 2;
    //     if (solve->x > 0 && maze[solve->y + 1][solve->x - 1] == '*')
    //         return 4;
    //     if (solve->x + 1 < max_cols && maze[solve->y][solve->x + 1] == '*')
    //         return 3;
    // }
    // if (direction == 'w') {
    //     if (solve->y + 1 < max_lignes && maze[solve->y + 1][solve->x] == '*')
    //         return 1;
    //     if (solve->y > 0 && maze[solve->y - 1][solve->x] == '*')
    //         return 2;
    //     if (solve->x + 1 < max_cols && maze[solve->y][solve->x + 1] == '*')
    //         return 3;
    // } else if (direction == 'e') {
    //     if (solve->y + 1 < max_lignes && maze[solve->y + 1][solve->x] == '*')
    //         return 1;
    //     if (solve->y > 0 && maze[solve->y - 1][solve->x] == '*')
    //         return 2;
    //     if (solve->x > 0 && maze[solve->y + 1][solve->x - 1] == '*')
    //         return 4;
    // }