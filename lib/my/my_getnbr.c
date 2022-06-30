/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** get nb in a string
*/
#include <limits.h>

int neg_or_pos(char const *str, int res)
{
    int i = 0;
    int sign = 0;
    int n = 0;

    while (str[i] != '\0') {
        if (str[i] == '-' || str[i] == '+') {
            if (str[i] == '-')
                sign++;
        } else
            break;
        i++;
    }
    if ((sign % 2) == 1)
        n = -1;
    else
        n = 1;
    return (res * n);
}

int my_getnbr(char const *str, char c)
{
    int i = 0;
    long long nb = 0;

    while (str[i] != c) {
        while (str[i] >= '0' && str[i] <= '9') {
            nb = (nb * 10) + str[i] - 48;
            if (nb > INT_MAX || nb < INT_MIN)
                return 0;
            i++;
        }
        if (((str[i] >= 'a') && (str[i] <= 'z'))
        || ((str[i] >= 'A') && (str[i] <= 'Z')))
            break;
        i++;
    }
    nb = neg_or_pos(str, nb);
    return nb;
}
