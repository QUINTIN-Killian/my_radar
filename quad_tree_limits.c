/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** display the quad tree's limits
** quad_tree_limits
*/

#include "include/my.h"
#include "include/my_radar.h"

static void init_quad_tree_limits_aux(window_t *window)
{
    window->quad_tree_limits->v = sfRectangleShape_create();
    sfRectangleShape_setOrigin(window->quad_tree_limits->v,
    (sfVector2f){0, 540});
    sfRectangleShape_setPosition(window->quad_tree_limits->v,
    (sfVector2f){960, 540});
    sfRectangleShape_setFillColor(window->quad_tree_limits->v, sfBlack);
    sfRectangleShape_setOutlineColor(window->quad_tree_limits->v, sfBlack);
    sfRectangleShape_setOutlineThickness(window->quad_tree_limits->v, 2.0);
    sfRectangleShape_setSize(window->quad_tree_limits->v,
    (sfVector2f){3, 1080});
}

void init_quad_tree_limits(window_t *window)
{
    window->quad_tree_limits = malloc(sizeof(quad_tree_limits_t));
    window->quad_tree_limits->h = sfRectangleShape_create();
    sfRectangleShape_setOrigin(window->quad_tree_limits->h,
    (sfVector2f){960, 0});
    sfRectangleShape_setPosition(window->quad_tree_limits->h,
    (sfVector2f){960, 540});
    sfRectangleShape_setFillColor(window->quad_tree_limits->h, sfBlack);
    sfRectangleShape_setOutlineColor(window->quad_tree_limits->h, sfBlack);
    sfRectangleShape_setOutlineThickness(window->quad_tree_limits->h, 2.0);
    sfRectangleShape_setSize(window->quad_tree_limits->h,
    (sfVector2f){1920, 3});
    init_quad_tree_limits_aux(window);
}
