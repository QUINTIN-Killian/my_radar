/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** end events
** end_events
*/

#include "include/my.h"
#include "include/my_radar.h"

void leave_simulation(sfEvent *event, window_t *window)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(window->window_info);

    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyEscape)) {
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

void music_play_end(sfEvent *event, window_t *window)
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

void volume_end(sfEvent *event, window_t *window)
{
    volume_up(event, window);
    volume_down(event, window);
}

void get_end_event(window_t *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window_info, &event)) {
        leave_simulation(&event, window);
        music_play_end(&event, window);
        volume_end(&event, window);
    }
}
