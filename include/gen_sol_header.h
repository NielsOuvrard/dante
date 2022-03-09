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

typedef struct list_solve {
    int x;
    int y;
    char dir;
    struct list_solve* next;
    struct list_solve* prev;
} list_solve;

// * ///////////////////////// SOLVER

char **filepath_to_arr (char *filepath);

list_solve *my_put_in_solve (list_solve *list, int x, int y);

int my_put_end_solve (list_solve *list, int x, int y, char dir);

int free_linked_list_solve (list_solve *list);

// * ///////////////////////// GENERATOR

// tools

int random_int (int min, int max);

int gestion_erreur (int ac, char **av);

// linked list tt

three_tree *my_put_in_list (three_tree *list, int x, int y, char suiv);

int my_put_end_list (three_tree *list, int x, int y, char prev);

int free_linked_list_tt (three_tree *list);

// recursive

three_tree *recursive_dig (char **maze, three_tree *three);
