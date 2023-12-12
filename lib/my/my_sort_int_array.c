/*
** EPITECH PROJECT, 2023
** undefined
** File description:
**  sorts an integer array in ascending order
** my_sort_int_array
*/

#include "my.h"

static void comparison(int *array, int ind_a, int ind_b)
{
    int temp;

    if (array[ind_a] > array[ind_b]) {
        temp = array[ind_a];
        array[ind_a] = array[ind_b];
        array[ind_b] = temp;
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int k = 0; k < size; k++)
        for (int i = 0; i < size - 1; i++)
            comparison(array, i, i + 1);
}
