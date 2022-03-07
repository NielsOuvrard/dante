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

int my_put_in_list (three_tree **list, int x, int y)
{
    three_tree *element;
    element = malloc(sizeof(three_tree));
    element->x = x;
    element->y = y;
    element->left = NULL;
    element->up = NULL;
    element->right = NULL;
    *list = element;
    return (0);
}

int free_linked_list_tt (three_tree *list)
{
    if (list->left)
        return free_linked_list_tt(list->left);
    if (list->up)
        return free_linked_list_tt(list->up);
    if (list->right)
        return free_linked_list_tt(list->right);
    three_tree *tmp = list;
    list = list->up;
    free(list);
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
