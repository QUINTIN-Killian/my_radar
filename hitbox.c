/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** manage the planes hitboxes
** rect
*/

#include "include/my.h"
#include "include/my_radar.h"

void init_hitbox(linked_planes_t *node)
{
    node->plane_info->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(node->plane_info->hitbox, (sfVector2f)
    {sfTexture_getSize(node->plane_info->plane_texture).x,
    sfTexture_getSize(node->plane_info->plane_texture).y});
    sfRectangleShape_setScale(node->plane_info->hitbox,
    (sfVector2f){0.2, 0.2});
    sfRectangleShape_setFillColor(node->plane_info->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(node->plane_info->hitbox, sfGreen);
    sfRectangleShape_setOrigin(node->plane_info->hitbox, (sfVector2f)
    {sfTexture_getSize(node->plane_info->plane_texture).x / 2,
    sfTexture_getSize(node->plane_info->plane_texture).y / 2});
    sfRectangleShape_setOutlineThickness(node->plane_info->hitbox, 10);
    sfRectangleShape_setRotation(node->plane_info->hitbox, 90 -
    node->plane_info->rotation);
}
