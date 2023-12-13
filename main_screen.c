/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** main screen of the simulation
** main_screen
*/

#include "include/my.h"
#include "include/my_radar.h"

void draw_planes(window_t *window, linked_planes_t **planes_list)
{
    linked_planes_t *node = *planes_list;

    while (node != NULL) {
        sfRenderWindow_drawSprite(window->window_info,
        node->plane_info->plane_sprite, NULL);
        node = node->next;
    }
}

void draw_towers(window_t *window, linked_towers_t **towers_list)
{
    linked_towers_t *node = *towers_list;

    while (node != NULL) {
        sfRenderWindow_drawSprite(window->window_info,
        node->tower_sprite, NULL);
        sfRenderWindow_drawCircleShape(window->window_info, node->range, NULL);
        node = node->next;
    }
}

void main_screen(window_t *window, linked_planes_t **planes_list,
    linked_towers_t **towers_list)
{
    while (sfRenderWindow_isOpen(window->window_info)) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        sfRenderWindow_drawSprite(window->window_info,
        window->background->background_sprite, NULL);
        draw_planes(window, planes_list);
        draw_towers(window, towers_list);
        get_event(window);
        sfRenderWindow_display(window->window_info);
    }
}
