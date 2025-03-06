/*
** EPITECH PROJECT, 2024
** organized
** File description:
** get nb devices
*/

#include <stdio.h>
#include "organized.h"

int get_nb_devices(device_t *lab)
{
    int count = 0;

    while (lab != NULL) {
        count++;
        lab = lab->next;
    }
    return count;
}
