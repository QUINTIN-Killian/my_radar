/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Return the length of an array of strings.
** my_strlen_array
*/

#include "my.h"

int my_strlen_array(char **array)
{
    int ind = 0;

    while (array[ind] != NULL)
        ind++;
    return ind;
}
