/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** apply action on the planes list
** action_on_list
*/

#include "include/my.h"
#include "include/my_radar.h"

int my_planes_list_len(linked_planes_t **planes_list)
{
    linked_planes_t **head = planes_list;
    linked_planes_t *tmp = *head;
    int ans = 0;

    while (tmp != NULL) {
        ans++;
        tmp = tmp->next;
    }
    return ans;
}

static void disp_planes_list_aux(linked_planes_t *tmp)
{
    my_putstr("PLANE\nId : ");
    my_put_nbr(tmp->plane_info->id);
    my_putstr("\nDeparture coordinates : ");
    my_put_nbr(tmp->plane_info->departure_coords.x);
    my_putstr(", ");
    my_put_nbr(tmp->plane_info->departure_coords.y);
    my_putstr("\nArrival coordinates : ");
    my_put_nbr(tmp->plane_info->arrival_coords.x);
    my_putstr(", ");
    my_put_nbr(tmp->plane_info->arrival_coords.y);
    my_putstr("\nSpeed : ");
    my_put_nbr(tmp->plane_info->speed);
    my_putstr("\nDelay : ");
    my_put_nbr(tmp->plane_info->delay);
    my_putstr("\n\n");
}

void disp_planes_list(linked_planes_t **planes_list)
{
    linked_planes_t **head = planes_list;
    linked_planes_t *tmp = *head;

    if (tmp == NULL)
        my_putstr("NULL\n");
    while (tmp != NULL) {
        disp_planes_list_aux(tmp);
        tmp = tmp->next;
    }
}

static void free_node(linked_planes_t *node)
{
    free(node->plane_info);
    free(node);
}

static linked_planes_t *del_first_node(linked_planes_t *current,
    linked_planes_t *tmp)
{
    tmp = current;
    current = current->next;
    free_node(tmp);
    return current;
}

static linked_planes_t *del_node(linked_planes_t **head, int id_del)
{
    linked_planes_t *current = *head;
    linked_planes_t *tmp = NULL;

    if (current == NULL)
        return current;
    if (current->plane_info->id == id_del)
        return del_first_node(current, tmp);
    while (current->next != NULL) {
        if (current->next->plane_info->id == id_del) {
            tmp = current->next;
            current->next = current->next->next;
            free_node(tmp);
            return *head;
        }
        current = current->next;
    }
    return *head;
}

void del_in_planes_list(linked_planes_t **planes_list, int id_del)
{
    linked_planes_t **head = planes_list;

    *head = del_node(head, id_del);
    planes_list = head;
}

void add_in_planes_list(linked_planes_t **planes_list,
    linked_planes_t *new_node)
{
    linked_planes_t **head = planes_list;

    new_node->next = *head;
    *head = new_node;
    planes_list = head;
}
