/*
** EPITECH PROJECT, 2024
** organized
** File description:
** my itoa
*/

#include "my.h"
#include <stdlib.h>

static int digit_counter(int nb)
{
    int i = 0;

    if (nb == 0) {
        return 1;
    }
    while (nb != 0) {
        nb /= 10;
        i++;
    }
    return i;
}

char *my_itoa(int nb)
{
    int digit_nb = digit_counter(nb);
    char *result = malloc(sizeof(char) * digit_nb);

    for (int i = digit_nb; i > 0; i--) {
        result[digit_nb - i] = (nb / my_compute_power_rec(10, i - 1) + 48);
        nb %= my_compute_power_rec(10, i - 1);
    }
    return result;
}
