/*
** EPITECH PROJECT, 2024
** organized
** File description:
** merge sort
*/

#include <stdlib.h>
#include "my.h"
#include "organized.h"

static void **get_left_subarray(device_t **arr, int left, int left_len)
{
    void **l = malloc(sizeof(device_t *) * left_len);

    for (int i = 0; i < left_len; i++)
        l[i] = arr[left + i];
    return l;
}

static void **get_right_subarray(device_t **arr, int middle, int right_len)
{
    void **r = malloc(sizeof(device_t *) * right_len);

    for (int i = 0; i < right_len; i++)
        r[i] = arr[middle + 1 + i];
    return r;
}

static void merge(device_t **arr, array_bounds_t *b, char *att,
    int (*compare)(void *, void *))
{
    int middle = b->l + (b->r - b->l) / 2;
    int left_len = middle - b->l + 1;
    int right_len = b->r - middle;
    int l_i = 0;
    int r_i = 0;
    void **l = get_left_subarray(arr, b->l, left_len);
    void **r = get_right_subarray(arr, middle, right_len);

    while (l_i < left_len && r_i < right_len) {
        arr[b->l + l_i + r_i] = compare(get_attr(l[l_i], att),
            get_attr(r[r_i], att)) <= 0 ? l[l_i] : r[r_i];
        if (compare(get_attr(l[l_i], att), get_attr(r[r_i], att)) <= 0)
            l_i++;
        else
            r_i++;
    }
    for (; l_i < left_len; l_i++)
        arr[b->l + l_i + r_i] = l[l_i];
    free(l);
    free(r);
}

static void main_loop(device_t **arr, int left, int right, char *to_cmp)
{
    int middle;
    int (*compare_function)(void *, void *);

    if (my_strcmp(to_cmp, "NAME") == 0)
        compare_function = &my_strcmp;
    else
        compare_function = &my_intcmp;
    if (left < right) {
        middle = left + (right - left) / 2;
        main_loop(arr, left, middle, to_cmp);
        main_loop(arr, middle + 1, right, to_cmp);
        merge(arr, &(array_bounds_t){left, right}, to_cmp, compare_function);
    }
}

void mergesort(device_t **lab, char *attribute_to_sort)
{
    device_t **array = linked_list_to_array(lab);
    device_t *current;
    int nb_devices = get_nb_devices(*lab);

    main_loop(array, 0, nb_devices - 1, attribute_to_sort);
    if (nb_devices != 0) {
        *lab = array[0];
        current = *lab;
        for (int i = 1; i < nb_devices + 1; i++) {
            current->next = i == nb_devices ? NULL : array[i];
            current = current->next;
        }
    }
}
