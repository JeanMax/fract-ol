#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2015/02/19 15:29:14 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	fractol
C_SRC =	main.c hooks.c mlx.c error.c \
		mandel.c julia.c schottky.c chromosom.c noun.c rabbit.c
O_DIR =	obj
VPATH =	src
SRCC = 	$(C_SRC:%.c=src/%.c)
SRCO =	$(C_SRC:%.c=$(O_DIR)/%.o)
LIB =	libft/libft.a
INC =	inc/header.h
CC =	gcc
RM =	rm -f
CFLAGS = -Wall -Werror -Wextra -I./inc/ -I/usr/X11/include
MLX = -L/usr/X11/lib -lmlx -lXext -lX11

.PHONY: all lib soft debug optimize clean fclean zclean brute re

all: 
	@make -C libft
	@$(MAKE) $(NAME)

$(NAME): $(SRCO) $(LIB) $(INC)
	$(CC) $(CFLAGS) $(SRCO) $(LIB) $(MLX) -o $@ -lm

$(O_DIR)/%.o: %.c
	@$(RM) $(NAME)
	$(CC) $(CFLAGS) $(MLX) -c $^ -o $@ -lm

soft:
	@$(RM) $(NAME)
	@$(CC) $(SRCC) $(LIB) $(MLX) -o $(NAME) -lm
	@./$(NAME)

debug: re
	@$(CC) $(CFLAGS) -ggdb $(SRCO) $(LIB) $(MLX) -o $(NAME)
	@gdb $(NAME)

optimize: re
	@$(CC) $(CFLAGS) -O2 $(SRCO) $(LIB) $(MLX) -o $(NAME)

clean:
	@$(RM) $(SRCO)

fclean: clean
	@$(RM) $(NAME)

zclean: fclean
	@make -C libft fclean

brute: zclean all

re: fclean all

