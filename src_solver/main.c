/*
** EPITECH PROJECT, 2022
** a_star
** File description:
** main
*/

#include "my.h"

int main (int ac, char **av)
{
    t_par *par = malloc(sizeof(t_par));
    par->open = NULL;
    par->map = get_map("map.txt");
    par->arr = map_to_arr(par->map);
    par->arr_len = my_arrlen(par->arr);
    par->str_len = my_strlen(par->arr[0]);
    get_endpos(par);
    malloc_list(par);
    par->current_x = 0;
    par->current_y = 0;
    par->nodes[0][0].g_cost = 0;
    par->nodes[0][0].parent = NULL;
    check_allsquares(par, 0, 0);
    par->nodes[0][0].visited = 1;
    remove_open(par, 0, 0);
    par->arr[par->current_y][par->current_x] = 'O';
    astar(par);
}

void astar(t_par *par)
{
    int i = 0;
    check_allsquares(par, par->current_x, par->current_y);
    //printf("Current x : %d Current y : %d\n", par->current_x, par->current_y);
    while (1) {
        if (par->current_x == 4 && par->current_y == 3) {
            i = 0;
            while (par->arr[i] != NULL) {
                printf(par->arr[i]);
                printf("%c", '\n');
                i++;
            }
            exit(11);
        }
        par->nodes[0][0].visited = 1;
        pick_square(par);
        check_allsquares(par, par->current_x, par->current_y);
        par->arr[par->current_y][par->current_x] = 'O';
        printf("Current x : %d Current y : %d\n", par->current_x, par->current_y);
        i++;
    }
    i = 0;
    while (par->arr[i] != NULL) {

        printf(par->arr[i]);
        printf("%c", '\n');
        i++;
    }
}