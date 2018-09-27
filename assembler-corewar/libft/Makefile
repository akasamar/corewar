# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osapon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 16:12:22 by osapon            #+#    #+#              #
#    Updated: 2017/11/07 15:57:04 by osapon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = $(wildcard ft_*.c) get_next_line.c
OBJ = $(SRC:.c=.o)
HEAD = libft.h get_next_line.h ft_printf.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c -I $(NAME) $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
