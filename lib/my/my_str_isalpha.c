/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** returns 1 if the string passed as parameter
** only contains alphabetical characters and 0
** if the string contains another type of character
** my_str_isalpha
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    int len_str = my_strlen(str);

    if (len_str == 0)
        return 1;
    for (int i = 0; i < len_str; i++) {
        if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122) {
            return 0;
        }
    }
    return 1;
}
