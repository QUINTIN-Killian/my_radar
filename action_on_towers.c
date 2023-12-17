/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** apply action on the towers list
** action_on_list
*/

#include "include/my.h"
#include "include/my_radar.h"

int my_towers_list_len(linked_towers_t **towers_list)
{
    linked_towers_t **head = towers_list;
    linked_towers_t *tmp = *head;
    int ans = 0;

    while (tmp != NULL) {
        ans++;
        tmp = tmp->next;
    }
    return ans;
}

void disp_towers_list(linked_towers_t **towers_list)
{
    linked_towers_t **head = towers_list;
    linked_towers_t *tmp = *head;

    my_putstr("TOWER :\n");
    if (tmp == NULL)
        my_putstr("NULL\n\n");
    while (tmp != NULL) {
        my_putstr("Id : ");
        my_put_nbr(tmp->id);
        my_putstr("\nCoordinates : ");
        my_put_nbr(tmp->tower_pos.x);
        my_putstr(", ");
        my_put_nbr(tmp->tower_pos.y);
        my_putstr("\nRadius : ");
        my_put_nbr(tmp->radius);
        my_putstr("\n\n");
        tmp = tmp->next;
    }
}

static void free_node(linked_towers_t *node)
{
    sfSprite_destroy(node->tower_sprite);
    sfTexture_destroy(node->tower_texture);
    sfCircleShape_destroy(node->range);
    free(node);
}

static linked_towers_t *del_first_node(linked_towers_t *current,
    linked_towers_t *tmp)
{
    tmp = current;
    current = current->next;
    free_node(tmp);
    return current;
}

static linked_towers_t *del_node(linked_towers_t **head, int id_del)
{
    linked_towers_t *current = *head;
    linked_towers_t *tmp = NULL;

    if (current == NULL)
        return current;
    if (current->id == id_del)
        return del_first_node(current, tmp);
    while (current->next != NULL) {
        if (current->next->id == id_del) {
            tmp = current->next;
            current->next = current->next->next;
            free_node(tmp);
            return *head;
        }
        current = current->next;
    }
    return *head;
}

void del_in_towers_list(linked_towers_t **towers_list, int id_del)
{
    linked_towers_t **head = towers_list;

    *head = del_node(head, id_del);
    towers_list = head;
}

static void init_new_node_sprite(linked_towers_t *new_node)
{
    new_node->tower_sprite = sfSprite_create();
    new_node->tower_texture =
    sfTexture_createFromFile("pictures/tower2.png", NULL);
    sfSprite_setTexture(new_node->tower_sprite,
    new_node->tower_texture, sfFalse);
    sfSprite_setPosition(new_node->tower_sprite, (sfVector2f)
    {new_node->tower_pos.x, new_node->tower_pos.y});
    sfSprite_setScale(new_node->tower_sprite, (sfVector2f){0.2, 0.2});
    new_node->range = sfCircleShape_create();
    sfCircleShape_setPosition(new_node->range, (sfVector2f)
    {new_node->tower_pos.x +
    sfTexture_getSize(new_node->tower_texture).x * 0.2 /
    2 - new_node->radius, new_node->tower_pos.y +
    sfTexture_getSize(new_node->tower_texture).y * 0.2 / 2 -
    new_node->radius});
    sfCircleShape_setRadius(new_node->range, (float)new_node->radius);
    sfCircleShape_setOutlineThickness(new_node->range, 3.0);
    sfCircleShape_setOutlineColor(new_node->range, sfBlack);
    sfCircleShape_setFillColor(new_node->range, sfTransparent);
}

void add_in_towers_list(linked_towers_t **towers_list,
    linked_towers_t *new_node)
{
    linked_towers_t **head = towers_list;

    init_new_node_sprite(new_node);
    new_node->next = *head;
    *head = new_node;
    towers_list = head;
}
