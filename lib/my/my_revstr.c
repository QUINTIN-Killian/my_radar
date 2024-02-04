/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** reverses a string
** my_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    char temp;

    for (int i = 0; i < my_strlen(str) / 2; i++) {
        temp = str[i];
        str[i] = str[my_strlen(str) - i - 1];
        str[my_strlen(str) - i - 1] = temp;
    }
    return str;
}
