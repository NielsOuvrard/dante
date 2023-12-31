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

typedef struct sfVector2i {
    int x;
    int y;
} sfVector2i;

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

// * ///////////////////////// GENERATOR

// tools

int random_int (int min, int max);

int gestion_erreur (int ac, char **av);

void random_dig(char **maze, int i, int size_x, int size_y);

int lignes_solo (int lignes, int cols);

// linked list tt

three_tree *my_put_in_list (three_tree *list, int x, int y, char suiv);

int my_put_end_list (three_tree *list, int x, int y, char prev);

int free_linked_list_tt (three_tree *list);

// recursive dig

three_tree *test_test (char **maze, three_tree *three, sfVector2i infos);

// recursive dig2

three_tree *recursive_dig (char **maze, three_tree *three, sfVector2i infos);

// ok to dig next

int is_okay_to_dig_n (char **maze, three_tree *three, sfVector2i infos);

int is_okay_to_dig_s (char **maze, three_tree *three, sfVector2i infos);

// ok to dig

int is_okay_to_dig (char **maze, three_tree *three, char direction,
sfVector2i infos);

three_tree *looking_for_new_way (char **maze, three_tree *three,
sfVector2i infos);

/// nsew dir

three_tree *retry (char **maze, three_tree *three, sfVector2i infos);

three_tree *north_dir (char **maze, three_tree *three, sfVector2i infos);

three_tree *east_dir (char **maze, three_tree *three, sfVector2i infos);

three_tree *south_dir (char **maze, three_tree *three, sfVector2i infos);

three_tree *west_dir (char **maze, three_tree *three, sfVector2i infos);
