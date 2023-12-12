/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** main screen of the simulation
** main_screen
*/

#include "include/my.h"
#include "include/my_radar.h"

void main_screen(window_t *window)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window->window_info)) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        close_window(&event, window);
        sfRenderWindow_display(window->window_info);
    }
}
