/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** task08
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(str, src);
    return str;
}
