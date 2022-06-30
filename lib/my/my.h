/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include "bsq.h"
    #include <stdio.h>

    int my_put_nbr(int nb);
    int my_strlen(char const *str);
    int my_putstr(char const *str);
    void my_putchar(char c);
    int **load_map(char *filepath, bsq_t *bsq);
    char **my_str_to_word_array(char *buff, char c);
    void print_map(int **map, int h, int w);
    int **minim(int **map, int w, int h);
    int bsq(char *filepath, bsq_t *sq);
    int my_strtol(char *str, char **endptr);
    int my_getnbr(char const *str, char c);
    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    int my_nblen(int nb);
    int free_intarray(int **map, int h);
    int disp_resolve_map(char *map, bsq_t * s, int len);
    int check_map(char *map, bsq_t *s, int len);
    int bsq(char *filepath, bsq_t *sq);

#endif /* !MY_H_ */