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
    if (ac != 2)
        return NULL;
    return get_buffer_file(av[1]);
}
