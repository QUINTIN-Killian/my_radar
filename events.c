/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** get the events during the simulation
** events
*/

#include "include/my.h"
#include "include/my_radar.h"

void display(sfEvent *event, window_t *window)
{
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyL) &&
    window->show_hitboxes) {
        window->show_hitboxes = False;
        return;
    }
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyL) &&
    !window->show_hitboxes) {
        window->show_hitboxes = True;
        return;
    }
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyS) &&
    window->show_entities) {
        window->show_entities = False;
        return;
    }
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyS) &&
    !window->show_entities) {
        window->show_entities = True;
        return;
    }
}

void music_play(sfEvent *event, window_t *window)
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

void volume(sfEvent *event, window_t *window)
{
    volume_up(event, window);
    volume_down(event, window);
}

static void close_window(sfEvent *event, window_t *window)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(window->window_info);

    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window->window_info);
        return;
    }
    if (window->pause && event->type == sfEvtMouseButtonPressed &&
    mouse_pos.x >= 960 - 125 && mouse_pos.x <= 960 + 125 &&
    mouse_pos.y >= 670 - 50 && mouse_pos.y <= 670 + 50) {
        sfRenderWindow_close(window->window_info);
        return;
    }
}

void get_event(window_t *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window_info, &event)) {
        close_window(&event, window);
        music_play(&event, window);
        volume(&event, window);
        display(&event, window);
        is_paused(&event, window);
    }
}
