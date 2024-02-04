/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** copies a string in another string
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int len_src = my_strlen(src);

    for (int i = 0; i < len_src; i++)
        dest[i] = src[i];
    dest[len_src] = '\0';
    return dest;
}
