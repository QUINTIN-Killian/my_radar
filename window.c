/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** manage the window
** window
*/

#include "include/my.h"
#include "include/my_radar.h"

void init_window(window_t *window)
{
    window->video_mode.height = 600;
    window->video_mode.width = 800;
    window->video_mode.bitsPerPixel = 64;
    window->window_name = "my_radar (created by Killian QUINTIN)";
    window->window_info = sfRenderWindow_create(window->video_mode,
    window->window_name, sfClose, NULL);
    window->window_size = sfRenderWindow_getSize(window->window_info);
}
