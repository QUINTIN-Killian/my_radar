/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Concatenates 2 strings.
** concat_str
*/

#include "my.h"

int get_len_total(int nb_elt, va_list args_temp)
{
    int len_total = 0;

    for (int i = 0; i < nb_elt; i++)
        len_total = len_total + my_strlen(va_arg(args_temp, char *));
    va_end(args_temp);
    return len_total;
}

char *add_in_str(char *ans, char *str_temp, int *ind)
{
    for (int k = 0; k < my_strlen(str_temp); k++) {
        ans[*ind] = str_temp[k];
        *ind = *ind + 1;
    }
    return ans;
}

char *concat_str(int nb_elt, ...)
{
    va_list args;
    va_list args_temp;
    int ind = 0;
    char *ans;
    char *str_temp;
    int len_total = 0;

    va_start(args_temp, nb_elt);
    len_total = get_len_total(nb_elt, args_temp);
    ans = malloc(sizeof(char) * (len_total + 1));
    va_start(args, nb_elt);
    for (int i = 0; i < nb_elt; i++) {
        str_temp = va_arg(args, char *);
        ans = add_in_str(ans, str_temp, &ind);
    }
    va_end(args);
    ans[len_total] = '\0';
    return ans;
}
