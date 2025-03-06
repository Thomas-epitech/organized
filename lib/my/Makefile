##
## EPITECH PROJECT, 2024
## organized
## File description:
## lib makefile
##

CC = gcc

NAME = libmy.a

SRC = my_getnbr.c	\
	  my_putchar.c	\
	  my_put_nbr.c	 \
	  my_putstr.c	\
	  my_strcmp.c	\
	  my_strlen.c	\
	  my_strncmp.c	\
	  my_strdup.c	\
	  my_strcpy.c	\
	  my_compute_power_rec.c	\
	  my_itoa.c	\
	  my_intcmp.c

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
