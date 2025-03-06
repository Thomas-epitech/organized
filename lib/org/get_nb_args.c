/*
** EPITECH PROJECT, 2024
** organized
** File description:
** get nb args
*/

#include <stdio.h>

int get_nb_args(char **args)
{
    int i;

    for (i = 0; args[i] != NULL; i++);
    return i;
}
