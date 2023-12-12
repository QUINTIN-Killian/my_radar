/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** turns the command-line given arguments into
** a single string. Arguments are to be
** separated by ‘\n’.
** concat_params
*/

#include "my.h"

char *concat_params(int argc, char **argv)
{
    int total_len = 0;
    int ind = 0;
    char *str;

    for (int i = 0; i < argc; i++)
        total_len += my_strlen(argv[i]);
    str = malloc(sizeof(char) * (total_len + argc) - 1);
    for (int i = 0; i < argc; i++) {
        for (int k = 0; k < my_strlen(argv[i]); k++) {
            str[ind] = argv[i][k];
            ind++;
        }
        str[ind] = '\n';
        ind++;
    }
    str[(total_len + argc) - 1] = '\0';
    return str;
}
