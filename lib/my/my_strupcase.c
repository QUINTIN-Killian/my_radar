/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** puts every letter of every word in it in uppercase
** my_strupcase
*/

#include "my.h"

char *my_strupcase(char *str)
{
    int len_str = my_strlen(str);

    for (int i = 0; i < len_str; i++)
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
    return str;
}
