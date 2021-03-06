# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 10:55:50 by dpoveda-          #+#    #+#              #
#    Updated: 2021/09/27 11:59:09 by dpoveda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_NAME = libft.a

MAKE = make

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = -rcs

LIBFT_DIR = libft

SRC_DIR = src

OBJ_DIR = obj

SRC_FILES =			ft_printf.c		ft_tab_utils.c		ft_print_char.c		\
					ft_print_str.c	ft_print_int.c		ft_print_uint.c		\
					ft_print_ptr.c	ft_print_hex.c

OBJ_FILES = $(SRC_FILES:%.c=%.o)

LIBFT_FILES = libft.a

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_FILES))

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) .
	cp $(LIBFT_NAME) $(NAME)
	ar $(ARFLAGS) $@ $(OBJ)

bonus: $(NAME)

$(LIBFT):
	$(MAKE) all -sC $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) clean -sC $(LIBFT_DIR)
	rm -rf $(LIBFT_NAME)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -sC $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all
