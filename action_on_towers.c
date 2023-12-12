/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** apply action on the towers list
** action_on_list
*/

#include "include/my.h"
#include "include/my_radar.h"

int my_towers_list_len(linked_towers_t **towers_list)
{
    linked_towers_t **head = towers_list;
    linked_towers_t *tmp = *head;
    int ans = 0;

    while (tmp != NULL) {
        ans++;
        tmp = tmp->next;
    }
    return ans;
}

void disp_towers_list(linked_towers_t **towers_list)
{
    linked_towers_t **head = towers_list;
    linked_towers_t *tmp = *head;

    if (tmp == NULL)
        my_putstr("NULL\n");
    while (tmp != NULL) {
        my_putstr("TOWER\nId : ");
        my_put_nbr(tmp->id);
        my_putstr("\nCoordinates : ");
        my_put_nbr(tmp->tower_pos.x);
        my_putstr(", ");
        my_put_nbr(tmp->tower_pos.y);
        my_putstr("\nRadius : ");
        my_put_nbr(tmp->radius);
        my_putstr("\n\n");
        tmp = tmp->next;
    }
}

static linked_towers_t *del_first_node(linked_towers_t *current,
    linked_towers_t *tmp)
{
    tmp = current;
    current = current->next;
    free(tmp);
    return current;
}

static linked_towers_t *del_node(linked_towers_t **head, int id_del)
{
    linked_towers_t *current = *head;
    linked_towers_t *tmp = NULL;

    if (current == NULL)
        return current;
    if (current->id == id_del)
        return del_first_node(current, tmp);
    while (current->next != NULL) {
        if (current->next->id == id_del) {
            tmp = current->next;
            current->next = current->next->next;
            free(tmp);
            return *head;
        }
        current = current->next;
    }
    return *head;
}

void del_in_towers_list(linked_towers_t **towers_list, int id_del)
{
    linked_towers_t **head = towers_list;

    *head = del_node(head, id_del);
    towers_list = head;
}

void add_in_towers_list(linked_towers_t **towers_list,
    linked_towers_t *new_node)
{
    linked_towers_t **head = towers_list;

    new_node->next = *head;
    *head = new_node;
    towers_list = head;
}
