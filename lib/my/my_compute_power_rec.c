/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** returns the first argument raised to the power p, where p is the second
** argument
** my_compute_power_rec
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p > 0)
        return nb * my_compute_power_rec(nb, p - 1);
    return 0;
}
