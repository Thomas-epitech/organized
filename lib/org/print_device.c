/*
** EPITECH PROJECT, 2024
** organized
** File description:
** print device
*/

#include "organized.h"
#include "my.h"

void print_device(device_t *dev)
{
    char *materials[] = {"ACTUATOR", "DEVICE", "PROCESSOR",
        "SENSOR", "WIRE"};

    my_putstr(materials[(int)dev->material]);
    my_putstr(" n°");
    my_put_nbr(dev->id);
    my_putstr(" - \"");
    my_putstr(dev->name);
    my_putchar('\"');
}
