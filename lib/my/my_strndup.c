/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** allocates memory and copies the n string elkements given
** as argument in it
** my_strndup
*/

#include "my.h"

char *my_strndup(char const *src, int n)
{
    int len_src = my_strlen(src);
    char *str;
    int max;

    if (n > my_strlen(src)) {
        str = malloc(sizeof(char) * (my_strlen(src) + 1));
        max = my_strlen(src);
    } else {
        str = malloc(sizeof(char) * (n + 1));
        max = n;
    }
    for (int i = 0; i < n; i++) {
        str[i] = src[i];
        if (n >= my_strlen(src))
            break;
    }
    str[max] = '\0';
    return str;
}
