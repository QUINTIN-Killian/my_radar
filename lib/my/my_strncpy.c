/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** copies n characters from a string into another
** my_strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int len_src = my_strlen(src);

    for (int i = 0; i < n; i++) {
        if (i >= len_src) {
            dest[i] = '\0';
            break;
        } else
            dest[i] = src[i];
    }
    return dest;
}
