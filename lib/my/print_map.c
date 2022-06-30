/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-BSQ-junot-hery-nantenaina.montpre
** File description:
** print_map
*/

#include "my.h"

void excep(char *map, int i, int j)
{
    if (map[i + j] == '.')
        map[i + j] = 'x';
}

int disp_resolve_map(char *map, bsq_t *s, int len)
{
    int i = 0;

    for (int c = 0; c < s->big_square; c++, s->save_i--) {
        i = s->save_i * (s->width + 1) + (len + 1);
        for (int j = s->save_j, sc = 0; sc < s->big_square; j--, sc++) {
            if (s->big_square > 1)
                map[i + j] = 'x';
            excep(map, i, j);
        }
    }
    for (int n = 0; n != (len + 1); n++)
        ++map;
    write(1, map, (s->height * s->width + s->height));
    return 0;
}
