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
        if ((int)sfTime_asSeconds(sfClock_getElapsedTime(window->timer->clock))
        >= node->plane_info->delay)
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
    
    if (fps > 120.0)
        fps = 120.0;
    tmp = convert_int_to_str(fps);
    sfText_setString(window->fps->fps_value, tmp);
    sfRenderWindow_drawText(window->window_info, window->fps->fps, NULL);
    sfRenderWindow_drawText(window->window_info,
    window->fps->fps_value, NULL);
    free(tmp);
    sfClock_restart(window->fps->clock_fps);
}

void main_screen(window_t *window, linked_planes_t **planes_list,
    linked_towers_t **towers_list)
{
    window->fps->clock_fps = sfClock_create();
    while (sfRenderWindow_isOpen(window->window_info)) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        sfRenderWindow_drawSprite(window->window_info,
        window->background->background_sprite, NULL);
        draw_planes(window, planes_list);
        draw_towers(window, towers_list);
        draw_time(window);
        get_event(window);
        draw_fps(window);
        sfRenderWindow_display(window->window_info);
    }
}
