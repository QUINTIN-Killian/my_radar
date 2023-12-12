/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** puts every letter of every word in it in lowercase
** my_strupcase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int len_str = my_strlen(str);

    for (int i = 0; i < len_str; i++)
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
    return str;
}
