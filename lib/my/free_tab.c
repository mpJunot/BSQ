/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-BSQ-junot-hery-nantenaina.montpre
** File description:
** free_tab
*/

#include "my.h"

int free_intarray(int **map, int h)
{
    if (map == NULL)
        return 84;
    for (int n = 0; n < h; n++)
        free(map[n]);
    free(map);
    return 0;
}
