# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvann <mvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 14:11:42 by mvann             #+#    #+#              #
#    Updated: 2018/06/29 16:04:02 by mvann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
LIBFT = -L libft/ -lft
NAME = lem-in
SRC = lem_in.c\
	input.c\
	split.c\
	int.c\
	boolean.c\
	error.c\
	room.c\
	print.c\
	name.c\
	distance.c\
	ant.c
MINILIBX_DIR = minilibx_macos/
MINILIBX = -L $(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit
VIS = visu-hex
VIS_SRC = visualizer.c\
	input.c\
	split.c\
	int.c\
	boolean.c\
	error.c\
	room.c\
	print.c\
	name.c\
	distance.c\
	ant.c\
	draw.c\
	normalize.c\
	line.c\
	events.c\
	iterate.c

.PHONY: test library all clean fclean re mlx

all: library $(NAME) mlx $(VIS)

library:
	@cd libft/ && make

$(NAME):
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)

mlx:
	@cd $(MINILIBX_DIR) && make

$(VIS):
	@gcc $(FLAGS) -o $(VIS) $(VIS_SRC) $(LIBFT) $(MINILIBX)

clean:
	@rm -f $(SRC:.c=.o)
	@cd libft/ && make clean
	@cd $(MINILIBX_DIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(VIS)
	@cd libft/ && make fclean

re: fclean all
