/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-BSQ-junot-hery-nantenaina.montpre
** File description:
** my_nblen
*/

int my_nblen(int nb)
{
    int n = 1;
    int count = 0;

    if (nb < 0) {
        count++;
        nb *= -1;
    }
    while ((nb / n) >= 10)
        n *= 10;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}
