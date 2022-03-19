/*
** EPITECH PROJECT, 2022
** B-PSU-200-MAR-2-1-mysokoban-adam.elaoumari
** File description:
** open_map
*/

#include "solver.h"

int get_lines_str(char *str)
{
    int i = 0;
    int nb = 0;
    while (str[i] != '\0') {
        if (str[i] == 10 && str[i - 1] != '\n')
            nb++;
        i++;
    }
    return nb;
}

char *get_map(char *path)
{
    char *map = malloc(sizeof(char) * (get_size(path) + 2));
    int fd = open(path, O_RDONLY);
    read(fd, map, get_size(path));
    map[get_size(path)] = '\n';
    map[get_size(path) + 1] = '\0';
    close(fd);
    return map;
}

int get_line_lenght(char *map)
{
    int i = 0;
    while (map[i] != '\0') {
        if (map[i] == '\n')
            return i;
        i++;
    }
    return i;
}

char **map_to_arr(char *map)
{
    int move = 0, l = 0, line_str = get_lines_str(map);
    int j = 0, k = 0, z = 0, y = 0, end = my_strlen(map);
    char **arr = malloc(sizeof(char *) * (line_str + 1));
    for (int i = get_lines_str(map); i != 0 ; i--) {
        arr[j] = malloc(sizeof(char) * (get_line_lenght(map) + 2));
        j++;
    }
    for (l = 0 ; l != line_str && move != end; l++) {
        for (int i = move; map[i] != '\0' && map[i] != '\n' ; i++) {
            arr[l][y] = map[i];
            move++;
            y++;
        }
        arr[l][y] = '\0';
        y = 0;
        move++;
    }
    arr[l] = NULL;
    return arr;
}
