/*
** EPITECH PROJECT, 2022
** B-PSU-200-MAR-2-1-mysokoban-adam.elaoumari
** File description:
** open_map
*/

#include "my.h"

int get_lines_str(char *str)
{
    int i = 0;
    int nb = 0;
    while (str[i] != '\0') {
        if (str[i] == 10)
            nb++;
        i++;
    }
    nb++;
    return nb;
}

char *get_map(char *path)
{
    char *map = malloc(sizeof(char) * get_size(path) + 1);
    int fd = open(path, O_RDONLY);
    read(fd, map, get_size(path));
    map[get_size(path)] = '\0';
    close(fd);
    return map;
}

int get_line_lenght(char *map, int pos)
{
    int i = pos;
    while (map[i] != '\0') {
        if (map[i] == '\n')
            return i;
        i++;
    }
    return i;
}

char **map_to_arr(char *map)
{
    int j = 0;
    int k = 0;
    int z = 0;
    int y = 0;
    char **arr = malloc(sizeof(char *) * (get_lines_str(map) + 1));
    for (int i = get_lines_str(map); i != 0 ; i--) {
        arr[j] = malloc(sizeof(char) * 1000);
        j++;
    }
    for (int l = get_lines_str(map); l != 0 && map[k] != '\0'; l--) {
        for (int kk = get_line_lenght(map, k); k != kk; k++) {
            arr[y][z] = map[k];
            z++;
        }
        arr[y][z] = '\0';
        k++;
        z = 0;
        y++;
    }
    arr[y] = NULL;
    return arr;
}