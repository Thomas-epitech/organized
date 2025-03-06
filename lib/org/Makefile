##
## EPITECH PROJECT, 2024
## organized
## File description:
## lib org Makefile
##

CC = gcc

NAME = liborg.a

SRC = get_nb_args.c \
	  get_nb_devices.c \
	  print_device.c \
	  get_nth_device.c \
	  get_device_idx.c \
	  swap_devices.c \
	  linked_list_to_array.c \
	  get_dev_attribute.c \
	  my_rev_list.c \
	  sorts/mergesort.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Wshadow -I../../include/

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
