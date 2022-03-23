/*
** EPITECH PROJECT, 2022
** linked list
** File description:
** linked list
*/

#include "my.h"
#include "gen_sol_header.h"

three_tree *my_put_in_list_next (three_tree *list, three_tree *element,
char suiv)
{
    if (suiv == 'e') {
        element->prev = 'w';
        element->east = list;
    } else if (suiv == 'w') {
        element->prev = 'e';
        element->west = list;
    }
    return element;
}

three_tree *my_put_in_list (three_tree *list, int x, int y, char suiv)
{
    three_tree *element;
    element = malloc(sizeof(three_tree));
    element->x = x;
    element->y = y;
    element->north = NULL;
    element->south = NULL;
    element->east = NULL;
    element->west = NULL;
    if (suiv == 'n') {
        element->prev = 's';
        element->north = list;
    } else if (suiv == 's') {
        element->prev = 'n';
        element->south = list;
    } else {
        element = my_put_in_list_next(list, element, suiv);
    }
    list = element;
    return element;
}

void my_put_end_list_next (three_tree *list, three_tree *element, char prev)
{
    if (prev == 'e') {
        element->prev = 'w';
        element->west = list;
        list->east = element;
    } else if (prev == 'w') {
        element->prev = 'e';
        element->east = list;
        list->west = element;
    }
}

int my_put_end_list (three_tree *list, int x, int y, char prev)
{
    three_tree *element;
    element = malloc(sizeof(three_tree));
    element->x = x;
    element->y = y;
    element->north = NULL;
    element->south = NULL;
    element->east = NULL;
    element->west = NULL;
    if (prev == 'n') {
        element->prev = 's';
        element->south = list;
        list->north = element;
    } else if (prev == 's') {
        element->prev = 'n';
        element->north = list;
        list->south = element;
    } else {
        my_put_end_list_next(list, element, prev);
    }
    return (0);
}

int free_linked_list_tt (three_tree *list)
{
    if (list->east) {
        list->east->west = NULL;
        free_linked_list_tt(list->east);
    }
    if (list->west) {
        list->west->east = NULL;
        free_linked_list_tt(list->west);
    }
    if (list->north) {
        list->north->south = NULL;
        free_linked_list_tt(list->north);
    }
    if (list->south) {
        list->south->north = NULL;
        free_linked_list_tt(list->south);
    }
    free(list);
    return 0;
}
