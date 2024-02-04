/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Converts a string into an int.
** convert_str_in_int
*/

#include "my.h"

int convert_str_in_int(char *str)
{
    int ans = 0;
    int elt = 0;

    for (int i = my_strlen(str) - 1; i >= 0; i--) {
        ans = ans + (str[i] - 48) *
        (my_compute_power_rec(10, elt));
        elt++;
    }
    return ans;
}
