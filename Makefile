#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2015/02/16 15:21:32 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	fractol
C_SRC =	main.c
O_DIR =	obj
VPATH =	src
SRCC = 	$(C_SRC:%.c=src/%.c)
SRCO =	$(C_SRC:%.c=$(O_DIR)/%.o)
LIB =	libft/libft.a
INC =	inc/header.h
CC =	gcc
RM =	rm -f
CFLAGS = -Wall -Werror -Wextra -I./inc/

.PHONY: all lib soft debug optimize clean fclean zclean brute re

all: 
	@make -C libft
	@$(MAKE) $(NAME)

$(NAME): $(SRCO) $(LIB) $(INC)
	@$(CC) $(CFLAGS) $(SRCO) $(LIB) -o $@

$(O_DIR)/%.o: %.c
	@$(RM) $(NAME)
	@$(CC) $(CFLAGS) -c $^ -o $@

soft:
	@$(RM) $(NAME)
	@$(CC) $(SRCC) $(LIB) -o $(NAME)
	@./$(NAME)

debug: re
	@$(CC) $(CFLAGS) -ggdb $(SRCO) $(LIB) -o $(NAME)
	@gdb $(NAME)

optimize: re
	@$(CC) $(CFLAGS) -O2 $(SRCO) $(LIB) -o $(NAME)

clean:
	@$(RM) $(SRCO)

fclean: clean
	@$(RM) $(NAME)

zclean: fclean
	@make -C libft fclean

brute: zclean all

re: fclean all

