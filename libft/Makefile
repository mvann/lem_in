# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvann <mvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 12:17:58 by mvann             #+#    #+#              #
#    Updated: 2018/05/20 16:18:12 by mvann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
COMP_FLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c\
	ft_lstdel.c\
	ft_memcpy.c\
	ft_putnbr_fd.c\
	ft_strdel.c\
	ft_strmapi.c\
	ft_strstr.c\
	ft_bzero.c\
	ft_lstdelone.c\
	ft_memdel.c\
	ft_putstr.c\
	ft_strdup.c\
	ft_strncat.c\
	ft_strsub.c\
	ft_isalnum.c\
	ft_lstiter.c\
	ft_memmove.c\
	ft_putstr_fd.c\
	ft_strequ.c\
	ft_strncmp.c\
	ft_strtrim.c\
	ft_isalpha.c\
	ft_lstmap.c\
	ft_memset.c\
	ft_putwchar.c\
	ft_striter.c\
	ft_strncpy.c\
	ft_tolower.c\
	ft_isascii.c\
	ft_lstnew.c\
	ft_putchar.c\
	ft_strcat.c\
	ft_striteri.c\
	ft_strnequ.c\
	ft_toupper.c\
	ft_isdigit.c\
	ft_memalloc.c\
	ft_putchar_fd.c\
	ft_strchr.c\
	ft_strjoin.c\
	ft_strnew.c\
	ft_isprint.c\
	ft_memccpy.c\
	ft_putendl.c\
	ft_strclr.c\
	ft_strlcat.c\
	ft_strnstr.c\
	ft_itoa.c\
	ft_memchr.c\
	ft_putendl_fd.c\
	ft_strcmp.c\
	ft_strlen.c\
	ft_strrchr.c\
	ft_lstadd.c\
	ft_memcmp.c\
	ft_putnbr.c\
	ft_strcpy.c\
	ft_strmap.c\
	ft_strsplit.c\
	ft_lstsize.c\
	ft_lstat.c\
	ft_isromanupper.c\
	ft_isromanlower.c\
	get_next_line.c

all: $(NAME)

$(NAME):
	@cd ft_printf && make
	@gcc $(COMP_FLAGS) -c $(SRC)
	@ar rc $(NAME) $(SRC:.c=.o) ft_printf/*.o
	@ranlib $(NAME)

clean:
	@rm -f $(SRC:.c=.o)
	@cd ft_printf && make clean

fclean: clean
	@rm -f $(NAME)
	@cd ft_printf && make fclean

re: fclean all
