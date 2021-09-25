# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 10:55:50 by dpoveda-          #+#    #+#              #
#    Updated: 2021/09/25 19:20:23 by dpoveda-         ###   ########.fr        #
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

SRC_FILES =		ft_printf.c		ft_tab_utils.c		ft_print_char.c		\
				ft_print_str.c	ft_print_int.c		ft_print_uint.c		\
				ft_print_ptr.c	ft_print_hex.c

OBJ_FILES = $(SRC_FILES:%.c=%.o)

LIBFT_FILES = libft.a

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_FILES))

.PHONY: all bonus clean fclean rm

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_NAME)
	cp $(LIBFT_NAME) $(NAME)
	ar $(ARFLAGS) $@ $(OBJ)

$(LIBFT_NAME): $(LIBFT)
	cp $(LIBFT) .

$(LIBFT):
	$(MAKE) all -C $(LIBFT_DIR)

bonus: # QUE PONGO AQUIN NO DICE DE SEPRAR LOS BONUSES AAAAAAAAAAAHHHHH

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(LIBFT_NAME)
	rm -rf $(NAME)

re: fclean all
