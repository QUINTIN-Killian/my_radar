/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** start screen
** start
*/

#include "include/my.h"
#include "include/my_radar.h"

void init_background_start(window_t *window, start_menu_t *start)
{
    start->start_text = sfText_create();
    sfText_setPosition(start->start_text, (sfVector2f){822, 250});
    sfText_setFillColor(start->start_text, sfWhite);
    sfText_setOutlineColor(start->start_text, sfBlack);
    sfText_setFont(start->start_text, window->main_font);
    sfText_setString(start->start_text, "my_radar");
    sfText_setOutlineThickness(start->start_text, 2.0);
    sfText_setCharacterSize(start->start_text, 90);
    start->start_background = sfRectangleShape_create();
    sfRectangleShape_setSize(start->start_background, (sfVector2f){300, 600});
    sfRectangleShape_setOrigin(start->start_background,
    (sfVector2f){150, 300});
    sfRectangleShape_setPosition(start->start_background,
    (sfVector2f){960, 540});
    sfRectangleShape_setOutlineThickness(start->start_background, 5.0);
    sfRectangleShape_setOutlineColor(start->start_background, sfBlack);
    sfRectangleShape_setFillColor(start->start_background, sfWhite);
}

void init_launch_start(window_t *window, start_menu_t *start)
{
    start->launch_game_button = sfRectangleShape_create();
    sfRectangleShape_setSize(start->launch_game_button,
    (sfVector2f){250, 100});
    sfRectangleShape_setOrigin(start->launch_game_button,
    (sfVector2f){125, 50});
    sfRectangleShape_setPosition(start->launch_game_button,
    (sfVector2f){960, 550});
    sfRectangleShape_setOutlineThickness(start->launch_game_button, 2.0);
    sfRectangleShape_setOutlineColor(start->launch_game_button, sfBlack);
    sfRectangleShape_setFillColor(start->launch_game_button, sfWhite);
    start->launch_game = sfText_create();
    sfText_setPosition(start->launch_game, (sfVector2f){877, 533});
    sfText_setFillColor(start->launch_game, sfWhite);
    sfText_setOutlineColor(start->launch_game, sfBlack);
    sfText_setFont(start->launch_game, window->main_font);
    sfText_setString(start->launch_game, "START SIMULATION");
    sfText_setOutlineThickness(start->launch_game, 2.0);
    sfText_setCharacterSize(start->launch_game, 30);
}

void init_leave_start(window_t *window, start_menu_t *start)
{
    start->leave_game_button = sfRectangleShape_create();
    sfRectangleShape_setSize(start->leave_game_button, (sfVector2f){250, 100});
    sfRectangleShape_setOrigin(start->leave_game_button,
    (sfVector2f){125, 50});
    sfRectangleShape_setPosition(start->leave_game_button,
    (sfVector2f){960, 670});
    sfRectangleShape_setOutlineThickness(start->leave_game_button, 2.0);
    sfRectangleShape_setOutlineColor(start->leave_game_button, sfBlack);
    sfRectangleShape_setFillColor(start->leave_game_button, sfWhite);
    start->leave_game = sfText_create();
    sfText_setPosition(start->leave_game, (sfVector2f){934, 650});
    sfText_setFillColor(start->leave_game, sfWhite);
    sfText_setOutlineColor(start->leave_game, sfBlack);
    sfText_setFont(start->leave_game, window->main_font);
    sfText_setString(start->leave_game, "LEAVE");
    sfText_setOutlineThickness(start->leave_game, 2.0);
    sfText_setCharacterSize(start->leave_game, 30);
}

static void init_start(window_t *window, start_menu_t *start)
{
    init_background_start(window, start);
    init_launch_start(window, start);
    init_leave_start(window, start);
}

static void destroy_start(start_menu_t *start)
{
    sfRectangleShape_destroy(start->start_background);
    sfRectangleShape_destroy(start->launch_game_button);
    sfRectangleShape_destroy(start->leave_game_button);
    sfText_destroy(start->start_text);
    sfText_destroy(start->launch_game);
    sfText_destroy(start->leave_game);
}

void is_started(sfEvent *event, window_t *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window->window_info);

    if (event->type == sfEvtMouseButtonPressed &&
    pos.x >= 960 - 125 && pos.x <= 960 + 125 &&
    pos.y >= 550 - 50 && pos.y <= 550 + 50) {
        window->start = True;
        return;
    }
}

static void change_button_color(window_t *window, start_menu_t *start)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(window->window_info);

    if (mouse_pos.x >= 960 - 125 && mouse_pos.x <= 960 + 125 &&
    mouse_pos.y >= 550 - 50 && mouse_pos.y <= 550 + 50)
        sfRectangleShape_setFillColor(start->launch_game_button, sfCyan);
    else
        sfRectangleShape_setFillColor(start->launch_game_button, sfWhite);
    if (mouse_pos.x >= 960 - 125 && mouse_pos.x <= 960 + 125 &&
    mouse_pos.y >= 670 - 50 && mouse_pos.y <= 670 + 50)
        sfRectangleShape_setFillColor(start->leave_game_button, sfCyan);
    else
        sfRectangleShape_setFillColor(start->leave_game_button, sfWhite);
}

static void display_start(window_t *window, start_menu_t *start)
{
    sfRenderWindow_drawSprite(window->window_info,
    window->background->background_sprite, NULL);
    sfRenderWindow_drawRectangleShape(window->window_info,
    start->start_background, NULL);
    sfRenderWindow_drawText(window->window_info, start->start_text, NULL);
    sfRenderWindow_drawRectangleShape(window->window_info,
    start->launch_game_button, NULL);
    sfRenderWindow_drawText(window->window_info,
    start->launch_game, NULL);
    sfRenderWindow_drawRectangleShape(window->window_info,
    start->leave_game_button, NULL);
    sfRenderWindow_drawText(window->window_info, start->leave_game, NULL);
}

void start_game(window_t *window, linked_planes_t **planes_list,
    linked_towers_t **towers_list)
{
    start_menu_t start;

    init_start(window, &start);
    while (sfRenderWindow_isOpen(window->window_info) && !window->start) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        display_start(window, &start);
        change_button_color(window, &start);
        get_start_event(window);
        sfRenderWindow_display(window->window_info);
    }
    if (!sfRenderWindow_isOpen(window->window_info))
        destroy_start(&start);
    else
        main_screen(window, planes_list, towers_list);
}
