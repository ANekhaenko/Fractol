# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/14 20:35:40 by anekhaen          #+#    #+#              #
#    Updated: 2019/11/08 16:44:38 by anekhaen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall 
NAME=fractol
SRC=*.c
OBJ=$(SRC:.c=.o)
INCLUDES=libft/libft.a minilibx_macos/libmlx.a
COLOR = \033[47m\033[34m
all:
	@make -C libft/ all
	@make -C minilibx_macos/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)
	@echo "$(COLOR)Project successfully compiled"
clean:
	-rm -f $(OBJ)
	@make -C libft/ clean
	@make -C minilibx_macos/ clean
fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean
re: fclean all
