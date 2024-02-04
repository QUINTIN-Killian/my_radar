/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** display game infos
** display
*/

#include "include/my.h"
#include "include/my_radar.h"

static void draw_planes_aux(window_t *window, linked_planes_t *node)
{
    if (window->show_entities) {
        sfRenderWindow_drawSprite(window->window_info,
        node->plane_info->plane_sprite, NULL);
    }
    if (window->show_hitboxes) {
        sfRectangleShape_setPosition(node->plane_info->hitbox,
        node->plane_info->plane_pos);
        sfRenderWindow_drawRectangleShape(window->window_info,
        node->plane_info->hitbox, NULL);
    }
}

void draw_planes(window_t *window,
    linked_planes_t **planes_list, quad_tree_t *quad_tree)
{
    linked_planes_t *node = *planes_list;

    while (node != NULL) {
        if ((int)sfTime_asSeconds(sfClock_getElapsedTime(window->timer->clock))
        >= node->plane_info->delay) {
            put_in_quad_tree(quad_tree, node);
            draw_planes_aux(window, node);
        }
        node = node->next;
    }
}

void draw_towers(window_t *window, linked_towers_t **towers_list)
{
    linked_towers_t *node = *towers_list;

    while (node != NULL) {
        if (window->show_entities)
            sfRenderWindow_drawSprite(window->window_info,
            node->tower_sprite, NULL);
        if (window->show_hitboxes)
            sfRenderWindow_drawCircleShape(window->window_info, node->range,
            NULL);
        node = node->next;
    }
}

void draw_time(window_t *window)
{
    sfTime time_clock = sfClock_getElapsedTime(window->timer->clock);
    float time = sfTime_asSeconds(time_clock);
    char *tmp = convert_int_to_str((int)time);

    sfText_setString(window->timer->time_value, tmp);
    sfRenderWindow_drawText(window->window_info, window->timer->time, NULL);
    sfRenderWindow_drawText(window->window_info,
    window->timer->time_value, NULL);
    free(tmp);
}

void draw_fps(window_t *window)
{
    sfTime fps_clock = sfClock_getElapsedTime(window->fps->clock_fps);
    float time = sfTime_asSeconds(fps_clock);
    float fps = 1.0 / time;
    char *tmp;

    tmp = convert_int_to_str(fps);
    sfText_setString(window->fps->fps_value, tmp);
    sfRenderWindow_drawText(window->window_info, window->fps->fps, NULL);
    sfRenderWindow_drawText(window->window_info,
    window->fps->fps_value, NULL);
    free(tmp);
    sfClock_restart(window->fps->clock_fps);
}

static void draw_quad_tree_limits(window_t *window)
{
    if (window->show_quad_tree) {
        sfRenderWindow_drawRectangleShape(window->window_info,
        window->quad_tree_limits->h, NULL);
        sfRenderWindow_drawRectangleShape(window->window_info,
        window->quad_tree_limits->v, NULL);
    }
}

void display_fonctions(window_t *window, linked_planes_t **planes_list,
    linked_towers_t **towers_list, quad_tree_t *quad_tree)
{
    sfRenderWindow_drawSprite(window->window_info,
    window->background->background_sprite, NULL);
    draw_quad_tree_limits(window);
    draw_fps(window);
    draw_towers(window, towers_list);
    draw_planes(window, planes_list, quad_tree);
    draw_time(window);
}
