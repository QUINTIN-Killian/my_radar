/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Header for my_radar project.
** my_hunter
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

typedef struct background {
    sfTexture *background_texture;
    sfSprite *background_sprite;
} background_t;

typedef struct window {
    sfRenderWindow *window_info;
    sfVector2u window_size;
    sfVideoMode video_mode;
    char *window_name;
    background_t *background;
} window_t;

//error_handling.c :
int error_handling(int ac, char **av);

//window.c :
void init_window(window_t *window);

//main_screen.c :
void main_screen(window_t *window);

//events.c :
void close_window(sfEvent *event, window_t *window);

#endif
