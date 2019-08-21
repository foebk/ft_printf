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
SRC = ft_printf.c printint.c printoct.c printtxt.c specs.c printint2.c printoct2.c printpercent.c printhex.c printhex2.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
HEADER = -I. -I./libft/includes

all: $(NAME)

# $(OBJ): %.o: %.c
# 		@gcc -c -I./libft/includes $< -o $@
		

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT)
	@echo "LIBFT COMPILATED"
	@cc -c $(SRC) -I./libft/includes -I.
	@echo "OBJECT FILES COMPILATED"
	@cp $(LIBFT) ./$(NAME)
	@ar -rc $(NAME) $(OBJ)
	@echo "DONE. HAVE FUN"

clean:
	/bin/rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft fclean

re: fclean all