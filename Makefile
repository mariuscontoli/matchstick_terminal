##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for executable
##

CC =	gcc

NAME	=	matchstick

SRC	=	src/matchstick.c\
		src/my_map.c\
		src/utils.c\
		my_printf/my_printf.c\
		my_printf/print_chars.c\
		my_printf/print_ints.c\
		my_printf/print_ints2.c\
		my_printf/utils.c\
		my_printf/utils2.c\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)


%.o: %.c
	$(CC) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $@ $^ -lm

clean:
	rm -rf src/*.o
	rm -rf my_printf/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean
