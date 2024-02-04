/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** allocates memory and copies the string given
** as argument in it
** my_strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int len_src = my_strlen(src);
    char *str = malloc(sizeof(char) * (len_src + 1));

    for (int i = 0; i < len_src; i++)
        str[i] = src[i];
    str[len_src] = '\0';
    return str;
}
