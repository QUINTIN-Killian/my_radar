/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** returns the smallest prime number that is greater than, or equal to,
** the number given as a parameter.
** my_find_prime_sup
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb))
        return nb;
    else
        return my_find_prime_sup(nb + 1);
}
