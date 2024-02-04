/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** counts and retruns the number of characters in a string
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int ind = 0;

    while (str[ind] != '\0')
        ind++;
    return ind;
}
