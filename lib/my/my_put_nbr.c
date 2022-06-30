/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** display a given nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int n = 1;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb / n) >= 10)
        n *= 10;
    while (n > 0) {
        my_putchar((nb / n) % 10 + 48);
        n /= 10;
    }
    return 0;
}
