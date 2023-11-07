# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:33:02 by tpetros           #+#    #+#              #
#    Updated: 2023/11/07 12:10:28 by tpetros          ###   ########.fr        #
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
	
$(LIBFT):
	# make -C ./includes/libft  2> /dev/null

$(NAME): $(OBJS)
	@echo "Compiling mlx"
	# $(MAKE) -C $(MLX) 2> /dev/null
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LINKER) -g -o $(NAME)


$(OBJ_PATH):
	mkdir -p $(addprefix $(OBJ_PATH)/, $(SRC_DIRS))

clean:
	@echo "Cleaning objects"
	@$(RM) $(OBJ_PATH)
	# @make clean -sC $(MLX)
	# @make clean -sC ./includes/libft

fclean: clean
	@echo "Cleaning $(NAME)"
	@$(RM) $(NAME)
	# @make fclean -sC ./includes/libft

re: fclean all

push:
	git add .
	git commit -m "AT $(date +%Y%m%d%H%M%S) BY $(whoami)"
	git push

.PHONY: all clean fclean re

