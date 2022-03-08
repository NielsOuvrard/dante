/*
** EPITECH PROJECT, 2022
** sol_main.c
** File description:
** sol_main.c
*/

#include "my.h"
#include "gen_sol_header.h"

int main (int ac, char **av)
{
    char **maze = filepath_to_arr(av[1]);
    my_show_word_array(maze);
    free_my_arr(maze);
    return 0;
}
