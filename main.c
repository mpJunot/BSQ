/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-BSQ-junot-hery-nantenaina.montpre
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    bsq_t *sq = malloc(sizeof(bsq_t));
    if (ac != 2)
        return 84;
    if (bsq(av[1], sq) == -1)
        return 84;
    free(sq->map);
    free(sq);
    return 0;
}
