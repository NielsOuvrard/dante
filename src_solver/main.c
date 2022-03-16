/*
** EPITECH PROJECT, 2022
** a_star
** File description:
** main
*/

#include "solver.h"

void astar(t_par *par)
{
    int i = 0;
    while (list_len(par)) {
        if (par->current_x == par->end_x - 1
        && par->current_y == par->end_y - 1) {
            i = 0;
            write_tomap(par);
            print_arr(par);
            exit(11);
        }
        pick_square(par);
        check_allsquares(par, par->current_x, par->current_y);
        i++;
    }
    printf("no solution found");
    exit (0);
}

t_par *initialise_struct_par (int ac, char **av)
{
    t_par *par = malloc(sizeof(t_par));
    par->open = NULL;
    par->map = get_map(av[1]);
    par->arr = map_to_arr(par->map);
    par->arr_len = my_arrlen(par->arr);
    par->str_len = my_strlen(par->arr[0]);
    get_endpos(par);
    malloc_list(par);
    par->current_x = 0;
    par->current_y = 0;
    par->nodes[0][0].g_cost = 0;
    par->nodes[0][0].x = 0;
    par->nodes[0][0].y = 0;
    par->nodes[0][0].parent = NULL;
    check_allsquares(par, 0, 0);
    remove_open(par, 0, 0);
    return par;
}

int main (int ac, char **av)
{
    if (ac > 2)
        return 84;
    if (check_errors(ac, av) != 0)
        return 84;
    t_par *par = initialise_struct_par(ac, av);
    astar(par);
    return 0;
}
