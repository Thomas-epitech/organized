/*
** EPITECH PROJECT, 2024
** organized
** File description:
** get nth device function
*/

#include <stdio.h>
#include "organized.h"

device_t *get_nth_device(device_t **lab, int n)
{
    device_t *current = *lab;

    for (int i = 0; i < n; i++) {
        if (!current->next)
            return NULL;
        current = current->next;
    }
    return current;
}
