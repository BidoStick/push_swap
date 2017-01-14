# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 17:00:24 by jgoncalv          #+#    #+#              #
#    Updated: 2017/01/04 15:36:57 by jgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = checker

NAME2 = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIB = libft

LDFLAGS = -Llibft

LDLIBS = -lft

SRC_PATH = src

SRC_NAME = checker.c\
		list.c\
		command.c\
		swap.c\
		push.c\
		rotate.c\
		rotate_rev.c\
		get.c\
		check.c\

SRC_NAME2 = push_swap.c\
		list.c\
		command.c\
		swap.c\
		push.c\
		rotate.c\
		rotate_rev.c\
		get.c\
		check.c\
		quicksort.c\
		affichage.c\
		separation.c\
		search.c\
		range.c\
		sort.c\
		restore.c\
		usecom.c

AR = ar rc

INC_LIB = -I libft/include

CPPFLAGS = -I include

OBJ_PATH = obj

OBJ_PATH2 = obj2

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_NAME2 = $(SRC_NAME2:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC2 = $(addprefix $(SRC_PATH)/,$(SRC_NAME2))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ2 = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME2))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@echo $(NAME) ": Sources compiling..."
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)
	@echo "Executable "$(NAME)" made"

$(NAME2): $(OBJ2)
	@make -C $(LIB)
	@echo $(NAME) ": Sources compiling..."
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)
	@echo "Executable "$(NAME2)" made"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_LIB) -o $@ -c $<

$(OBJ_PATH2)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH2) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_LIB) -o $@ -c $<

clean:
	@rm -f $(OBJ) $(OBJ2)
	@rmdir $(OBJ_PATH) 2> /def/null || true
	@rmdir $(OBJ_PATH2) 2> /def/null || true
	@echo $(OBJ_PATH)" et "$(OBJ_PATH2)" supprimé !"

fclean: clean
	@rm -f $(NAME) $(NAME2)
	@echo "Objet et executable de "$(NAME)" et "$(NAME2)" supprimer !"

re: fclean all
	@echo "Make re done !"

norme:
	norminette $(SRC)
	norminette $(INC_PATH)
