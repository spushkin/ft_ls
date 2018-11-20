# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spushkin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 09:50:12 by spushkin          #+#    #+#              #
#    Updated: 2018/11/20 09:50:46 by spushkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = add_new_file.c display_all.c display_detailed_list.c display_list_items.c\
	  display_list.c main.c misc.c parsing.c sort_list.c

FLAGS = -Wall -Wextra -Werror -O2

OBJS = $(SRC:.c=.o)
	
LIBFT = libft

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) $(OBJS) -L./libft -lft -o $(NAME)
	echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)
	echo "\033[31mObjects files \033[1;31m$(OBJS)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a
	echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all
