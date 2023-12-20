/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Header for my_radar project.
** my_hunter
*/

#include <math.h>
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

typedef enum boolean {
    False,
    True
} bool;

typedef struct background {
    sfTexture *background_texture;
    sfSprite *background_sprite;
} background_t;

typedef struct music {
    sfMusic *main_music;
} music_t;

typedef struct timer {
    sfClock *clock;
    sfText *time;
    sfFont *time_font;
    sfText *time_value;
    sfFont *time_value_font;
} main_timer_t;

typedef struct game_fps {
    sfClock *clock_fps;
    sfText *fps;
    sfFont *fps_font;
    sfText *fps_value;
    sfFont *fps_value_font;
} game_fps_t;

typedef struct window {
    int id_planes;
    int id_towers;
    bool show_hitboxes;
    bool show_entities;
    sfClock *plane_clock;
    sfRenderWindow *window_info;
    sfVector2u window_size;
    sfVideoMode video_mode;
    char *window_name;
    background_t *background;
    music_t *music;
    main_timer_t *timer;
    game_fps_t *fps;
} window_t;

typedef struct plane {
    int id;
    float rotation;
    float hypothenuse;
    sfVector2f departure_coords;
    sfVector2f arrival_coords;
    sfVector2f plane_pos;
    int speed;
    int delay;
    sfRectangleShape *hitbox;
    sfSprite *plane_sprite;
    sfTexture *plane_texture;
} plane_t;

typedef struct linked_list_planes {
    plane_t *plane_info;
    struct linked_list_planes *next;
} linked_planes_t;

typedef struct linked_list_towers {
    int id;
    sfVector2f tower_pos;
    int radius;
    sfSprite *tower_sprite;
    sfTexture *tower_texture;
    sfCircleShape *range;
    struct linked_list_towers *next;
} linked_towers_t;

typedef struct corner {
    struct quad_tree *under_quad_tree;
    sfIntRect area;
    int nb_planes;
    linked_planes_t **under_planes_list;
} corner_t;

typedef struct quad_tree {
    corner_t *top_left;
    corner_t *top_right;
    corner_t *bottom_left;
    corner_t *bottom_right;
} quad_tree_t;

//file.c :
char **get_buffer_file(char *filepath);
void add_elt(char **word_array, window_t *window,
    linked_planes_t **planes_list, linked_towers_t **towers_list);

//error_handling.c :
char **error_handling(int ac, char **av);

//window.c :
void init_window(window_t *window);

//main_screen.c :
void main_screen(window_t *window, linked_planes_t **planes_list,
    linked_towers_t **towers_list);

//action_on_planes.c :
linked_planes_t *cpy_plane_node(linked_planes_t *node);
int my_planes_list_len(linked_planes_t **planes_list);
void disp_planes_list(linked_planes_t **planes_list);
void del_in_planes_list(linked_planes_t **planes_list, int id_del);
void add_in_planes_list(linked_planes_t **planes_list,
    linked_planes_t *new_node, int is_new);

//action_on_towers.c :
int my_towers_list_len(linked_towers_t **towers_list);
void disp_towers_list(linked_towers_t **towers_list);
void del_in_towers_list(linked_towers_t **towers_list, int id_del);
void add_in_towers_list(linked_towers_t **towers_list,
    linked_towers_t *new_node);

//events.c :
void get_event(window_t *window);

//quad_tree.c :
void del_in_quad_tree(quad_tree_t *quad_tree);
void put_in_quad_tree(quad_tree_t *quad_tree,
    linked_planes_t *plane);
void init_quad_tree(window_t *window, quad_tree_t *quad_tree);

//planes_travel.c :
void get_plane_travel_info(linked_planes_t *node);

//end_simulation.c :
int is_arrived(linked_planes_t *node);
void end(window_t *window, linked_planes_t **planes_list);

//hitbox.c :
void init_hitbox(linked_planes_t *node);
void explore_quad_tree(linked_planes_t **head, quad_tree_t *quad_tree);

//display.c :
void display_fonctions(window_t *window, linked_planes_t **planes_list,
    linked_towers_t **towers_list, quad_tree_t *quad_tree);

#endif
