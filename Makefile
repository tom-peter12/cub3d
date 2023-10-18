# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:33:02 by tpetros           #+#    #+#              #
#    Updated: 2023/10/18 23:47:33 by tpetros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

OBJ_DIR = objs/
SRC = sources/cub3d.c
OBJS = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
CC = cc
# CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
OS := $(shell uname)

ifeq ($(OS),Darwin)
	LINKER = -Lincludes/mlx -lincludes/mlx -framework OpenGL -framework AppKit
else ifeq ($(OS),Linux)
	LINKER = -Lincludes/mlx_linux -lmlx_Linux -L/usr/lib -Iincludes/mlx_linux -lXext -lX11 -lm -lz
else
	LINKER = 
endif

all : $(NAME)

$(NAME): $(OBJS)
	cd ./includes/libft/ && make
	cd ./includes/mlx_linux/ && make
	$(CC) $(CFLAGS) $(OBJS) $(LINKER) ./includes/libft/libft.a -o $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -Iincludes/mlx_linux -c $< -o $@


clean:
	cd ./includes/mlx_linux/ && make clean
	cd ./includes/libft/ && make clean
	$(RM) $(OBJ_DIR)

fclean: clean
	cd ./includes/mlx_linux/ && make clean
	cd ./includes/libft/ && make fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

