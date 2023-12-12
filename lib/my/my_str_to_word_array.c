/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Splits a string into words.
** my_str_to_word_array
*/

#include "my.h"

static int is_alphanum(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 1;
    return 0;
}

static int det_nb_word(char const *str)
{
    int ans = 0;
    int a = 1;

    for (int i = 0; i < my_strlen(str); i++) {
        if (is_alphanum(str[i]) && a == 1) {
            ans++;
            a = 0;
        }
        if (!is_alphanum(str[i])) {
            a = 1;
        }
    }
    return ans;
}

static int det_len_word(char const *str, int ind)
{
    int ans = 0;

    while (is_alphanum(str[ind + ans]) && (ind + ans) < my_strlen(str)) {
        ans++;
    }
    return ans;
}

static void set_word(char **tab, char const *str, int *start, int *ind_tab)
{
    int i;

    while (*start < my_strlen(str)) {
        i = 0;
        tab[*ind_tab] = malloc(sizeof(char) * det_len_word(str, *start) + 1);
        while (*start < my_strlen(str) && is_alphanum(str[*start])) {
            tab[*ind_tab][i] = str[*start];
            i++;
            *start = *start + 1;
        }
        tab[*ind_tab][i] = '\0';
        *start = *start + 1;
        *ind_tab = *ind_tab + 1;
        while (*start < my_strlen(str) && !is_alphanum(str[*start]))
            *start = *start + 1;
    }
}

char **my_str_to_word_array(char const *str)
{
    char **tab;
    int ind_tab = 0;
    int start = 0;

    if (my_strlen(str) == 0 || det_nb_word(str) == 0) {
        tab = malloc(sizeof(char *));
        tab[0] = NULL;
        return tab;
    }
    tab = malloc(sizeof(char *) * (det_nb_word(str) + 1));
    while (start < my_strlen(str) && !is_alphanum(str[start])) {
        start++;
    }
    set_word(tab, str, &start, &ind_tab);
    tab[det_nb_word(str)] = NULL;
    return tab;
}
