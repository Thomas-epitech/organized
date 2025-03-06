/*
** EPITECH PROJECT, 2024
** organized
** File description:
** organized header (not organized)
*/

#ifndef ORG_H
    #define ORG_H
typedef enum {
    ACTUATOR,
    DEVICE,
    PROCESSOR,
    SENSOR,
    WIRE
} material_t;

typedef struct device {
    material_t material;
    char *name;
    int id;
    struct device *next;
} device_t;

typedef struct {
    int l;
    int r;
} array_bounds_t;

//Useful linked list function
int get_nb_args(char **);
int get_nb_devices(device_t *);
void print_device(device_t *);
int get_device_idx(device_t **, device_t *);
device_t *get_nth_device(device_t **, int);
void swap_devices(device_t **, device_t *, device_t *);
device_t **linked_list_to_array(device_t **);
void *get_attr(device_t *, char *);
void rev_list(device_t **);
void create_device(device_t **, material_t, char *);

//Sort functions
void mergesort(device_t **, char *);
#endif
