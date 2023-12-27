/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** pause screen
** pause
*/

#include "include/my.h"
#include "include/my_radar.h"

void init_background_pause(pause_menu_t *pause)
{
    pause->pause_text = sfText_create();
    pause->pause_text_font = sfFont_createFromFile("font/Airport.otf");
    sfText_setPosition(pause->pause_text, (sfVector2f){867, 250});
    sfText_setFillColor(pause->pause_text, sfWhite);
    sfText_setOutlineColor(pause->pause_text, sfBlack);
    sfText_setFont(pause->pause_text, pause->pause_text_font);
    sfText_setString(pause->pause_text, "PAUSE");
    sfText_setOutlineThickness(pause->pause_text, 2.0);
    sfText_setCharacterSize(pause->pause_text, 100);
    pause->pause_background = sfRectangleShape_create();
    sfRectangleShape_setSize(pause->pause_background, (sfVector2f){300, 600});
    sfRectangleShape_setOrigin(pause->pause_background,
    (sfVector2f){150, 300});
    sfRectangleShape_setPosition(pause->pause_background,
    (sfVector2f){960, 540});
    sfRectangleShape_setOutlineThickness(pause->pause_background, 5.0);
    sfRectangleShape_setOutlineColor(pause->pause_background, sfBlack);
    sfRectangleShape_setFillColor(pause->pause_background, sfWhite);
}

void init_continue_pause(pause_menu_t *pause)
{
    pause->continue_game_button = sfRectangleShape_create();
    sfRectangleShape_setSize(pause->continue_game_button,
    (sfVector2f){250, 100});
    sfRectangleShape_setOrigin(pause->continue_game_button,
    (sfVector2f){125, 50});
    sfRectangleShape_setPosition(pause->continue_game_button,
    (sfVector2f){960, 550});
    sfRectangleShape_setOutlineThickness(pause->continue_game_button, 2.0);
    sfRectangleShape_setOutlineColor(pause->continue_game_button, sfBlack);
    sfRectangleShape_setFillColor(pause->continue_game_button, sfWhite);
    pause->continue_game = sfText_create();
    pause->continue_game_font = sfFont_createFromFile("font/Airport.otf");
    sfText_setPosition(pause->continue_game, (sfVector2f){920, 533});
    sfText_setFillColor(pause->continue_game, sfWhite);
    sfText_setOutlineColor(pause->continue_game, sfBlack);
    sfText_setFont(pause->continue_game, pause->continue_game_font);
    sfText_setString(pause->continue_game, "CONTINUE");
    sfText_setOutlineThickness(pause->continue_game, 2.0);
    sfText_setCharacterSize(pause->continue_game, 30);
}

void init_leave_pause(pause_menu_t *pause)
{
    pause->leave_game_button = sfRectangleShape_create();
    sfRectangleShape_setSize(pause->leave_game_button, (sfVector2f){250, 100});
    sfRectangleShape_setOrigin(pause->leave_game_button,
    (sfVector2f){125, 50});
    sfRectangleShape_setPosition(pause->leave_game_button,
    (sfVector2f){960, 670});
    sfRectangleShape_setOutlineThickness(pause->leave_game_button, 2.0);
    sfRectangleShape_setOutlineColor(pause->leave_game_button, sfBlack);
    sfRectangleShape_setFillColor(pause->leave_game_button, sfWhite);
    pause->leave_game = sfText_create();
    pause->leave_game_font = sfFont_createFromFile("font/Airport.otf");
    sfText_setPosition(pause->leave_game, (sfVector2f){934, 650});
    sfText_setFillColor(pause->leave_game, sfWhite);
    sfText_setOutlineColor(pause->leave_game, sfBlack);
    sfText_setFont(pause->leave_game, pause->leave_game_font);
    sfText_setString(pause->leave_game, "LEAVE");
    sfText_setOutlineThickness(pause->leave_game, 2.0);
    sfText_setCharacterSize(pause->leave_game, 30);
}

static void init_pause(pause_menu_t *pause)
{
    init_background_pause(pause);
    init_continue_pause(pause);
    init_leave_pause(pause);
}

static void destroy_pause(pause_menu_t *pause)
{
    sfRectangleShape_destroy(pause->pause_background);
    sfRectangleShape_destroy(pause->continue_game_button);
    sfRectangleShape_destroy(pause->leave_game_button);
    sfText_destroy(pause->pause_text);
    sfFont_destroy(pause->pause_text_font);
    sfText_destroy(pause->continue_game);
    sfFont_destroy(pause->continue_game_font);
    sfText_destroy(pause->leave_game);
    sfFont_destroy(pause->leave_game_font);
}

void is_paused(sfEvent *event, window_t *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window->window_info);

    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyEscape) && !window->pause) {
        window->pause = True;
        return;
    }
    if (window->pause) {
        if (event->type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
            window->pause = False;
            return;
        }
        if (event->type == sfEvtMouseButtonPressed &&
        pos.x >= 960 - 125 && pos.x <= 960 + 125 &&
        pos.y >= 550 - 50 && pos.y <= 550 + 50) {
            window->pause = False;
            return;
        }
    }
}

static void change_button_color(window_t *window, pause_menu_t *pause)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(window->window_info);

    if (mouse_pos.x >= 960 - 125 && mouse_pos.x <= 960 + 125 &&
    mouse_pos.y >= 550 - 50 && mouse_pos.y <= 550 + 50)
        sfRectangleShape_setFillColor(pause->continue_game_button, sfCyan);
    else
        sfRectangleShape_setFillColor(pause->continue_game_button, sfWhite);
    if (mouse_pos.x >= 960 - 125 && mouse_pos.x <= 960 + 125 &&
    mouse_pos.y >= 670 - 50 && mouse_pos.y <= 670 + 50)
        sfRectangleShape_setFillColor(pause->leave_game_button, sfCyan);
    else
        sfRectangleShape_setFillColor(pause->leave_game_button, sfWhite);
}

static void display_pause(window_t *window, pause_menu_t *pause)
{
    sfRenderWindow_drawRectangleShape(window->window_info,
    pause->pause_background, NULL);
    sfRenderWindow_drawText(window->window_info, pause->pause_text, NULL);
    sfRenderWindow_drawRectangleShape(window->window_info,
    pause->continue_game_button, NULL);
    sfRenderWindow_drawText(window->window_info,
    pause->continue_game, NULL);
    sfRenderWindow_drawRectangleShape(window->window_info,
    pause->leave_game_button, NULL);
    sfRenderWindow_drawText(window->window_info, pause->leave_game, NULL);
}

void pause_game(window_t *window, linked_planes_t **planes_list,
    linked_towers_t **towers_list, quad_tree_t *quad_tree)
{
    pause_menu_t pause;

    init_pause(&pause);
    while (sfRenderWindow_isOpen(window->window_info) && window->pause) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        display_fonctions(window, planes_list, towers_list, quad_tree);
        display_pause(window, &pause);
        change_button_color(window, &pause);
        del_in_quad_tree(quad_tree);
        get_event(window);
        sfRenderWindow_display(window->window_info);
    }
    destroy_pause(&pause);
}
