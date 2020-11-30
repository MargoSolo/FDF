# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 10:12:58 by xlongfel          #+#    #+#              #
#    Updated: 2019/11/26 14:44:20 by xlongfel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS=-framework OpenGL -framework AppKit 
FLAGS=-Werror -g
NAME=fdf
SRC=./main.c ./bresenham.c ./read.c ./get_next_line.c ./module.c  ./ft_free_struct.c ./color.c ./cl.c
INCLUDES=libft/libft.a minilibx_macos/libmlx.a #-L /usr/local/lib -lmlx

all:
	@make -C libft/ all
	#@make -C minilibx_macos/all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)
	
	

clean:
	@make -C libft/ clean
	@make -C mminilibx-macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
