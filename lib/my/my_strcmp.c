/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** task06
*/

#include "my.h"

int my_strcmp(void *a, void *b)
{
    char *s1 = (char *)a;
    char *s2 = (char *)b;

    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if ((s1[i] == '\0') ^ (s2[i] == '\0'))
            return s1[i] != '\0' ? 1 : -1;
        if (s1[i] != s2[i])
            return s1[i] > s2[i] ? 1 : -1;
    }
    return 0;
}
