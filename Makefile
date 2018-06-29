# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvann <mvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 14:11:42 by mvann             #+#    #+#              #
#    Updated: 2018/06/28 19:07:11 by mvann            ###   ########.fr        #
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
	ant.c\

.PHONY: test library all clean fclean re

all: library $(NAME)

library:
	@cd libft/ && make

$(NAME):
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)

clean:
	@rm -f $(SRC:.c=.o)
	@cd libft/ && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft/ && make fclean

re: fclean all
