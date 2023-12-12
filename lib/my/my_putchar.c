/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** writes a character
** my_putchar
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
