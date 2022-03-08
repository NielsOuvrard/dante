/*
** EPITECH PROJECT, 2022
** linked list
** File description:
** linked list
*/

#include "my.h"
#include "gen_sol_header.h"

// void my_put_in_list_head (head_node_binary **head, node_binary *body)
// {
//     head_node_binary *element;
//     element = malloc(sizeof(head_node_binary));
//     element->node = body;
//     element->next = *head;
//     *head = element;
// }

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
    // element->prev = prev;
    if (prev == 'n') {
        element->prev = 's';
        list->north = element;
    } else if (prev == 's') {
        element->prev = 'n';
        list->south = element;
    }
    if (prev == 'e') {
        element->prev = 'w';
        list->east = element;
    } else if (prev == 'w') {
        element->prev = 'e';
        list->west = element;
    }
    // if (value == 1)
    //     list->left = element;
    // else if (value == 2)
    //     list->up = element;
    // else
    //     list->right = element;
    return (0);
}

int free_linked_list_tt (three_tree *list)
{
    if (list->east) {
        three_tree *tmp = list->east;
        free(list);
        return free_linked_list_tt(tmp);
    }
    if (list->west) {
        three_tree *tmp = list->west;
        free(list);
        return free_linked_list_tt(tmp);
    }
    if (list->north) {
        three_tree *tmp = list->north;
        free(list);
        return free_linked_list_tt(tmp);
    }
    if (list->south) {
        three_tree *tmp = list->south;
        free(list);
        return free_linked_list_tt(tmp);
    }
    return 0;
}

// void disp_head_list (three_tree *head)
// {
//     while (head) {
//         my_putstr("value : ");
//         if (head->node->type == 0) {
//             my_putchar(head->node->right->value);
//             my_putchar('|');
//             my_putchar(head->node->left->value);
//         }
//         my_putchar(head->node->value);
//         my_putstr("\tocc : ");
//         my_putint(head->node->occ);
//         my_putstr(" \tleft : ");
//         my_putint(head->node->left != NULL ? head->node->left->occ : 0);
//         my_putstr("\tright : ");
//         my_putint(head->node->right != NULL  ? head->node->right->occ : 0);
//         my_putchar('\n');
//         head = head->next;
//     }
// }

// int disp_linked_list_tt (three_tree *list)
// {
//     while (list != NULL) {
//         my_putstr("value : ");
//         if (list->value != '\n')
//             my_putchar(list->value);
//         else
//             my_putstr("\\n");
//         my_putstr("\tocc : ");
//         my_putint(list->occ);
//         my_putchar('\n');
//         list = list->next;
//     }
//     return 1;
// }
