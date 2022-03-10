/*
** EPITECH PROJECT, 2022
** linked list
** File description:
** linked list
*/

#include "my.h"
#include "gen_sol_header.h"

list_solve *my_put_in_solve (list_solve *list, int x, int y)
{
    list_solve *element = malloc(sizeof(list_solve));
    element->x = x;
    element->y = y;
    element->next = list;
    element->prev = NULL;
    // list->prev = element;
    list = element;
    return element;
}

int my_put_end_solve (list_solve *list, int x, int y, char dir)
{
    list_solve *element;
    element = malloc(sizeof(list_solve));
    element->x = x;
    element->y = y;
    element->dir = dir;
    element->next = NULL;
    element->prev = list;
    list->next = element;
    return (0);
}

int free_linked_list_solve (list_solve *list)
{
    if (list->next) {
        list->next->prev = NULL;
        free_linked_list_solve(list->next);
    }
    if (list->prev) {
        list->prev->next = NULL;
        free_linked_list_solve(list->prev);
    }
    free(list);
    return 0;
}
