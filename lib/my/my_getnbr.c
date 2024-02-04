/*
** EPITECH PROJECT, 2023
** undefined
** File description:
**  returns a number, sent to the function as a string
** my_getnbr
*/

#include "my.h"

static int is_number(char a)
{
    if (a >= 48 && a <= 57)
        return 1;
    return 0;
}

static int det_sign(char const *str, int *ind, int *neg)
{
    while (str[*ind] == '-') {
        *neg = *neg + 1;
        *ind = *ind + 1;
    }
}

int my_getnbr(char const *str)
{
    int size_len = my_strlen(str);
    int neg = 0;
    int ind = 0;
    int ans = 0;

    det_sign(str, &ind, &neg);
    while (is_number(str[ind])) {
        if (ind < size_len - 1 && is_number(str[ind + 1])) {
            ans = ans + (str[ind] - 48);
            ans = ans * 10;
            ind++;
        } else {
            ans = ans + (str[ind] - 48);
            ind++;
        }
    }
    if (neg % 2 == 1)
        return ans * (-1);
    return ans;
}
