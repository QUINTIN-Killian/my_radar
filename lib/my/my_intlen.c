/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Returns the len of an integer
** my_intlen
*/

int my_intlen(int n)
{
    int ans = 1;

    if (n < 0)
        n = n * (-1);
    while (n > 9) {
        n = n / 10;
        ans++;
    }
    return ans;
}
