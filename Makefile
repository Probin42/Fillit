# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rweiss <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 12:23:11 by rweiss            #+#    #+#              #
#    Updated: 2017/01/12 15:43:07 by rweiss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INC_DIR = inc/

SRC_DIR = ./src/

SRC_FILES = main.c \
 			check_piece.c \
 			get_piece.c \
 			yes_we_can.c \
 			map.c \
 			parse_map.c \
 			algo.c \
			error.c

O_FILES = $(SRC_FILES:.c=.o)

CC = gcc

CC_FLAGS = -Wall -Werror -Wextra

I_LIBFT = -Ilibft

LIBFT = -Llibft $(I_LIBFT) -lft

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@$(CC) $(CC_FLAGS) -o $(NAME) $^ -I$(INC_DIR) $(LIBFT)

%.o: $(SRC_DIR)%.c
	@$(CC) $(CC_FLAGS) -I$(INC_DIR) -o $@ -c $< $(I_LIBFT)

clean:
	@make clean -C libft
	@rm -f $(O_FILES)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
