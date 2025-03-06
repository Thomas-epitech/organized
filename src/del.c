/*
** EPITECH PROJECT, 2024
** organized
** File description:
** del function
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "organized.h"
#include "my.h"

static int is_nb(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}

static void free_next_device(device_t *dev)
{
    device_t *new_next = dev->next->next;

    print_device(dev->next);
    my_putstr(" deleted.\n");
    free(dev->next);
    dev->next = new_next;
}

static int remove_device(device_t **lab, int device_id)
{
    device_t *current = *lab;

    if (current == NULL)
        return -1;
    if (current->id == device_id) {
        *lab = current->next;
        print_device(current);
        my_putstr(" deleted.\n");
        free(current);
        return 0;
    }
    while (current->next) {
        if (current->next->id == device_id) {
            free_next_device(current);
            return 0;
        }
        current = current->next;
    }
    return -1;
}

int del(void *data, char **args)
{
    int nb_args = get_nb_args(args);
    device_t **lab = (device_t **)data;

    if (nb_args == 0)
        return -1;
    for (int i = 0; i < nb_args; i++) {
        if (!is_nb(args[i]) || remove_device(lab, my_getnbr(args[i])) == -1) {
            my_putstr(args[i]);
            my_putstr(": Invalid id\n");
            return -1;
        }
    }
    return 0;
}
