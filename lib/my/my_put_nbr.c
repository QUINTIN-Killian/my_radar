/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday03-killian.quintin
** File description:
** displays the number given as a parameter
** my_put_nbr
*/

#include "my.h"

static void write_negative_end(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

static void write_positive_end(void)
{
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('7');
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        write_negative_end();
        return 0;
    }
    if (nb == 2147483647) {
        write_positive_end();
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb < 10)
        my_putchar(nb + 48);
    else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return 0;
}
