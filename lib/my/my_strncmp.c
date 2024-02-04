/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Reproduce the behavior of the strncmp function
** my_strncmp
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);

    for (int i = 0; i < n; i++) {
        if (i >= len_s1 && i < len_s2)
            return -1;
        if (i < len_s1 && i >= len_s2)
            return 1;
        if (i == len_s1 && i == len_s2)
            return 0;
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}
