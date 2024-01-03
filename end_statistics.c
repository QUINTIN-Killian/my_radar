/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** manage the end statistics
** end_statistics
*/

#include "include/my.h"
#include "include/my_radar.h"

void init_total_planes(window_t *window, end_menu_t *end)
{
    char *tmp = convert_int_to_str(window->total_planes);

    end->total_planes_text = sfText_create();
    sfText_setPosition(end->total_planes_text, (sfVector2f){835, 400});
    sfText_setFillColor(end->total_planes_text, sfWhite);
    sfText_setOutlineColor(end->total_planes_text, sfBlack);
    sfText_setFont(end->total_planes_text, window->main_font);
    sfText_setString(end->total_planes_text, "- Total of planes : ");
    sfText_setOutlineThickness(end->total_planes_text, 2.0);
    sfText_setCharacterSize(end->total_planes_text, 22);
    end->total_planes_value = sfText_create();
    sfText_setPosition(end->total_planes_value, (sfVector2f){974, 400});
    sfText_setFillColor(end->total_planes_value, sfWhite);
    sfText_setOutlineColor(end->total_planes_value, sfBlack);
    sfText_setFont(end->total_planes_value, window->main_font);
    sfText_setString(end->total_planes_value, tmp);
    free(tmp);
    sfText_setOutlineThickness(end->total_planes_value, 2.0);
    sfText_setCharacterSize(end->total_planes_value, 22);
}

void init_arrived_planes(window_t *window, end_menu_t *end)
{
    char *tmp = convert_int_to_str(window->arrived_planes);

    end->arrived_planes_text = sfText_create();
    sfText_setPosition(end->arrived_planes_text, (sfVector2f){835, 430});
    sfText_setFillColor(end->arrived_planes_text, sfWhite);
    sfText_setOutlineColor(end->arrived_planes_text, sfBlack);
    sfText_setFont(end->arrived_planes_text, window->main_font);
    sfText_setString(end->arrived_planes_text, "- Arrived planes : ");
    sfText_setOutlineThickness(end->arrived_planes_text, 2.0);
    sfText_setCharacterSize(end->arrived_planes_text, 22);
    end->arrived_planes_value = sfText_create();
    sfText_setPosition(end->arrived_planes_value, (sfVector2f){963, 430});
    sfText_setFillColor(end->arrived_planes_value, sfWhite);
    sfText_setOutlineColor(end->arrived_planes_value, sfBlack);
    sfText_setFont(end->arrived_planes_value, window->main_font);
    sfText_setString(end->arrived_planes_value, tmp);
    free(tmp);
    sfText_setOutlineThickness(end->arrived_planes_value, 2.0);
    sfText_setCharacterSize(end->arrived_planes_value, 22);
}

static void init_percentage_arrived_planes_aux(window_t *window,
    end_menu_t *end, char *tmp)
{
    sfText_setFillColor(end->percentage_arrived_planes_value, sfWhite);
    sfText_setOutlineColor(end->percentage_arrived_planes_value, sfBlack);
    sfText_setFont(end->percentage_arrived_planes_value, window->main_font);
    sfText_setString(end->percentage_arrived_planes_value, tmp);
    free(tmp);
    sfText_setOutlineThickness(end->percentage_arrived_planes_value, 2.0);
    sfText_setCharacterSize(end->percentage_arrived_planes_value, 22);
}

void init_percentage_arrived_planes(window_t *window, end_menu_t *end)
{
    char *tmp = convert_int_to_str(100 * window->arrived_planes /
    window->total_planes);

    end->percentage_arrived_planes_text = sfText_create();
    sfText_setPosition(end->percentage_arrived_planes_text,
    (sfVector2f){835, 460});
    sfText_setFillColor(end->percentage_arrived_planes_text, sfWhite);
    sfText_setOutlineColor(end->percentage_arrived_planes_text, sfBlack);
    sfText_setFont(end->percentage_arrived_planes_text, window->main_font);
    sfText_setString(end->percentage_arrived_planes_text,
    "- Arrived planes (in %) : ");
    sfText_setOutlineThickness(end->percentage_arrived_planes_text, 2.0);
    sfText_setCharacterSize(end->percentage_arrived_planes_text, 22);
    end->percentage_arrived_planes_value = sfText_create();
    sfText_setPosition(end->percentage_arrived_planes_value,
    (sfVector2f){1010, 460});
    init_percentage_arrived_planes_aux(window, end, tmp);
}

void init_destroyed_planes(window_t *window, end_menu_t *end)
{
    char *tmp = convert_int_to_str(window->total_planes -
    window->arrived_planes);

    end->destroyed_planes_text = sfText_create();
    sfText_setPosition(end->destroyed_planes_text, (sfVector2f){835, 490});
    sfText_setFillColor(end->destroyed_planes_text, sfWhite);
    sfText_setOutlineColor(end->destroyed_planes_text, sfBlack);
    sfText_setFont(end->destroyed_planes_text, window->main_font);
    sfText_setString(end->destroyed_planes_text, "- Destroyed planes : ");
    sfText_setOutlineThickness(end->destroyed_planes_text, 2.0);
    sfText_setCharacterSize(end->destroyed_planes_text, 22);
    end->destroyed_planes_value = sfText_create();
    sfText_setPosition(end->destroyed_planes_value, (sfVector2f){986, 490});
    sfText_setFillColor(end->destroyed_planes_value, sfWhite);
    sfText_setOutlineColor(end->destroyed_planes_value, sfBlack);
    sfText_setFont(end->destroyed_planes_value, window->main_font);
    sfText_setString(end->destroyed_planes_value, tmp);
    free(tmp);
    sfText_setOutlineThickness(end->destroyed_planes_value, 2.0);
    sfText_setCharacterSize(end->destroyed_planes_value, 22);
}

static void init_percentage_destroyed_planes_aux(window_t *window,
    end_menu_t *end, char *tmp)
{
    sfText_setFillColor(end->percentage_destroyed_planes_value, sfWhite);
    sfText_setOutlineColor(end->percentage_destroyed_planes_value, sfBlack);
    sfText_setFont(end->percentage_destroyed_planes_value, window->main_font);
    sfText_setString(end->percentage_destroyed_planes_value, tmp);
    free(tmp);
    sfText_setOutlineThickness(end->percentage_destroyed_planes_value, 2.0);
    sfText_setCharacterSize(end->percentage_destroyed_planes_value, 22);
}

void init_percentage_destroyed_planes(window_t *window, end_menu_t *end)
{
    char *tmp = convert_int_to_str(100 * (window->total_planes -
    window->arrived_planes) / window->total_planes);

    end->percentage_destroyed_planes_text = sfText_create();
    sfText_setPosition(end->percentage_destroyed_planes_text,
    (sfVector2f){835, 520});
    sfText_setFillColor(end->percentage_destroyed_planes_text, sfWhite);
    sfText_setOutlineColor(end->percentage_destroyed_planes_text, sfBlack);
    sfText_setFont(end->percentage_destroyed_planes_text, window->main_font);
    sfText_setString(end->percentage_destroyed_planes_text,
    "- Destroyed planes (in %) : ");
    sfText_setOutlineThickness(end->percentage_destroyed_planes_text, 2.0);
    sfText_setCharacterSize(end->percentage_destroyed_planes_text, 22);
    end->percentage_destroyed_planes_value = sfText_create();
    sfText_setPosition(end->percentage_destroyed_planes_value,
    (sfVector2f){1033, 520});
    init_percentage_destroyed_planes_aux(window, end, tmp);
}
