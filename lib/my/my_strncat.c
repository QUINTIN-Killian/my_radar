/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** concatenates n characters of the src
** string to the end of the dest string
** my_strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len_dest = my_strlen(dest);

    for (int i = 0; i < nb; i++) {
        dest[len_dest + i] = src[i];
    }
    dest[len_dest + nb] = '\0';
    return dest;
}
