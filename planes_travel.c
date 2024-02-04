/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** manage the travel actions of the planes
** planes_travel
*/

#include "include/my.h"
#include "include/my_radar.h"

void get_plane_travel_info(linked_planes_t *node)
{
    float x = node->plane_info->arrival_coords.x -
    node->plane_info->departure_coords.x;
    float y = node->plane_info->arrival_coords.y -
    node->plane_info->departure_coords.y;
    float hyp1 = roundf(sqrtf(powf(x, 2.0) + powf(y, 2.0)));

    node->plane_info->hypothenuse = hyp1;
    node->plane_info->rotation = atan2f(x, y) * 180 /
    3.14159265358979323846264338;
}
