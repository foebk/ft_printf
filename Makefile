# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ction <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/14 20:31:59 by ction             #+#    #+#              #
#    Updated: 2019/08/14 20:32:00 by ction            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra

LIBFT_DIR = ./libft
SRC_DIR = ./srcs
INC_DIR = ./includes
OBJ_DIR = ./obj

SRC	= ft_printf.c printint.c printoct.c printtxt.c specs.c printint2.c \
	printoct2.c printpercent.c printhex.c printhex2.c printunsigned.c

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_H = $(LIBFT_DIR)/includes

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT_DIR)/objs/*.o
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -g $(FLAGS) -c $< -I$(INC_DIR) -I$(LIBFT_H) -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
