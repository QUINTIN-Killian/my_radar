/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** apply action on the planes list
** action_on_list
*/

#include "include/my.h"
#include "include/my_radar.h"

linked_planes_t *cpy_plane_node(linked_planes_t *node)
{
    linked_planes_t *ans = malloc(sizeof(linked_planes_t));

    ans->next = NULL;
    ans->plane_info = malloc(sizeof(plane_t));
    ans->plane_info->arrival_coords = node->plane_info->arrival_coords;
    ans->plane_info->departure_coords = node->plane_info->departure_coords;
    ans->plane_info->delay = node->plane_info->delay;
    ans->plane_info->id = node->plane_info->id;
    ans->plane_info->plane_pos = node->plane_info->plane_pos;
    ans->plane_info->plane_texture =
    sfTexture_copy(node->plane_info->plane_texture);
    ans->plane_info->plane_sprite =
    sfSprite_copy(node->plane_info->plane_sprite);
    ans->plane_info->speed = node->plane_info->speed;
    ans->plane_info->hitbox = sfRectangleShape_copy(node->plane_info->hitbox);
    return ans;
}

int my_planes_list_len(linked_planes_t **planes_list)
{
    linked_planes_t **head = planes_list;
    linked_planes_t *tmp = *head;
    int ans = 0;

    while (tmp != NULL) {
        ans++;
        tmp = tmp->next;
    }
    return ans;
}

static void disp_planes_list_aux(linked_planes_t *tmp)
{
    my_putstr("Id : ");
    my_put_nbr(tmp->plane_info->id);
    my_putstr("\nDeparture coordinates : ");
    my_put_nbr(tmp->plane_info->departure_coords.x);
    my_putstr(", ");
    my_put_nbr(tmp->plane_info->departure_coords.y);
    my_putstr("\nArrival coordinates : ");
    my_put_nbr(tmp->plane_info->arrival_coords.x);
    my_putstr(", ");
    my_put_nbr(tmp->plane_info->arrival_coords.y);
    my_putstr("\nSpeed : ");
    my_put_nbr(tmp->plane_info->speed);
    my_putstr("\nDelay : ");
    my_put_nbr(tmp->plane_info->delay);
    my_putstr("\n\n");
}

void disp_planes_list(linked_planes_t **planes_list)
{
    linked_planes_t **head = planes_list;
    linked_planes_t *tmp = *head;

    my_putstr("PLANE :\n");
    if (tmp == NULL)
        my_putstr("NULL\n\n");
    while (tmp != NULL) {
        disp_planes_list_aux(tmp);
        tmp = tmp->next;
    }
}

static void free_node(linked_planes_t *node)
{
    sfSprite_destroy(node->plane_info->plane_sprite);
    sfTexture_destroy(node->plane_info->plane_texture);
    sfRectangleShape_destroy(node->plane_info->hitbox);
    free(node->plane_info);
    free(node);
}

static linked_planes_t *del_first_node(linked_planes_t *current,
    linked_planes_t *tmp)
{
    tmp = current;
    current = current->next;
    free_node(tmp);
    return current;
}

static linked_planes_t *del_node(linked_planes_t **head, int id_del)
{
    linked_planes_t *current = *head;
    linked_planes_t *tmp = NULL;

    if (current == NULL)
        return current;
    if (current->plane_info->id == id_del)
        return del_first_node(current, tmp);
    while (current->next != NULL) {
        if (current->next->plane_info->id == id_del) {
            tmp = current->next;
            current->next = current->next->next;
            free_node(tmp);
            return *head;
        }
        current = current->next;
    }
    return *head;
}

void del_in_planes_list(linked_planes_t **planes_list, int id_del)
{
    linked_planes_t **head = planes_list;

    *head = del_node(head, id_del);
    planes_list = head;
}

static void init_new_node_sprite(linked_planes_t *new_node)
{
    new_node->plane_info->plane_pos = new_node->plane_info->departure_coords;
    new_node->plane_info->plane_sprite = sfSprite_create();
    new_node->plane_info->plane_texture =
    sfTexture_createFromFile("pictures/plane4.png", NULL);
    sfSprite_setTexture(new_node->plane_info->plane_sprite,
    new_node->plane_info->plane_texture, sfFalse);
    sfSprite_setScale(new_node->plane_info->plane_sprite, (sfVector2f){20.0 /
    (float)sfTexture_getSize(new_node->plane_info->plane_texture).x, 20.0 /
    (float)sfTexture_getSize(new_node->plane_info->plane_texture).y});
    sfSprite_setOrigin(new_node->plane_info->plane_sprite, (sfVector2f)
    {sfTexture_getSize(new_node->plane_info->plane_texture).x / 2,
    sfTexture_getSize(new_node->plane_info->plane_texture).y / 2});
    sfSprite_setPosition(new_node->plane_info->plane_sprite, (sfVector2f)
    {new_node->plane_info->plane_pos.x, new_node->plane_info->plane_pos.y});
    sfSprite_setRotation(new_node->plane_info->plane_sprite, 90.0 -
    new_node->plane_info->rotation);
}

void add_in_planes_list(linked_planes_t **planes_list,
    linked_planes_t *new_node, int is_new)
{
    linked_planes_t *head = *planes_list;

    if (is_new)
        init_new_node_sprite(new_node);
    new_node->next = head;
    *planes_list = new_node;
}
