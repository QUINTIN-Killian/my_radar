/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** main screen of the simulation
** main_screen
*/

#include "include/my.h"
#include "include/my_radar.h"

static void destroy_main_screen(quad_tree_t *quad_tree)
{
    free(quad_tree->top_left->under_planes_list);
    free(quad_tree->top_right->under_planes_list);
    free(quad_tree->bottom_left->under_planes_list);
    free(quad_tree->bottom_right->under_planes_list);
    free(quad_tree->top_left);
    free(quad_tree->top_right);
    free(quad_tree->bottom_left);
    free(quad_tree->bottom_right);
}

static void teleport_plane(window_t *window, linked_planes_t *node)
{
    if (node->plane_info->plane_pos.x > window->window_size.x)
        node->plane_info->plane_pos.x = 0;
    if (node->plane_info->plane_pos.x < 0)
        node->plane_info->plane_pos.x = window->window_size.x;
    if (node->plane_info->plane_pos.y > window->window_size.y)
        node->plane_info->plane_pos.y = 0;
    if (node->plane_info->plane_pos.y < 0)
        node->plane_info->plane_pos.y = window->window_size.y;
}

static linked_planes_t *change_plane_pos(window_t *window,
    linked_planes_t *node, linked_planes_t **planes_list)
{
    linked_planes_t *tmp = node->next;

    if ((int)sfTime_asSeconds(sfClock_getElapsedTime(window->timer->clock))
    >= node->plane_info->delay && node->plane_info->speed != 0) {
        node->plane_info->plane_pos.x += ((node->plane_info->arrival_coords.x -
        node->plane_info->departure_coords.x) / node->plane_info->hypothenuse)
        * node->plane_info->speed;
        node->plane_info->plane_pos.y += ((node->plane_info->arrival_coords.y -
        node->plane_info->departure_coords.y) / node->plane_info->hypothenuse)
        * node->plane_info->speed;
        teleport_plane(window, node);
        sfSprite_setPosition(node->plane_info->plane_sprite,
        node->plane_info->plane_pos);
        if (is_arrived(node)) {
            window->arrived_planes++;
            del_in_planes_list(planes_list, node->plane_info->id);
        }
    }
    return tmp;
}

static void move_planes(window_t *window, linked_planes_t **planes_list)
{
    linked_planes_t *node = *planes_list;
    sfTime time = sfClock_getElapsedTime(window->plane_clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.05) {
        sfClock_restart(window->plane_clock);
        while (node != NULL) {
            node = change_plane_pos(window, node, planes_list);
        }
    }
}

void main_screen(window_t *window, linked_planes_t **planes_list,
    linked_towers_t **towers_list)
{
    quad_tree_t quad_tree;

    init_quad_tree(window, &quad_tree);
    while (sfRenderWindow_isOpen(window->window_info) &&
    my_planes_list_len(planes_list) > 0) {
        sfRenderWindow_clear(window->window_info, sfWhite);
        display_fonctions(window, planes_list, towers_list, &quad_tree);
        move_planes(window, planes_list);
        explore_quad_tree(planes_list, towers_list, &quad_tree);
        del_in_quad_tree(&quad_tree);
        get_event(window);
        end(window, planes_list);
        sfRenderWindow_display(window->window_info);
    }
    destroy_main_screen(&quad_tree);
}
