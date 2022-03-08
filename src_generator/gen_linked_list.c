/*
** EPITECH PROJECT, 2022
** linked list
** File description:
** linked list
*/

#include "my.h"
#include "gen_sol_header.h"

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
    }
    if (suiv == 'e') {
        element->prev = 'w';
        element->east = list;
    } else if (suiv == 'w') {
        element->prev = 'e';
        element->west = list;
    }
    list = element;
    return element;
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
    }
    if (prev == 'e') {
        element->prev = 'w';
        element->west = list;
        list->east = element;
    } else if (prev == 'w') {
        element->prev = 'e';
        element->east = list;
        list->west = element;
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


// int free_linked_list_tt (three_tree *list)
// {
//     if (list->east) {
//         three_tree *tmp = list->east;
//         free(list);
//         return free_linked_list_tt(tmp);
//     }
//     if (list->west) {
//         three_tree *tmp = list->west;
//         free(list);
//         return free_linked_list_tt(tmp);
//     }
//     if (list->north) {
//         three_tree *tmp = list->north;
//         free(list);
//         return free_linked_list_tt(tmp);
//     }
//     if (list->south) {
//         three_tree *tmp = list->south;
//         free(list);
//         return free_linked_list_tt(tmp);
//     }
//     return 0;
// }
