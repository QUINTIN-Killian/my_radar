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

static bool is_in_range_tower(linked_towers_t **towers_list,
    linked_planes_t *node)
{
    linked_towers_t *tower = *towers_list;

    while (tower != NULL) {
        if (powf(tower->tower_pos.x - node->plane_info->plane_pos.x, 2.0) +
        powf(tower->tower_pos.y - node->plane_info->plane_pos.y, 2.0) <=
        powf(tower->radius + 10.0, 2.0))
            return True;
        tower = tower->next;
    }
    return False;
}

static bool is_intersecting_planes(linked_planes_t *node1,
    linked_planes_t *node2)
{
    float x = node1->plane_info->plane_pos.x - node2->plane_info->plane_pos.x;
    float y = node1->plane_info->plane_pos.y - node2->plane_info->plane_pos.y;

    if (x < 0.0)
        x *= -1.0;
    if (y < 0.0)
        y *= -1.0;
    if (x < 20.0 && y < 20.0)
        return True;
    return False;
}

bool search_correspondances(linked_planes_t **planes_list,
    linked_towers_t **towers_list, linked_planes_t *node1)
{
    linked_planes_t *node2 = node1->next;
    linked_planes_t *tmp;
    bool node1_in_range_tower = is_in_range_tower(towers_list, node1);
    bool ans = False;

    while (node2 != NULL) {
        if (node1->plane_info->id != node2->plane_info->id &&
        is_intersecting_planes(node1, node2) && (!node1_in_range_tower ||
        !is_in_range_tower(towers_list, node2))) {
            ans = True;
            tmp = node2;
            node2 = node2->next;
            del_in_planes_list(planes_list, tmp->plane_info->id);
        } else
            node2 = node2->next;
    }
    return ans;
}

void collision(linked_planes_t **planes_list, linked_towers_t **towers_list,
    linked_planes_t **under_head)
{
    linked_planes_t *node1 = *under_head;
    linked_planes_t *tmp = NULL;
    bool del = False;

    while (node1 != NULL) {
        del = search_correspondances(planes_list, towers_list, node1);
        if (del) {
            del = False;
            tmp = node1;
            node1 = node1->next;
            del_in_planes_list(planes_list, tmp->plane_info->id);
        } else
            node1 = node1->next;
    }
}

void explore_quad_tree(linked_planes_t **planes_list,
    linked_towers_t **towers_list, quad_tree_t *quad_tree)
{
    collision(planes_list, towers_list,
    quad_tree->top_left->under_planes_list);
    collision(planes_list, towers_list,
    quad_tree->top_right->under_planes_list);
    collision(planes_list, towers_list,
    quad_tree->bottom_left->under_planes_list);
    collision(planes_list, towers_list,
    quad_tree->bottom_right->under_planes_list);
}
