/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Reproduce the behavior of the strcmp function
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);
    int len = len_s1;

    if (len_s1 < len_s2)
        len = len_s2;
    for (int i = 0; i < len; i++) {
        if (i >= len_s1 && i < len_s2)
            return -1;
        if (i < len_s1 && i >= len_s2)
            return 1;
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}
