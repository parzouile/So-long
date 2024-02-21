# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 20:06:26 by aschmitt          #+#    #+#              #
#    Updated: 2024/02/21 10:03:12 by aschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

INC				= inc/
SRC_DIR			= srcs/
OBJ_DIR			= obj/

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g3 -I
LDFLAGS 	= -Lminilibx/mlx_Linux -Lminilibx/mlx -L/usr/lib -Imlx_linux -lXext -lX11
LIB 		= inc/ml/libmlx.a inc/ml/libmlx_Linux.a
RM			= rm -f

SRC 		= $(SRC_DIR)map.c $(SRC_DIR)so_long.c $(SRC_DIR)gnl.c $(SRC_DIR)gnl_utils.c $(SRC_DIR)move.c \
				$(SRC_DIR)display.c $(SRC_DIR)check_solution.c $(SRC_DIR)utils.c

OBJ 		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

G = "\033[32m"
X = "\033[0m"

all: 		$(NAME)

$(NAME):	$(OBJ) 
			@echo $(G)Compiling [$(SRC)]$(X)
			@$(CC) $^ $(LIB) $(LDFLAGS) -o $(NAME)
			@echo $(G)Compiling [$(NAME)]$(X)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INC)*.h Makefile
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			@echo $(G)Delete [Obj]$(X)	
			@$(RM) -r $(OBJ_DIR)

fclean: 	clean
			@echo $(G)Delete [$(NAME)]$(X)	
			@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
