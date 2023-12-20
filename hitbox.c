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
    sfRectangleShape_setOrigin(node->plane_info->hitbox, (sfVector2f)
    {sfTexture_getSize(node->plane_info->plane_texture).x / 2 * 0.070,
    sfTexture_getSize(node->plane_info->plane_texture).y / 2 * 0.075});
    sfRectangleShape_setOutlineThickness(node->plane_info->hitbox, 2);
    sfRectangleShape_setRotation(node->plane_info->hitbox, 90 -
    node->plane_info->rotation);
}

int is_intersecting_planes(linked_planes_t *node1, linked_planes_t *node2)
{
    float x;
    float y;

    if (node1 == NULL || node2 == NULL)
        return -1;
    x = node1->plane_info->plane_pos.x - node2->plane_info->plane_pos.x;
    y = node1->plane_info->plane_pos.y - node2->plane_info->plane_pos.y;
    if (x < 0.0)
        x *= -1.0;
    if (y < 0.0)
        y *= -1.0;
    if (x < 20.0 && y < 20.0)
        return 1;
    return 0;
}

int check_intersecting_planes(linked_planes_t **head,
    linked_planes_t **head_under_list, linked_planes_t *node1,
    linked_planes_t *node2)
{
    if (is_intersecting_planes(node1, node2) == 1) {
        del_in_planes_list(head, node1->plane_info->id);
        del_in_planes_list(head, node2->plane_info->id);
        if (*head_under_list == NULL || (*head_under_list)->next == NULL) {
            node1 = *head_under_list;
            node2 = node1->next;
            return check_intersecting_planes(head, head_under_list,
            node1, node2);
        } else
            return 0;
    } else if (is_intersecting_planes(node1, node2) == 0) {
        node2 = node2->next;
        return check_intersecting_planes(head, head_under_list, node1, node2);
    } else
        return 0;
}

void call_checking_collision(linked_planes_t **head,
    linked_planes_t **head_under_list)
{
    linked_planes_t *node1 = *head_under_list;
    linked_planes_t *node2 = NULL;

    if (node1 != NULL)
        node2 = node1->next;
    check_intersecting_planes(head, head_under_list, node1, node2);
}

void del_collision_planes(linked_planes_t **head, quad_tree_t *quad_tree)
{
    call_checking_collision(head, quad_tree->top_left->under_planes_list);
    call_checking_collision(head, quad_tree->top_right->under_planes_list);
    call_checking_collision(head, quad_tree->bottom_left->under_planes_list);
    call_checking_collision(head, quad_tree->bottom_right->under_planes_list);
}
