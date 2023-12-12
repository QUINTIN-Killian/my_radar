/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** returns 1 if the number is prime and 0 if not
** my_is_prime
*/

#include "my.h"

int my_is_prime(int nb)
{
    if (nb % 2 == 0 && nb != 2)
        return 0;
    if (nb <= 1)
        return 0;
    for (int i = 3; i < nb; i++)
        if ((nb / i) * i == nb && i != nb)
            return 0;
    return 1;
}
