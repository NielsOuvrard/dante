/*
** EPITECH PROJECT, 2022
** a_star
** File description:
** my
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef MY_H_
    #define MY_H_

struct node {
    int g_cost;
    int f_cost;
    int h_cost;
    int visited;
    struct node *parent;
} typedef t_node;

struct open {
    int x;
    int y;
    struct open *next;
} typedef t_open;

struct par {
    t_node **nodes;
    t_open *open;
    char *map;
    char **arr;
    int arr_len;
    int str_len;
    int end_x;
    int end_y;
    int current_x;
    int current_y;
} typedef t_par;

int get_lines_str(char *str);
char *get_map(char *path);
int get_line_lenght(char *map, int pos);
char **map_to_arr(char *map);
int my_arrlen(char **arr);
int my_strlen (char const *str);
int get_size(char *path);
void get_endpos(t_par *par);
void malloc_list(t_par *par);
void get_hcost(t_par *par, int x, int y);
void get_gcost(t_par *par, int x, int y);
void get_fcosts(t_par *par, int x, int y);
void add_toopen(t_open *open, int x, int y);
int is_inopen(t_par *par, int x, int y);
int is_accessible(t_par *par, int x, int y);
int get_pos(t_par *par, int x, int y);
void remove_open(t_par *par, int x, int y);
void discover_node(t_par *par, int x, int y, t_node *parent);
void check_cost(t_par *par, t_node *parent, int x, int y);
void check_right(int x, int y, t_par *par);
void check_left(int x, int y, t_par *par);
void check_up(int x, int y, t_par *par);
void check_down(int x, int y, t_par *par);
void check_allsquares(t_par *par, int x, int y);
void pick_square(t_par *par);
void astar(t_par *par);
#endif /* !MY_H_ */
