/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** duplicate planes in other quad trees if they enter the range of
** other quad trees
** move_in_quad_tree
*/

#include "include/my.h"
#include "include/my_radar.h"

static void in_top_left(linked_planes_t *node, quad_tree_t *quad_tree,
    float x, float y)
{
    if (x < 10.0)
        add_in_planes_list(quad_tree->top_right->under_planes_list,
        cpy_plane_node(node), 0);
    if (y < 10.0)
        add_in_planes_list(quad_tree->bottom_left->under_planes_list,
        cpy_plane_node(node), 0);
}

static void in_top_right(linked_planes_t *node, quad_tree_t *quad_tree,
    float x, float y)
{
    if (x > -10.0)
        add_in_planes_list(quad_tree->top_left->under_planes_list,
        cpy_plane_node(node), 0);
    if (y < 10.0)
        add_in_planes_list(quad_tree->bottom_right->under_planes_list,
        cpy_plane_node(node), 0);
}

static void in_bottom_left(linked_planes_t *node, quad_tree_t *quad_tree,
    float x, float y)
{
    if (x < 10.0)
        add_in_planes_list(quad_tree->bottom_right->under_planes_list,
        cpy_plane_node(node), 0);
    if (y > -10.0)
        add_in_planes_list(quad_tree->top_left->under_planes_list,
        cpy_plane_node(node), 0);
}

static void in_bottom_right(linked_planes_t *node, quad_tree_t *quad_tree,
    float x, float y)
{
    if (x > -10.0)
        add_in_planes_list(quad_tree->bottom_left->under_planes_list,
        cpy_plane_node(node), 0);
    if (y > -10.0)
        add_in_planes_list(quad_tree->top_right->under_planes_list,
        cpy_plane_node(node), 0);
}

static void in_center(linked_planes_t *node, quad_tree_t *quad_tree)
{
    add_in_planes_list(quad_tree->top_left->under_planes_list,
    cpy_plane_node(node), 0);
    add_in_planes_list(quad_tree->top_right->under_planes_list,
    cpy_plane_node(node), 0);
    add_in_planes_list(quad_tree->bottom_left->under_planes_list,
    cpy_plane_node(node), 0);
    add_in_planes_list(quad_tree->bottom_right->under_planes_list,
    cpy_plane_node(node), 0);
}

void move_in_quad_tree_aux(linked_planes_t *node,
    quad_tree_t *quad_tree, float x, float y)
{
    if (x < 10.0 && x > -10.0 && y < 10.0 && y > -10.0) {
        in_center(node, quad_tree);
        return;
    }
    if (x >= 0.0 && y >= 0.0) {
        in_top_left(node, quad_tree, x, y);
        return;
    }
    if (x < 0.0 && y >= 0.0) {
        in_top_right(node, quad_tree, x, y);
        return;
    }
    if (x >= 0.0 && y < 0.0) {
        in_bottom_left(node, quad_tree, x, y);
        return;
    }
    if (x < 0.0 && y < 0.0) {
        in_bottom_right(node, quad_tree, x, y);
        return;
    }
}

void move_in_quad_tree(linked_planes_t **planes_list, quad_tree_t *quad_tree)
{
    linked_planes_t *node = *planes_list;
    float x;
    float y;

    while (node != NULL) {
        x = 960.0 - node->plane_info->plane_pos.x;
        y = 540.0 - node->plane_info->plane_pos.y;
        move_in_quad_tree_aux(node, quad_tree, x, y);
        node = node->next;
    }
}
