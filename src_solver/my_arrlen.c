/*
** EPITECH PROJECT, 2022
** Astar2
** File description:
** my_arrlen
*/

#include "my.h"

int my_arrlen(char **arr)
{
    int i = 0;
    while (arr[i] != NULL) {
        i++;
    }
    return i;
}