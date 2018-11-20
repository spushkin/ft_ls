# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spushkin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 09:51:58 by spushkin          #+#    #+#              #
#    Updated: 2018/11/20 09:52:06 by spushkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -O2

SOURCES = ./src/ft_*.c ./ft_printf/*.c

INCLUDE = header

OBJS = ./src/ft_*.o ./ft_printf/*.o

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SOURCES) -I $(INCLUDE)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
