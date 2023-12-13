/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** convert int to str
** convert_int_to_str
*/

#include "my.h"

char *convert_int_to_str(int nbr)
{
    int intlen = my_intlen(nbr);
    char *str = malloc(sizeof(char) * (intlen + 1));
    int n = 1;

    for (int i = 0; i < intlen; i++) {
        str[i] = nbr / my_compute_power_rec(10, intlen - n) + 48;
        nbr = nbr - (nbr / my_compute_power_rec(10, intlen - n) *
        my_compute_power_rec(10, intlen - n));
        n++;
    }
    str[intlen] = '\0';
    return str;
}
