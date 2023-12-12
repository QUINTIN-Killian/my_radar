/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Displays the content of an array of words.
** There must be one word per line, and each word
** must end with ‘\n’, including the last one.
** my_show_word_array
*/

#include "my.h"

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
