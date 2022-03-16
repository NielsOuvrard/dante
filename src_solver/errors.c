/*
** EPITECH PROJECT, 2022
** src_solver
** File description:
** errors
*/

#include "solver.h"

int check_errors(int ac, char **av)
{
    if (open(av[1], O_RDONLY) < 0)
        return 84;
    if (is_a_file(av[1]) == 0)
        return (84);
    return 0;
}

int is_a_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}
