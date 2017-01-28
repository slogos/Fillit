# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slogos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 15:36:15 by hkalia            #+#    #+#              #
#    Updated: 2016/11/04 21:14:41 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror
CFILES = fillit.c checker.c verificator.c modificator.c ft_strsplit.c
CFILES += solve_tetris.c solve_tools.c tools.c

OFILES = $(CFILES:.c=.o)

.PHONY: clean fclean all re

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(CFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

clean:
	rm -rf $(OFILES)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all
