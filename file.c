/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** get the file content
** file
*/

#include "include/my.h"
#include "include/my_radar.h"

static int check_aircraft(char **word_array, int *ind)
{
    int nbr;

    if (*ind + 7 > my_strlen_array(word_array))
        return 84;
    *ind = *ind + 1;
    for (int i = 0; i < 6; i++) {
        if (!my_str_isnum(word_array[*ind]))
            return 84;
        nbr = convert_str_in_int(word_array[*ind]);
        if ((i == 0 || i == 2) && nbr > 1920)
            return 84;
        if ((i == 1 || i == 3) && nbr > 1080)
            return 84;
        if (i == 4 && nbr > 20)
            return 84;
        *ind = *ind + 1;
    }
    return 0;
}

static int check_tower(char **word_array, int *ind)
{
    int nbr;

    if (*ind + 4 > my_strlen_array(word_array))
        return 84;
    *ind = *ind + 1;
    for (int i = 0; i < 3; i++) {
        if (!my_str_isnum(word_array[*ind]))
            return 84;
        nbr = convert_str_in_int(word_array[*ind]);
        if (i == 0 && nbr > 1920)
            return 84;
        if (i == 1 && nbr > 1080)
            return 84;
        if (i == 2 && (nbr > 20 || nbr < 1))
            return 84;
        *ind = *ind + 1;
    }
    return 0;
}

char **check_buffer_content(char **word_array)
{
    int ind = 0;
    int ans = 0;

    if (my_strlen_array(word_array) == 0)
        return NULL;
    while (ind < my_strlen_array(word_array)) {
        if (ans != 0 || (my_strcmp(word_array[ind], "A") != 0 &&
        my_strcmp(word_array[ind], "T") != 0)) {
            return NULL;
        }
        if (my_strcmp(word_array[ind], "A") == 0) {
            ans = check_aircraft(word_array, &ind);
            continue;
        }
        if (my_strcmp(word_array[ind], "T") == 0) {
            ans = check_tower(word_array, &ind);
            continue;
        }
    }
    return word_array;
}

static char **create_word_array(struct stat *st, int fd)
{
    int file_size = st->st_size;
    int len;
    char *buff;
    char **word_array;

    buff = malloc(sizeof(char) * (file_size + 1));
    buff[file_size] = '\0';
    len = read(fd, buff, file_size);
    close(fd);
    if (len < 0) {
        free(buff);
        return NULL;
    }
    word_array = my_str_to_word_array(buff);
    free(buff);
    return word_array;
}

char **get_buffer_file(char *filepath)
{
    struct stat st;
    int fd = open(filepath, O_RDONLY);
    char **word_array;

    if (fd == -1 || stat(filepath, &st) == -1) {
        close(fd);
        write(2, "ERROR : can't open file or can't find file.", 43);
        return NULL;
    }
    word_array = create_word_array(&st, fd);
    if (word_array == NULL)
        return NULL;
    return check_buffer_content(word_array);
}

static void add_plane(window_t *window,
    linked_planes_t **planes_list, char **word_array, int *ind)
{
    linked_planes_t *plane = malloc(sizeof(linked_planes_t));

    window->total_planes++;
    plane->plane_info = malloc(sizeof(plane_t));
    plane->plane_info->id = window->id_planes;
    window->id_planes++;
    plane->plane_info->departure_coords = (sfVector2f)
    {convert_str_in_int(word_array[*ind + 1]),
    convert_str_in_int(word_array[*ind + 2])};
    plane->plane_info->arrival_coords = (sfVector2f)
    {convert_str_in_int(word_array[*ind + 3]),
    convert_str_in_int(word_array[*ind + 4])};
    plane->plane_info->speed = convert_str_in_int(word_array[*ind + 5]);
    plane->plane_info->delay = convert_str_in_int(word_array[*ind + 6]);
    *ind += 7;
    get_plane_travel_info(plane);
    add_in_planes_list(planes_list, plane, 1);
    init_hitbox(plane);
}

static void add_tower(window_t *window,
    linked_towers_t **towers_list, char **word_array, int *ind)
{
    linked_towers_t *tower = malloc(sizeof(linked_towers_t));

    tower->id = window->id_towers;
    window->id_towers++;
    tower->tower_pos = (sfVector2f){convert_str_in_int(word_array[*ind + 1]),
    convert_str_in_int(word_array[*ind + 2])};
    tower->radius = convert_str_in_int(word_array[*ind + 3]);
    *ind += 4;
    add_in_towers_list(towers_list, tower);
}

void add_elt(char **word_array, window_t *window,
    linked_planes_t **planes_list, linked_towers_t **towers_list)
{
    int ind = 0;

    while (ind < my_strlen_array(word_array)) {
        if (my_strcmp(word_array[ind], "A") == 0) {
            add_plane(window, planes_list, word_array, &ind);
            continue;
        }
        if (my_strcmp(word_array[ind], "T") == 0) {
            add_tower(window, towers_list, word_array, &ind);
            continue;
        }
    }
}
