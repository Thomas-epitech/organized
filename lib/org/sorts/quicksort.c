/*
** EPITECH PROJECT, 2024
** organized
** File description:
** quick sort function
*/

#include "organized.h"
#include "my.h"

static int partition(device_t **lab, int begin, int end)
{
    device_t *pivot = get_nth_device(lab, begin);
    int pivot_idx = get_device_idx(lab, pivot);
    int store_idx = pivot_idx + 1;

    for (int i = pivot_idx + 1; i < end; i++)
        if (my_strcmp(get_nth_device(lab, i)->name, pivot->name) <= 0) {
            store_idx++;
            swap_devices(lab, get_nth_device(lab, i),
                get_nth_device(lab, store_idx));
        }
    swap_devices(lab, pivot, get_nth_device(lab, store_idx - 1));
    return get_device_idx(lab, pivot);
}

static void main_loop(device_t **lab, int begin, int end)
{
    int pivot;

    if (begin < end) {
        pivot = partition(lab, begin, end);
        if (pivot == -1)
            return;
        my_put_nbr(pivot);
        my_putstr(" ");
        my_put_nbr(begin);
        my_putstr(" ");
        my_put_nbr(end);
        my_putstr("   ");
        main_loop(lab, begin, pivot);
        main_loop(lab, pivot + 1, end);
    }
}

void quicksort(device_t **lab)
{
    main_loop(lab, 0, get_nb_devices(*lab) - 1);
}
