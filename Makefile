# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 20:06:26 by aschmitt          #+#    #+#              #
#    Updated: 2024/01/25 10:12:52 by aschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

INC				= inc/
SRC_DIR			= srcs/
OBJ_DIR			= obj/

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -I
LDFLAGS 	= -Lminilibx/mlx_Linux -Lminilibx/mlx -L/usr/lib -Imlx_linux -lXext -lX11
LIB 		= inc/ml/libmlx.a inc/ml/libmlx_Linux.a
RM			= rm -f

SRC 		= $(SRC_DIR)map.c $(SRC_DIR)so_long.c $(SRC_DIR)gnl.c $(SRC_DIR)gnl_utils.c $(SRC_DIR)move.c \
				$(SRC_DIR)display.c $(SRC_DIR)check_solution.c $(SRC_DIR)utils.c

OBJ 		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))


all: 		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $^ $(LIB) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			$(RM) -r $(OBJ_DIR)

fclean: 	clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
