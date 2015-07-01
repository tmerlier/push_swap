# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 16:01:27 by tmerlier          #+#    #+#              #
#    Updated: 2015/06/27 15:45:04 by tmerlier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB = libft/

HEADER = includes/

DIRSRC = srcs/

FLAGS = -Wall -Wextra -Werror -g

SRC = main.c \
	  push_swap.c \
	  list.c \
	  options.c \
	  check.c \
	  print.c \
	  swap.c \
	  push.c \
	  rotate.c \
	  rev_rotate.c \
	  error.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: init $(NAME)

init:
	@echo "\033[0;32m          $(NAME) PROJECT\033[0m"

$(NAME): $(OBJ)
	@make -s -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $^ -L$(LIB) -lft

%.o: $(DIRSRC)%.c
	@gcc $(FLAGS)  -o $@ -c $< -I$(LIB)$(HEADER) -I$(HEADER)

clean:
	@rm -f $(OBJ)
	@make clean -s -C $(LIB)
	@echo "\033[4;32mDeleted\033[0;33m $(OBJ)\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIB)
	@echo "\033[4;32mDeleted\033[0;33m $(NAME)\033[0m"

re: fclean all
