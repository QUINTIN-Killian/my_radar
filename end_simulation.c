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

void end(window_t *window, linked_planes_t **planes_list)
{
    if (my_planes_list_len(planes_list) == 0)
        sfRenderWindow_close(window->window_info);
}
