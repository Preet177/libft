# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prsingh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 12:37:58 by prsingh           #+#    #+#              #
#    Updated: 2023/05/27 20:11:23 by prsingh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

CFILES =./SRC/ft_printf.c			\
	   	./SRC/ft_charprint.c		\
	 	./SRC/ft_hexprint.c			\
	 	./SRC/ft_intprint.c			\
	   	./SRC/ft_pointerprint.c		\
	   	./SRC/ft_stringprint.c		\
		./SRC/ft_unsignedprint.c	\
		./SRC/ft_putchar.c			\
		./SRC/ft_putnbr.c			

OBJ = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
