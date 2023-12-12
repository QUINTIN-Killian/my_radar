/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday03-killian.quintin
** File description:
** displays if the number in argument is positive or negative
** my_isneg
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return 0;
}
