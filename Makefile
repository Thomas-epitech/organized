##
## EPITECH PROJECT, 2024
## organized
## File description:
## Makefile
##

CC = gcc

NAME = organized

MY_LIB = lib/my/libmy.a

ORG_LIB = lib/org/liborg.a

SRC = src/main.c	\
	  src/add.c	\
	  src/del.c	\
	  src/sort.c	\
	  src/disp.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Wshadow -Iinclude

LDFLAGS = -Llib/shell -lshell -Llib/org -lorg -Llib/my -lmy

all: $(NAME)

$(MY_LIB):
	make -C lib/my

$(ORG_LIB):
	make -C lib/org

$(NAME): $(MY_LIB) $(ORG_LIB) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
