/*
** EPITECH PROJECT, 2024
** organized
** File description:
** sort function
*/

#include "organized.h"
#include "my.h"

static int is_valid_attr(char *attribute)
{
    char *possible_attributes[] = {"NAME", "ID", "TYPE"};
    int nb_possible_attributes = 3;

    for (int i = 0; i < nb_possible_attributes; i++)
        if (my_strcmp(attribute, possible_attributes[i]) == 0)
            return 1;
    my_putstr(attribute);
    my_putstr(": Invalid attribute\n");
    return 0;
}

int sort(void *data, char **args)
{
    device_t **lab = data;
    int nb_args = get_nb_args(args);

    if (nb_args == 0) {
        my_putstr("sort command takes at least one argument\n");
    }
    for (int i = 0; i < nb_args; i++) {
        if (!is_valid_attr(args[i]))
            return -1;
        mergesort(lab, args[i]);
        if (i != nb_args - 1 && my_strcmp(args[i + 1], "-r") == 0) {
            rev_list(lab);
            i++;
        }
    }
    return 0;
}
