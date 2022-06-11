# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 21:29:51 by lpfleide          #+#    #+#              #
#    Updated: 2021/12/15 18:04:00 by lpfleide         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = 
INCLUDE = -L. libft/libft.a
NAME = push_swap
CHECKER = checker
SRC_CHECKER = checker.c
SRC_PS = push_swap.c
SRC = ./dll/push_swap_operations.c \
		./dll/push_swap_operations_2.c ./dll/doubly_linked_list.c \
		./astack/astack.c ./astack/push_lis_b.c ./astack/input_handler.c ./astack/lis.c \
		./bstack/bstack.c ./bstack/best_operations.c ./bstack/check_operations.c \
		./bstack/execute_operations.c
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_PS = $(patsubst %.c, %.o, $(SRC_PS))
OBJ_CHECKER = $(patsubst %.c, %.o, $(SRC_CHECKER))

%.o: %.c $(SRC) $(SRC_PS) $(SRC_CHECKER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME) $(CHECKER)

$(NAME): libmake $(OBJ) $(OBJ_PS)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_PS) $(INCLUDE) -o $(NAME)

$(CHECKER): libmake $(OBJ) $(OBJ_CHECKER)
	$(CC) $(FLAGS) $(OBJ) $(OBJ_CHECKER) $(INCLUDE) -o $(CHECKER)

libmake:
	make all -C ./libft
	make all -C ./libft/ft_printf/

clean:
	rm -f $(OBJ) $(OBJ_PS) $(OBJ_CHECKER)
	make clean -C ./libft
	make clean -C ./libft/ft_printf/

fclean: clean
	rm -f $(NAME) $(CHECKER)
	make fclean -C ./libft
	make fclean -C ./libft/ft_printf/

re: fclean all