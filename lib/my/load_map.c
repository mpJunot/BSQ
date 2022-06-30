/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-BSQ-junot-hery-nantenaina.montpre
** File description:
** load_map
*/

#include "my.h"

int **int_map(char *old_map, int w, int h, int len)
{
    int **map = malloc(sizeof(int *) * h);
    int x = 0;
    int n = 0;

    if (old_map[0] == '\0')
        return NULL;
    for (int y = (len + 1); n < h; n++, y++) {
        map[n] = malloc(sizeof(int) * w);
        for (x = 0; old_map[y] != '\n' && old_map[y] != '\0'; x++, y++) {
            if (old_map[y] >= 48 && old_map[y] <= 57)
                y++;
            if (old_map[y] == '.')
                map[n][x] = 1;
            else if (old_map[y] == 'o')
                map[n][x] = 0;
            else
                return NULL;
        }
    }
    return map;
}

int get_width(char *map, int len)
{
    int x = len + 1;
    int count = 0;

    while (map[x] != '\n') {
        x++;
        count++;
    }
    return count;
}

int check_map(char *map, bsq_t *s, int len)
{
    int c = 0;
    int chek_line = (s->height * s->width + s->height) + len + 1;

    for (int x = 0; map[x] != '\0'; x++) {
        if (map[x] == '\n')
            c++;
    }
    if ((c - 1) != s->height || chek_line != s->size || map[0] == '-')
        return 1;
    return 0;
}

int **load_map(char *filepath, bsq_t *bsq)
{
    int fd = open(filepath, O_RDONLY);
    struct stat size;
    stat(filepath, &size);
    bsq->map = malloc(sizeof(char) * (size.st_size + 1));

    if (stat(filepath, &size) == -1 || fd == -1)
        return NULL;
    if (read(fd, bsq->map, size.st_size) == -1 || bsq->map == NULL)
        return NULL;
    bsq->map[size.st_size] = '\0';
    close(fd);
    if (bsq->map[0] != '\0') {
        bsq->height = my_getnbr(bsq->map, '\n');
        bsq->width = get_width(bsq->map, my_nblen(bsq->height));
    }
    bsq->size = size.st_size;
    return int_map(bsq->map, bsq->width, bsq->height, my_nblen(bsq->height));
}
