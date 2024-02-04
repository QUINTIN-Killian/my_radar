/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** manage the errors
** error_handling
*/

#include "include/my.h"
#include "include/my_radar.h"

char **error_handling(int ac, char **av)
{
    if (ac < 2) {
        write(2, "ERROR : not enough arguments given ", 35);
        write(2, "(./<bin> -h to get help).", 25);
        return NULL;
    }
    if (ac > 2) {
        write(2, "ERROR : too much arguments given ", 33);
        write(2, "(./<bin> -h to get help).", 25);
        return NULL;
    }
    return get_buffer_file(av[1]);
}
