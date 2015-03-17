# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroche <vroche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/08 23:30:25 by vroche            #+#    #+#              #
#    Updated: 2015/03/17 14:38:14 by vroche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Werror -Wextra

LIB = -framework OpenGL -framework AppKit \
	  	-L./minilibx_macos -lmlx -L./libft -lft

HDR = -I./libft

C = ft_burningship.c \
	ft_hsvtorgb.c \
	ft_julia.c \
	ft_manage.c \
	ft_manage_bns.c \
	ft_manage_jla.c \
	ft_manage_mdb.c \
	ft_mandelbrot.c \
	main.c

all: $(NAME)

$(NAME):
	make -C ./libft
	make -C ./minilibx_macos
	gcc $(FLAGS) $(HDR) $(LIB) $(C) -o $(NAME)

clean:
	make -C ./libft clean
	make -C ./minilibx_macos clean

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
