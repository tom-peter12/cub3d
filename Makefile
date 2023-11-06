# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:33:02 by tpetros           #+#    #+#              #
#    Updated: 2023/10/25 19:17:29 by tpetros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = cub3D
LIBFT     = ./includes/libft/libft.a
MLXMAC    = ./includes/mlx/
MLXLINUX  = ./includes/mlx_linux/

SRC_PATH  = sources/
OBJ_PATH  = objects
SRC_DIRS  = parsing raytracing
SRC       = $(wildcard $(addprefix $(SRC_PATH), $(addsuffix /*.c, $(SRC_DIRS))))
OBJS      = $(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)/%.o,$(SRC))

CC        = cc
CFLAGS    = -Wall -Wextra -Werror
RM        = rm -rf
MacLinker = -Lincludes/mlx -lmlx -framework OpenGL -framework AppKit
LinuxLink = -Lincludes/mlx_linux -lmlx_Linux -L/usr/lib -Iincludes/mlx_linux -lXext -lX11 -lm -lz
sanitize  = -fsanitize=address -g3 -fno-omit-frame-pointer

OS := $(shell uname)

ifeq ($(OS),Darwin)
	MLX     = $(MLXMAC)
	LINKER  = $(MacLinker)
else ifeq ($(OS),Linux)
	MLX     = $(MLXLINUX)
	LINKER  = $(LinuxLink)
else
	LINKER  =
endif

all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	# $(MAKE) -C $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LINKER) -g -o $(NAME)

$(LIBFT):
	@make -sC ./includes/libft

$(OBJ_PATH):
	mkdir -p $(addprefix $(OBJ_PATH)/, $(SRC_DIRS))

clean:
	@$(RM) $(OBJ_PATH)
	# @make clean -sC $(MLX)
	# @make clean -sC ./includes/libft

fclean: clean
	@echo "Cleaning $(NAME)"
	@$(RM) $(NAME)
	@make fclean -sC ./includes/libft

re: fclean all

.PHONY: all clean fclean re

