# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 10:55:50 by dpoveda-          #+#    #+#              #
#    Updated: 2021/09/25 11:10:38 by dpoveda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MAKE = make

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = -rcs

LIBFT_DIR = libft

SRC_DIR = src

OBJ_DIR = obj

SRC =	ft_printf.c		ft_printf_utils.c

OBJ = $(SRCS:%.c=%.o)

LIBFT = libft.a

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) all -C $(LIBFT_DIR) 
	ar $(ARFLAGS) $@ $^ $(NAME_LIBFT)

bonus: # QUE PONGO AQUIN NO DICE DE SEPRAR LOS BONUSES AAAAAAAAAAAHHHHH

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
