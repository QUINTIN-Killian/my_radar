/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** capitalizes the first letter of each word
** my_strcapitalize
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    int v = 1;
    int len_str = my_strlen(str);

    str = my_strlowcase(str);
    for (int i = 0; i < len_str; i++) {
        if (str[i] >= 97 && str[i] <= 122 && v) {
            str[i] = str[i] - 32;
            v = 0;
        }
        if (str[i] >= 48 && str[i] <= 57)
            v = 0;
        if (str[i] < 48 || (str[i] > 57 && str[i] < 65) || (str[i] > 90 &&
        str[i] < 97) || str[i] > 122)
            v = 1;
    }
    return str;
}
