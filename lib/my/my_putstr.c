/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** displays one by one the characters of a string
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int ind = 0;

    while (str[ind] != '\0') {
        my_putchar(str[ind]);
        ind++;
    }
    return 0;
}
