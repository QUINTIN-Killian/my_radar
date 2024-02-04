/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** swaps two integers in parameter
** my_swap
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
