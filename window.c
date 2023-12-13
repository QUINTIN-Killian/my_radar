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
    window->background = malloc(sizeof(background_t));
    window->background->background_sprite = sfSprite_create();
    window->background->background_texture =
    sfTexture_createFromFile("pictures/world_map3.png", NULL);
    sfSprite_setTexture(window->background->background_sprite,
    window->background->background_texture, sfFalse);
    sfSprite_setScale(window->background->background_sprite,
    (sfVector2f){2.25, 2.3});
    window->id_planes = 0;
    window->id_towers = 0;
    window->video_mode.height = 1080;
    window->video_mode.width = 1920;
    window->video_mode.bitsPerPixel = 64;
    window->window_name = "my_radar (created by Killian QUINTIN)";
    window->window_info = sfRenderWindow_create(window->video_mode,
    window->window_name, sfClose, NULL);
    window->window_size = sfRenderWindow_getSize(window->window_info);
}
