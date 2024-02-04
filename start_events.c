/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** get the start events
** start_events
*/

#include "include/my.h"
#include "include/my_radar.h"

void music_play_start(sfEvent *event, window_t *window)
{
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (sfMusic_getStatus(window->music->main_music) == sfPaused) {
            sfMusic_play(window->music->main_music);
            return;
        }
        if (sfMusic_getStatus(window->music->main_music) == sfPlaying) {
            sfMusic_pause(window->music->main_music);
            return;
        }
    }
}

static void volume_up(sfEvent *event, window_t *window)
{
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyUp)) {
        sfMusic_setVolume(window->music->main_music,
        sfMusic_getVolume(window->music->main_music) + 5.0);
    }
}

static void volume_down(sfEvent *event, window_t *window)
{
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyDown)) {
        sfMusic_setVolume(window->music->main_music,
        sfMusic_getVolume(window->music->main_music) - 5.0);
    }
}

void volume_start(sfEvent *event, window_t *window)
{
    volume_up(event, window);
    volume_down(event, window);
}

static void close_start_window(sfEvent *event, window_t *window)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(window->window_info);

    if (event->type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(window->window_info);
        return;
    }
    if (event->type == sfEvtMouseButtonPressed &&
    mouse_pos.x >= 960 - 125 && mouse_pos.x <= 960 + 125 &&
    mouse_pos.y >= 670 - 50 && mouse_pos.y <= 670 + 50) {
        sfRenderWindow_close(window->window_info);
        return;
    }
}

void get_start_event(window_t *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window_info, &event)) {
        close_start_window(&event, window);
        music_play_start(&event, window);
        volume_start(&event, window);
        is_started(&event, window);
    }
}
