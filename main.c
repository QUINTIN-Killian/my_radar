/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Main file.
** main
*/
/*
USAGE :
    add(&planes_list, node);
    disp(&planes_list);
    del(&planes_list, 777);
    disp(&planes_list);
NOTES :
    - afficher les avions quand leur tour est arrivé grâce a la clock globale
    - faire se déplacer les avions (en prenant en compte leur vitesse)
    - split l'écran en sous-écrans
    - détruire les avions
*/

#include "include/my.h"
#include "include/my_radar.h"

static void destroy_word_array(char **word_array)
{
    for (int i = 0; i < my_strlen_array(word_array); i++)
        free(word_array[i]);
    free(word_array);
}

static void destroy_main_aux(linked_planes_t **planes_list,
    linked_towers_t **towers_list)
{
    linked_planes_t *tmp_plane;
    linked_towers_t *tmp_tower;

    while (*planes_list != NULL) {
        tmp_plane = *planes_list;
        del_in_planes_list(planes_list, tmp_plane->plane_info->id);
    }
    while (*towers_list != NULL) {
        tmp_tower = *towers_list;
        del_in_towers_list(towers_list, tmp_tower->id);
    }
}

static void destroy_main(window_t *window,
    linked_planes_t **planes_list, linked_towers_t **towers_list)
{
    sfClock_destroy(window->timer->clock);
    sfText_destroy(window->timer->time);
    sfFont_destroy(window->timer->time_font);
    sfText_destroy(window->timer->time_value);
    sfFont_destroy(window->timer->time_value_font);
    free(window->timer);
    sfMusic_destroy(window->music->main_music);
    free(window->music);
    sfRenderWindow_destroy(window->window_info);
    sfSprite_destroy(window->background->background_sprite);
    sfTexture_destroy(window->background->background_texture);
    free(window->background);
    destroy_main_aux(planes_list, towers_list);
}

static void print_help(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr(" ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("  path_to_script     The path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -h                print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" 'L' key enable/disable hitboxes and areas.\n");
    my_putstr(" 'S' key enable/disable sprites.\n");
}

static int help(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_help();
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    window_t window;
    linked_planes_t *planes_list = NULL;
    linked_towers_t *towers_list = NULL;
    char **word_array;

    if (help(ac, av))
        return 0;
    word_array = error_handling(ac, av);
    if (word_array == NULL) {
        destroy_word_array(word_array);
        return 84;
    }
    init_window(&window);
    add_elt(word_array, &window, &planes_list, &towers_list);
    destroy_word_array(word_array);
    disp_planes_list(&planes_list);
    disp_towers_list(&towers_list);
    main_screen(&window, &planes_list, &towers_list);
    destroy_main(&window, &planes_list, &towers_list);
    return 0;
}
