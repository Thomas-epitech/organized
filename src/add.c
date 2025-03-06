/*
** EPITECH PROJECT, 2024
** organized
** File description:
** add function
*/

#include <stdlib.h>
#include "organized.h"
#include "my.h"

int get_material(char *mat)
{
    char *materials[] = {"ACTUATOR", "DEVICE", "PROCESSOR",
        "SENSOR", "WIRE"};
    int nb_materials = 5;

    for (int i = 0; i < nb_materials; i++)
        if (!my_strcmp(mat, materials[i]))
            return i;
    my_putstr(mat);
    my_putstr(": Invalid material\n");
    return -1;
}

static int get_next_id(device_t **lab)
{
    int max = -1;
    device_t *current = *lab;

    while (current) {
        if (current->id > max)
            max = current->id;
        current = current->next;
    }
    return max + 1;
}

void create_device(device_t **lab, material_t mat, char *name)
{
    device_t *dev = malloc(sizeof(device_t));

    dev->name = my_strdup(name);
    dev->material = mat;
    dev->id = get_next_id(lab);
    dev->next = *lab;
    *lab = dev;
    print_device(dev);
    my_putstr(" added.\n");
}

int add(void *data, char **args)
{
    int nb_args = get_nb_args(args);
    device_t **lab = (device_t **)data;
    int material_idx;

    if (nb_args % 2 != 0 || nb_args == 0)
        return -1;
    for (int i = 0; i < nb_args; i += 2) {
        material_idx = get_material(args[i]);
        if (material_idx == -1)
            return -1;
        create_device(lab, (material_t)material_idx, args[i + 1]);
    }
    return 0;
}
