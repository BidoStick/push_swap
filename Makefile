# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 17:00:24 by jgoncalv          #+#    #+#              #
#    Updated: 2016/12/17 15:30:34 by jgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = libft

LDFLAGS = -Llibft

LDLIBS = -lft

SRC_PATH = src

SRC_NAME = checker.c\
		check.c\
		list.c\
		command.c\
		swap.c\
		push.c\
		rotate.c\
		rotate_rev.c\

AR = ar rc

INC_LIB = -I libft/include

CPPFLAGS = -I include

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "Executable " $(NAME) " made"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_LIB) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /def/null || true
	@echo "Objet de " $(NAME) " supprimer"

fclean: clean
	@rm -f $(NAME)
	@echo "Objet et executable de " $(NAME) " supprimer"

re: fclean all
	@echo "Make re " $(NAME)

norme:
	norminette $(SRC)
	norminette $(INC_PATH)
