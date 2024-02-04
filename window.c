/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** manage the window
** window
*/

#include "include/my.h"
#include "include/my_radar.h"

static void init_fps(window_t *window)
{
    window->fps = malloc(sizeof(game_fps_t));
    window->fps->clock_fps = sfClock_create();
    window->fps->fps = sfText_create();
    sfText_setFont(window->fps->fps, window->main_font);
    sfText_setString(window->fps->fps, "FPS : ");
    sfText_setColor(window->fps->fps, sfBlack);
    sfText_setPosition(window->fps->fps, (sfVector2f){0, 50});
    window->fps->fps_value = sfText_create();
    sfText_setFont(window->fps->fps_value, window->main_font);
    sfText_setColor(window->fps->fps_value, sfBlack);
    sfText_setPosition(window->fps->fps_value, (sfVector2f){50, 50});
}

static void init_timer(window_t *window)
{
    window->timer = malloc(sizeof(main_timer_t));
    window->timer->clock = sfClock_create();
    window->timer->time = sfText_create();
    sfText_setFont(window->timer->time, window->main_font);
    sfText_setString(window->timer->time, "TIME : ");
    sfText_setColor(window->timer->time, sfBlack);
    window->timer->time_value = sfText_create();
    sfText_setFont(window->timer->time_value, window->main_font);
    sfText_setPosition(window->timer->time_value, (sfVector2f){70, 0});
    sfText_setColor(window->timer->time_value, sfBlack);
}

static void init_main_music(window_t *window)
{
    window->music = malloc(sizeof(music_t));
    window->music->main_music = sfMusic_createFromFile("music/main_theme.ogg");
    sfMusic_setLoop(window->music->main_music, sfTrue);
    sfMusic_play(window->music->main_music);
}

static void init_background(window_t *window)
{
    window->background = malloc(sizeof(background_t));
    window->background->background_sprite = sfSprite_create();
    window->background->background_texture =
    sfTexture_createFromFile("pictures/world_map5.png", NULL);
    sfSprite_setTexture(window->background->background_sprite,
    window->background->background_texture, sfFalse);
    sfSprite_setScale(window->background->background_sprite,
    (sfVector2f){1.5, 1.7});
}

static void init_window_aux(window_t *window)
{
    window->plane_clock = sfClock_create();
    window->video_mode.height = 1080;
    window->video_mode.width = 1920;
    window->video_mode.bitsPerPixel = 64;
    window->window_name = "my_radar (created by Killian QUINTIN)";
    window->window_info = sfRenderWindow_create(window->video_mode,
    window->window_name, sfClose, NULL);
    window->window_size = sfRenderWindow_getSize(window->window_info);
    sfRenderWindow_setFramerateLimit(window->window_info, 60);
}

void init_window(window_t *window)
{
    window->main_font = sfFont_createFromFile("font/Airport.otf");
    init_main_music(window);
    init_background(window);
    init_timer(window);
    init_fps(window);
    init_quad_tree_limits(window);
    window->id_planes = 0;
    window->id_towers = 0;
    window->show_quad_tree = False;
    window->show_hitboxes = False;
    window->show_entities = True;
    window->start = False;
    window->pause = False;
    window->total_planes = 0;
    window->arrived_planes = 0;
    init_window_aux(window);
}
