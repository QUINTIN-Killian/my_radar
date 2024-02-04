/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** returns 1 if the string passed as parameter
** only contains lowercase alphabetical
** characters and 0 otherwise
** my_str_islower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int len_str = my_strlen(str);

    if (len_str == 0)
        return 1;
    for (int i = 0; i < len_str; i++) {
        if (str[i] < 97 || str[i] > 122) {
            return 0;
        }
    }
    return 1;
}
