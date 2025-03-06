/*
** EPITECH PROJECT, 2024
** organized
** File description:
** yes, you saw the name of this file.
*/

int my_intcmp(void *a, void *b)
{
    int *n1 = (int *)a;
    int *n2 = (int *)b;

    if (*n1 < *n2)
        return -1;
    if (*n1 > *n2)
        return 1;
    return 0;
}
