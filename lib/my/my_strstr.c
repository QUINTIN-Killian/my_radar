/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Reproduces the behavior of the strstr function
** my_strstr
*/

#include "my.h"

static int is_to_find(char *str, char const *to_find, int ind)
{
    int len_to_find = my_strlen(to_find);

    for (int i = 0; i < len_to_find; i++) {
        if (str[ind + i] != to_find[i])
            return 0;
        if (i == len_to_find - 1)
            return 1;
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int len_to_find = my_strlen(to_find);
    int len_str = my_strlen(str);

    if (len_to_find == 0)
        return str;
    for (int i = 0; i < len_str; i++) {
        if (is_to_find(str, to_find, i))
            return &str[i];
    }
    return NULL;
}
