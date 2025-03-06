/*
** EPITECH PROJECT, 2024
** organized
** File description:
** main
*/

#include <stdlib.h>
#include "shell.h"
#include "organized.h"

static void free_lab(device_t **lab)
{
    device_t *curr_dev = *lab;
    device_t *next = NULL;
    int nb_devices = get_nb_devices(curr_dev);

    for (int i = 0; i < nb_devices; i++) {
        next = curr_dev->next;
        free(curr_dev->name);
        free(curr_dev);
        curr_dev = next;
    }
    free(lab);
}

int main(void)
{
    device_t **lab = malloc(sizeof(device_t *));
    int return_value = 0;

    *lab = NULL;
    if (workshop_shell(lab) == -1)
        return_value = 84;
    free_lab(lab);
    return return_value;
}
