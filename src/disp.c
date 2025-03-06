/*
** EPITECH PROJECT, 2024
** organized
** File description:
** disp function
*/

#include "organized.h"
#include "shell.h"
#include "my.h"

int disp(void *data, char **args)
{
    device_t *curr_dev = *(device_t **)data;

    if (get_nb_args(args) != 0) {
        my_putstr("disp command does not take any arguments\n");
        return -1;
    }
    while (curr_dev) {
        print_device(curr_dev);
        my_putchar('\n');
        curr_dev = curr_dev->next;
    }
    return 0;
}
