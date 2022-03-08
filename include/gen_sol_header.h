/*
** EPITECH PROJECT, 2021
** header du my snake
** File description:
** bcp de definitions
*/
#pragma once

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>

typedef struct three_tree {
    char prev;
    int x;
    int y;
    struct three_tree *north;
    struct three_tree *south;
    struct three_tree *east;
    struct three_tree *west;
} three_tree;

char **filepath_to_arr (char *filepath);

// tools

int random_int (int min, int max);

int gestion_erreur (int ac, char **av);

// linked list tt

three_tree *my_put_in_list (three_tree *list, int x, int y, char suiv);

int my_put_end_list (three_tree *list, int x, int y, char prev);

int free_linked_list_tt (three_tree *list);

// recursive

three_tree *recursive_dig (char **maze, three_tree *three);
