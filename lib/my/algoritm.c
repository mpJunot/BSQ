/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-BSQ-junot-hery-nantenaina.montpre
** File description:
** algoritm
*/

#include "my.h"
#include <stdio.h>

bsq_t *init(bsq_t *sq)
{
    sq->big_square = 1;
    sq->save_i = 0;
    sq->save_j = 0;
    return sq;
}

void neighboor(int **map, int i, int j)
{
    if (map[i][j] == 1) {
        int min = map[i][j - 1];
        if (map[i - 1][j - 1] < min)
            min = map[i - 1][j - 1];
        if (map[i - 1][j] < min)
            min = map[i - 1][j];
        map[i][j] = min + 1;
    }
}

void save_big_square(int **map, bsq_t *sq, int i, int j)
{
    if (map[i][j] > sq->big_square) {
        sq->save_i = i;
        sq->save_j = j;
        sq->big_square = map[i][j];
    }
}

int algo_s(int **map, bsq_t *sq)
{
    if (check_map(sq->map, sq, my_nblen(sq->height)) == 1 || map == NULL)
        return -1;
    for (int i = 1; i < sq->height; ++i) {
        for (int j = 1; j < sq->width; j++) {
            if (sq->height >= 2)
                neighboor(map, i, j);
            save_big_square(map, sq, i, j);
        }
    }
    free_intarray(map, sq->height);
    return 0;
}

int bsq(char *filepath, bsq_t *sq)
{
    sq = init(sq);
    int **map = load_map(filepath, sq);
    if (algo_s(map, sq) == -1 || map == NULL)
        return -1;
    disp_resolve_map(sq->map, sq, my_nblen(sq->height));
    return 0;
}
