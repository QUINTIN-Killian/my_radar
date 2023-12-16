/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** manage the quad tree
** quad_tree
*/

#include "include/my.h"
#include "include/my_radar.h"

void del_in_quad_tree_aux(quad_tree_t *quad_tree)
{
    linked_planes_t *node;

    node = *(quad_tree->bottom_left->under_planes_list);
    while (node != NULL) {
        del_in_planes_list(quad_tree->bottom_left->under_planes_list,
        node->plane_info->id);
        node = *(quad_tree->bottom_left->under_planes_list);
    }
    node = *(quad_tree->bottom_right->under_planes_list);
    while (node != NULL) {
        del_in_planes_list(quad_tree->bottom_right->under_planes_list,
        node->plane_info->id);
        node = *(quad_tree->bottom_right->under_planes_list);
    }
}

void del_in_quad_tree(quad_tree_t *quad_tree)
{
    linked_planes_t *node;

    node = *(quad_tree->top_left->under_planes_list);
    while (node != NULL) {
        del_in_planes_list(quad_tree->top_left->under_planes_list,
        node->plane_info->id);
        node = *(quad_tree->top_left->under_planes_list);
    }
    node = *(quad_tree->top_right->under_planes_list);
    while (node != NULL) {
        del_in_planes_list(quad_tree->top_right->under_planes_list,
        node->plane_info->id);
        node = *(quad_tree->top_right->under_planes_list);
    }
    del_in_quad_tree_aux(quad_tree);
}

void put_in_quad_tree_aux(quad_tree_t *quad_tree,
    linked_planes_t *node)
{
    if (node->plane_info->plane_pos.x >= quad_tree->bottom_left->area.top &&
    node->plane_info->plane_pos.x <= quad_tree->bottom_left->area.width &&
    node->plane_info->plane_pos.y >= quad_tree->bottom_left->area.left &&
    node->plane_info->plane_pos.y <= quad_tree->bottom_left->area.height * 2) {
        add_in_planes_list(quad_tree->bottom_left->under_planes_list,
        cpy_plane_node(node), 0);
        return;
    }
    if (node->plane_info->plane_pos.x >= quad_tree->bottom_right->area.top &&
    node->plane_info->plane_pos.x <= quad_tree->bottom_right->area.width * 2 &&
    node->plane_info->plane_pos.y >= quad_tree->bottom_right->area.left &&
    node->plane_info->plane_pos.y <= quad_tree->bottom_right->area.height * 2){
        add_in_planes_list(quad_tree->bottom_right->under_planes_list,
        cpy_plane_node(node), 0);
        return;
    }
}

void put_in_quad_tree(quad_tree_t *quad_tree,
    linked_planes_t *node)
{
    if (node->plane_info->plane_pos.x >= quad_tree->top_left->area.top &&
    node->plane_info->plane_pos.x <= quad_tree->top_left->area.width &&
    node->plane_info->plane_pos.y >= quad_tree->top_left->area.left &&
    node->plane_info->plane_pos.y <= quad_tree->top_left->area.height) {
        add_in_planes_list(quad_tree->top_left->under_planes_list,
        cpy_plane_node(node), 0);
        return;
    }
    if (node->plane_info->plane_pos.x >= quad_tree->top_right->area.top &&
    node->plane_info->plane_pos.x <= quad_tree->top_right->area.width * 2 &&
    node->plane_info->plane_pos.y >= quad_tree->top_right->area.left &&
    node->plane_info->plane_pos.y <= quad_tree->top_right->area.height) {
        add_in_planes_list(quad_tree->top_right->under_planes_list,
        cpy_plane_node(node), 0);
        return;
    }
    put_in_quad_tree_aux(quad_tree, node);
}

static void init_corner(window_t *window, quad_tree_t *quad_tree)
{
    quad_tree->top_left->area.top = 0;
    quad_tree->top_left->area.left = 0;
    quad_tree->top_left->area.width = window->window_size.x / 2;
    quad_tree->top_left->area.height = window->window_size.y / 2;
    quad_tree->top_right->area.top = window->window_size.x / 2;
    quad_tree->top_right->area.left = 0;
    quad_tree->top_right->area.width = window->window_size.x / 2;
    quad_tree->top_right->area.height = window->window_size.y / 2;
    quad_tree->bottom_left->area.top = 0;
    quad_tree->bottom_left->area.left = window->window_size.y / 2;
    quad_tree->bottom_left->area.width = window->window_size.x / 2;
    quad_tree->bottom_left->area.height = window->window_size.y / 2;
    quad_tree->bottom_right->area.top = window->window_size.x / 2;
    quad_tree->bottom_right->area.left = window->window_size.y / 2;
    quad_tree->bottom_right->area.width = window->window_size.x / 2;
    quad_tree->bottom_right->area.height = window->window_size.y / 2;
}

static void init_quad_tree_aux(window_t *window, quad_tree_t *quad_tree)
{
    quad_tree->top_left->under_planes_list =
    malloc(sizeof(linked_planes_t *));
    (*quad_tree->top_left->under_planes_list) = NULL;
    quad_tree->top_left->nb_planes = 0;
    quad_tree->top_right->under_quad_tree = NULL;
    quad_tree->top_right->under_planes_list =
    malloc(sizeof(linked_planes_t *));
    (*quad_tree->top_right->under_planes_list) = NULL;
    quad_tree->top_right->nb_planes = 0;
    quad_tree->bottom_left->under_quad_tree = NULL;
    quad_tree->bottom_left->under_planes_list =
    malloc(sizeof(linked_planes_t *));
    (*quad_tree->bottom_left->under_planes_list) = NULL;
    quad_tree->bottom_left->nb_planes = 0;
    quad_tree->bottom_right->under_quad_tree = NULL;
    quad_tree->bottom_right->under_planes_list =
    malloc(sizeof(linked_planes_t *));
    (*quad_tree->bottom_right->under_planes_list) = NULL;
    quad_tree->bottom_right->nb_planes = 0;
    init_corner(window, quad_tree);
}

void init_quad_tree(window_t *window, quad_tree_t *quad_tree)
{
    quad_tree->top_left = malloc(sizeof(corner_t));
    quad_tree->top_right = malloc(sizeof(corner_t));
    quad_tree->bottom_left = malloc(sizeof(corner_t));
    quad_tree->bottom_right = malloc(sizeof(corner_t));
    quad_tree->top_left->under_quad_tree = NULL;
    init_quad_tree_aux(window, quad_tree);
}
