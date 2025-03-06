/*
** EPITECH PROJECT, 2024
** organized
** File description:
** linked list to array
*/

#include <stdlib.h>
#include "organized.h"
#include "my.h"

device_t **linked_list_to_array(device_t **ll)
{
    int nb_dev = get_nb_devices(*ll);
    device_t *current = *ll;
    device_t **array = malloc(sizeof(device_t *) * nb_dev);

    for (int i = 0; i < nb_dev; i++) {
        array[i] = current;
        current = current->next;
    }
    return array;
}
