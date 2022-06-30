/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-BSQ-junot-hery-nantenaina.montpre
** File description:
** bsq
*/

#ifndef BSQ_H_
    #define BSQ_H_
    #define RED     "\033[0;31m"
    #define GREEN   "\033[0;32m"
    #define BLACK   "\033[0;30m"
    #define YELLOW  "\033[0;33m"
    #define BLUE    "\033[0;34m"
    #define PURPLE  "\033[0;35m"
    #define CYAN    "\033[0;36m"
    #define WHITE   "\033[0;37m"
    #define RESET   "\033[0m"

typedef struct bsq_s {
    int width;
    int height;
    int save_i;
    int save_j;
    int big_square;
    char *map;
    int size;
}bsq_t;

#endif /* !BSQ_H_ */
