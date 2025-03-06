/*
** EPITECH PROJECT, 2024
** organized
** File description:
** get_dev_attribute() function
*/

#include <stdio.h>
#include "organized.h"
#include "my.h"

void *get_attr(device_t *dev, char *attribute)
{
    if (my_strcmp(attribute, "NAME") == 0)
        return dev->name;
    if (my_strcmp(attribute, "ID") == 0)
        return &dev->id;
    if (my_strcmp(attribute, "TYPE") == 0)
        return &dev->material;
    return NULL;
}
