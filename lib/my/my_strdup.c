/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dup = malloc(sizeof(char) * my_strlen(src));
    my_strcpy(dup, src);
    return dup;
}
