/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** get the events during the simulation
** events
*/

#include "include/my.h"
#include "include/my_radar.h"

static void close_window(sfEvent *event, window_t *window)
{
    if (event->type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window->window_info);
}

void get_event(window_t *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->window_info, &event)) {
        close_window(&event, window);
    }
}
