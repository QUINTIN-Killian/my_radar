/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** manage the planes hitboxes
** rect
*/

#include "include/my.h"
#include "include/my_radar.h"

void init_hitbox(linked_planes_t *node)
{
    node->plane_info->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(node->plane_info->hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(node->plane_info->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(node->plane_info->hitbox, sfGreen);
    sfRectangleShape_setOrigin(node->plane_info->hitbox, (sfVector2f){10, 10});
    sfRectangleShape_setOutlineThickness(node->plane_info->hitbox, 2);
    sfRectangleShape_setRotation(node->plane_info->hitbox, 90 -
    node->plane_info->rotation);
}

int is_intersecting_planes(linked_planes_t *node1, linked_planes_t *node2)
{
    float x = node1->plane_info->plane_pos.x - node2->plane_info->plane_pos.x;
    float y = node1->plane_info->plane_pos.y - node2->plane_info->plane_pos.y;

    if (x < 0.0)
        x *= -1.0;
    if (y < 0.0)
        y *= -1.0;
    if (x < 20.0 && y < 20.0)
        return 1;
    return 0;
}

void search_correspondances(linked_planes_t **head,
    linked_planes_t **under_head, linked_planes_t *node1, bool *del)
{
    linked_planes_t *node2 = node1->next;
    linked_planes_t *tmp;

    while (node2 != NULL) {
        if (is_intersecting_planes(node1, node2)) {
            *del = True;
            tmp = node2;
            node2 = node2->next;
            del_in_planes_list(head, tmp->plane_info->id);
            del_in_planes_list(under_head, tmp->plane_info->id);
        } else
            node2 = node2->next;
    }
}

void collision(linked_planes_t **head, linked_planes_t **under_head)
{
    linked_planes_t *node1 = *under_head;
    linked_planes_t *tmp = NULL;
    bool del = False;

    while (node1 != NULL) {
        search_correspondances(head, under_head, node1, &del);
        if (del) {
            del = False;
            tmp = node1;
            node1 = node1->next;
            del_in_planes_list(head, tmp->plane_info->id);
            del_in_planes_list(under_head, tmp->plane_info->id);
        } else
            node1 = node1->next;
    }
}

void explore_quad_tree(linked_planes_t **head, quad_tree_t *quad_tree)
{
    collision(head, quad_tree->top_left->under_planes_list);
    collision(head, quad_tree->top_right->under_planes_list);
    collision(head, quad_tree->bottom_left->under_planes_list);
    collision(head, quad_tree->bottom_right->under_planes_list);
}
