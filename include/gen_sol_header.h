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
    int x;
    int y;
    struct three_tree *left;
    struct three_tree *up;
    struct three_tree *right;
} three_tree;

char **filepath_to_arr (char *filepath);

// tools

int random_int (int min, int max);

int gestion_erreur (int ac, char **av);
