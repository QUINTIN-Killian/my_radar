/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Prints a part of a string.
** my_put_elts
*/

#include "my.h"

int my_parsing(char *format, int ind_start, int ind_end)
{
    if (ind_start >= ind_end || ind_start >= my_strlen(format))
        return 0;
    my_putchar(format[ind_start]);
    my_parsing(format, ind_start + 1, ind_end);
}
