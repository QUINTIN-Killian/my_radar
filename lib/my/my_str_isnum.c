/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** returns 1 if the string passed as
** parameter only contains digits and 0 otherwise
** my_str_isnum
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int len_str = my_strlen(str);

    if (len_str == 0)
        return 1;
    for (int i = 0; i < len_str; i++) {
        if (str[i] < 48 || str[i] > 57) {
            return 0;
        }
    }
    return 1;
}
