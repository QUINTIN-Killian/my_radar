/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** returns the square root (if it is a whole number) of the
** number given as argument
** my_compute_square_root
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    if (nb <= 0)
        return 0;
    for (int i = 0; i <= nb; i++)
        if (i * i == nb)
            return i;
    return 0;
}
