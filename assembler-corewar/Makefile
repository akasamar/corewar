# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/08 16:59:18 by osapon            #+#    #+#              #
#    Updated: 2018/07/08 16:59:23 by osapon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_asm

FLAGS = -g -Wall -Wextra -Werror -o

SRCS = *.c

OBJ=$(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
		make -C libft/
		gcc -g $(FLAGS) $(NAME) $(SRCS)  -I /bin/ -L./libft -lft
clean:
		make -C libft/ clean
		/bin/rm -f $(OBJ)
fclean: clean
		rm -f libft/libft.a
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
		.NOTPARALLEL: all clean fclean re norm

norm:
		norminette *.c* .h
