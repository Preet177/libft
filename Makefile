# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prsingh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 14:40:17 by prsingh           #+#    #+#              #
#    Updated: 2023/04/12 16:38:11 by prsingh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PRINTF_DIR = ./Print_f

SRCS =  ft_isalpha.c \
        ft_isdigit.c \
        ft_isalnum.c \
        ft_isascii.c \
        ft_isprint.c \
        ft_strlen.c \
        ft_memset.c \
        ft_bzero.c \
        ft_memcpy.c \
        ft_memmove.c \
        ft_strlcpy.c \
        ft_strlcat.c \
        ft_toupper.c \
        ft_tolower.c \
        ft_strchr.c \
        ft_strrchr.c \
        ft_strncmp.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_strnstr.c \
        ft_atoi.c \
        ft_calloc.c \
        ft_strdup.c \
        ft_substr.c \
        ft_strjoin.c \
        ft_strtrim.c \
        ft_split.c \
        ft_itoa.c \
        ft_strmapi.c \
        ft_striteri.c \
        ft_putchar_fd.c \
        ft_putstr_fd.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c \
        GNL/get_next_line.c \
        GNL/get_next_line_utils.c

SRCS_BONUS = ft_lstnew.c \
             ft_lstlast.c \
             ft_lstadd_front.c \
             ft_lstadd_back.c \
             ft_lstsize.c \
             ft_lstdelone.c \
             ft_lstclear.c \
             ft_lstiter.c \
             ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ARRC = ar rc
RMRF = rm -rf

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) printf

$(NAME): $(OBJS)
	$(ARRC) $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS_BONUS)
	$(ARRC) $(NAME) $(OBJS_BONUS)

printf:
	$(MAKE) -C $(PRINTF_DIR)

clean: clean_printf
	$(RMRF) $(OBJS) $(OBJS_BONUS)

clean_printf:
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RMRF) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus printf clean_printf