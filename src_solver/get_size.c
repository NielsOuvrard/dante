/*
** EPITECH PROJECT, 2022
** Astar2
** File description:
** get_size
*/

#include "my.h"

int get_size(char *path)
{
    struct stat buffer;
    stat(path, &buffer);
    return buffer.st_size;
}