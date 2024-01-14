# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschmitt <aschmitt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 20:06:26 by aschmitt          #+#    #+#              #
#    Updated: 2024/01/14 17:32:47 by aschmitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long
OBJ_DIR 	= obj

# Compielr and Flags
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g3
LDFLAGS 	= -Lminilibx/mlx_Linux -Lminilibx/mlx -L/usr/lib -Imlx_linux -lXext -lX11 
LIB 		= ml/libmlx.a ml/libmlx_Linux.a
RM 			= rm -f

# Source Files
SRC 		= map.c so_long.c gnl.c gnl_utils.c move.c display.c

# Apply the pattern addprefix
OBJ 		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Build rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(LIB) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
