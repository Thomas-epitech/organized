/*
** EPITECH PROJECT, 2024
** organized
** File description:
** switch devices function
*/

#include "organized.h"

void handle_adjacent_dev(device_t **lab, device_t *dev1, device_t *dev2)
{
    int dev1_idx = get_device_idx(lab, dev1);
    int dev2_idx = get_device_idx(lab, dev2);
    device_t *left = dev1_idx > dev2_idx ? dev2 : dev1;
    device_t *right = dev1_idx < dev2_idx ? dev2 : dev1;

    left->next = right->next;
    if (get_device_idx(lab, left) == 0)
        *lab = right;
    else
        get_nth_device(lab, get_device_idx(lab, left) - 1)->next = right;
    right->next = left;
}

void handle_non_adjacent_dev(device_t **lab, device_t *dev1, device_t *dev2)
{
    int dev1_idx = get_device_idx(lab, dev1);
    int dev2_idx = get_device_idx(lab, dev2);
    device_t *tmp = dev1->next;

    dev1->next = dev2->next;
    if (dev1_idx == 0)
        *lab = dev2;
    else
        get_nth_device(lab, get_device_idx(lab, dev1) - 1)->next = dev2;
    dev2->next = tmp;
    if (dev2_idx == 0)
        *lab = dev1;
    else
        get_nth_device(lab, get_device_idx(lab, dev2) - 1)->next = dev1;
}

void swap_devices(device_t **lab, device_t *dev1, device_t *dev2)
{
    int dev1_idx = get_device_idx(lab, dev1);
    int dev2_idx = get_device_idx(lab, dev2);

    if (dev1 == dev2)
        return;
    if (dev1_idx == dev2_idx - 1 || dev1_idx == dev2_idx + 1)
        handle_adjacent_dev(lab, dev1, dev2);
    else
        handle_non_adjacent_dev(lab, dev1, dev2);
}
