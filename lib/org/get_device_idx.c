/*
** EPITECH PROJECT, 2024
** organized
** File description:
** get device index function
*/

#include <stdio.h>
#include "organized.h"

int get_device_idx(device_t **lab, device_t *dev)
{
    device_t *current = *lab;
    int idx;

    for (idx = 0; dev != current; idx++) {
        if (!current->next)
            return -1;
        current = current->next;
    }
    return idx;
}
