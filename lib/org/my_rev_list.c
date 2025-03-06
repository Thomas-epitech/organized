/*
** EPITECH PROJECT, 2024
** my revlist
** File description:
** task
*/

#include "organized.h"
#include "my.h"
#include <stdio.h>

void rev_list(device_t **begin)
{
    device_t *previous = NULL;
    device_t *current = *begin;
    device_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *begin = previous;
}
