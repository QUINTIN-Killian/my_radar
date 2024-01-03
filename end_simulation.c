/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** detect if there is no plane left on the screen
** end_simulation
*/

#include "include/my.h"
#include "include/my_radar.h"

int is_arrived(linked_planes_t *node)
{
    if (node->plane_info->plane_pos.x >=
    node->plane_info->arrival_coords.x - 10.0 &&
    node->plane_info->plane_pos.x <=
    node->plane_info->arrival_coords.x + 10.0 &&
    node->plane_info->plane_pos.y >=
    node->plane_info->arrival_coords.y - 10.0 &&
    node->plane_info->plane_pos.y <=
    node->plane_info->arrival_coords.y + 10.0) {
        return 1;
    }
    return 0;
}

void init_background_end(window_t *window, end_menu_t *end)
{
    end->end_text = sfText_create();
    sfText_setPosition(end->end_text, (sfVector2f){904, 250});
    sfText_setFillColor(end->end_text, sfWhite);
    sfText_setOutlineColor(end->end_text, sfBlack);
    sfText_setFont(end->end_text, window->main_font);
    sfText_setString(end->end_text, "END");
    sfText_setOutlineThickness(end->end_text, 2.0);
    sfText_setCharacterSize(end->end_text, 100);
    end->end_background = sfRectangleShape_create();
    sfRectangleShape_setSize(end->end_background, (sfVector2f){300, 600});
    sfRectangleShape_setOrigin(end->end_background,
    (sfVector2f){150, 300});
    sfRectangleShape_setPosition(end->end_background,
    (sfVector2f){960, 540});
    sfRectangleShape_setOutlineThickness(end->end_background, 5.0);
    sfRectangleShape_setOutlineColor(end->end_background, sfBlack);
    sfRectangleShape_setFillColor(end->end_background, sfWhite);
}

void init_button_end(window_t *window, end_menu_t *end)
{
    end->leave_game_button = sfRectangleShape_create();
    sfRectangleShape_setSize(end->leave_game_button, (sfVector2f){250, 100});
    sfRectangleShape_setOrigin(end->leave_game_button, (sfVector2f){125, 50});
    sfRectangleShape_setPosition(end->leave_game_button,
    (sfVector2f){960, 670});
    sfRectangleShape_setOutlineThickness(end->leave_game_button, 2.0);
    sfRectangleShape_setOutlineColor(end->leave_game_button, sfBlack);
    sfRectangleShape_setFillColor(end->leave_game_button, sfWhite);
    end->leave_game = sfText_create();
    sfText_setPosition(end->leave_game, (sfVector2f){934, 650});
    sfText_setFillColor(end->leave_game, sfWhite);
    sfText_setOutlineColor(end->leave_game, sfBlack);
    sfText_setFont(end->leave_game, window->main_font);
    sfText_setString(end->leave_game, "LEAVE");
    sfText_setOutlineThickness(end->leave_game, 2.0);
    sfText_setCharacterSize(end->leave_game, 30);
}

static void init_end_menu(window_t *window, end_menu_t *end)
{
    init_background_end(window, end);
    init_button_end(window, end);
    init_total_planes(window, end);
    init_arrived_planes(window, end);
    init_percentage_arrived_planes(window, end);
    init_destroyed_planes(window, end);
    init_percentage_destroyed_planes(window, end);
}

static void destroy_end(end_menu_t *end)
{
    sfRectangleShape_destroy(end->end_background);
    sfText_destroy(end->end_text);
    sfRectangleShape_destroy(end->leave_game_button);
    sfText_destroy(end->leave_game);
    sfText_destroy(end->total_planes_text);
    sfText_destroy(end->total_planes_value);
    sfText_destroy(end->arrived_planes_text);
    sfText_destroy(end->arrived_planes_value);
    sfText_destroy(end->percentage_arrived_planes_text);
    sfText_destroy(end->percentage_arrived_planes_value);
    sfText_destroy(end->destroyed_planes_text);
    sfText_destroy(end->destroyed_planes_value);
    sfText_destroy(end->percentage_destroyed_planes_text);
    sfText_destroy(end->percentage_destroyed_planes_value);
}

static void display_end_aux(window_t *window, end_menu_t *end)
{
    sfRenderWindow_drawText(window->window_info,
    end->arrived_planes_value, NULL);
    sfRenderWindow_drawText(window->window_info,
    end->percentage_arrived_planes_text, NULL);
    sfRenderWindow_drawText(window->window_info,
    end->percentage_arrived_planes_value, NULL);
    sfRenderWindow_drawText(window->window_info,
    end->destroyed_planes_text, NULL);
    sfRenderWindow_drawText(window->window_info,
    end->destroyed_planes_value, NULL);
    sfRenderWindow_drawText(window->window_info,
    end->percentage_destroyed_planes_text, NULL);
    sfRenderWindow_drawText(window->window_info,
    end->percentage_destroyed_planes_value, NULL);
}

static void display_end(window_t *window, end_menu_t *end)
{
    sfRenderWindow_drawSprite(window->window_info,
    window->background->background_sprite, NULL);
    sfRenderWindow_drawRectangleShape(window->window_info,
    end->end_background, NULL);
    sfRenderWindow_drawText(window->window_info, end->end_text, NULL);
    sfRenderWindow_drawRectangleShape(window->window_info,
    end->leave_game_button, NULL);
    sfRenderWindow_drawText(window->window_info,
    end->leave_game, NULL);
    sfRenderWindow_drawText(window->window_info,
    end->total_planes_text, NULL);
    sfRenderWindow_drawText(window->window_info,
    end->total_planes_value, NULL);
    sfRenderWindow_drawText(window->window_info,
    end->arrived_planes_text, NULL);
    display_end_aux(window, end);
}

static void change_button_color(window_t *window, end_menu_t *end)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(window->window_info);

    if (mouse_pos.x >= 960 - 125 && mouse_pos.x <= 960 + 125 &&
    mouse_pos.y >= 670 - 50 && mouse_pos.y <= 670 + 50)
        sfRectangleShape_setFillColor(end->leave_game_button, sfCyan);
    else
        sfRectangleShape_setFillColor(end->leave_game_button, sfWhite);
}

void end_screen(window_t *window)
{
    end_menu_t end;

    init_end_menu(window, &end);
    while (sfRenderWindow_isOpen(window->window_info)) {
        sfRenderWindow_clear(window->window_info, sfBlack);
        display_end(window, &end);
        change_button_color(window, &end);
        get_end_event(window);
        sfRenderWindow_display(window->window_info);
    }
    destroy_end(&end);
}
