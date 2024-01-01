# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:33:02 by tpetros           #+#    #+#              #
#    Updated: 2024/01/01 18:18:43 by tpetros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       := cub3D
NAME_B     := cub3D_b
LIBFT      := ./includes/libft/libft.a
MLXMAC     := ./includes/mlx/
MLXLINUX   := ./includes/mlx_linux/

SRC_PATH   := sources/
SRC_B_PATH := bonus/
OBJ_PATH   := objects
OBJ_B_PATH := objects_b
SRC_DIRS   := parsing raycasting

SRC_PARSE := sources/parsing/parse_arg.c \
             sources/parsing/parse_fill.c \
             sources/parsing/parse_fill_2.c \
             sources/parsing/parse_init_deinit.c \
             sources/parsing/parse_map.c \
             sources/parsing/parse_util.c \
             sources/parsing/parse_validation.c \
             sources/parsing/parser.c

SRC_RAYCAST := sources/raycasting/dda_algo.c \
               sources/raycasting/init.c \
               sources/raycasting/locating_player.c \
               sources/raycasting/movement.c \
               sources/raycasting/r3nd3r_t3xtur3.c \
               sources/raycasting/r3nd3r.c \
               sources/raycasting/raycasting.c \
               sources/raycasting/utils.c \
               sources/raycasting/movement_utils.c

SRC := $(SRC_PARSE) \
       $(SRC_RAYCAST) \
       sources/main.c

SRC_BONUS := $(SRC_PARSE) \
             bonus/raycasting/dda_algo.c \
             bonus/raycasting/init.c \
             bonus/raycasting/locating_player.c \
             bonus/raycasting/movement.c \
             bonus/raycasting/r3nd3r_t3xtur3.c \
             bonus/raycasting/r3nd3r.c \
             bonus/raycasting/raycasting.c \
             bonus/raycasting/utils.c \
             bonus/raycasting/movement_utils.c \
             bonus/main_bonus.c \
             bonus/raycasting/minimap_bonus.c

OBJS := $(SRC:sources/%.c=objects/%.o)
OBJS_B := $(SRC_BONUS:bonus/%.c=objects_b/%.o)

CC        	:= cc
CFLAGS    	:= -Wall -Wextra -Werror
RM        	:= rm -rf
MacLinker 	:= -Lincludes/mlx -lmlx -framework OpenGL -framework AppKit
LinuxLink 	:= -Lincludes/mlx_linux -lmlx_Linux -L/usr/lib -Iincludes/mlx_linux -lXext -lX11 -lm -lz

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
bonus: $(OBJ_B_PATH) $(LIBFT) $(NAME_B)

$(NAME): $(OBJS)
	@echo "Compiling and Linking MLX"
	@$(MAKE) -C $(MLX) 2> /dev/null
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  $(LINKER) -o $(NAME)
	@echo "Compilation successfull. Enjoy"

$(NAME_B): $(OBJS_B)
	@echo "Compiling and Linking MLX ... bonus"
	@$(MAKE) -C $(MLX) 2> /dev/null
	@$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT)  $(LINKER) -o $(NAME_B)
	@echo "Compilation successfull. Enjoy"


$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)/parsing
	@mkdir -p $(OBJ_PATH)/raycasting

$(OBJ_B_PATH):
	@mkdir -p $(OBJ_B_PATH)/parsing
	@mkdir -p $(OBJ_B_PATH)/raycasting

$(OBJ_PATH)/%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
$(OBJ_B_PATH)/%.o: $(SRC_B_PATH)%.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT):
	@echo "Compiling LIBFT"
	@make -C ./includes/libft  2> /dev/null
	@echo "LIBFT lib archieved"

clean:
	@$(RM) $(OBJ_PATH)
	@$(RM) $(OBJ_B_PATH)
	@make clean -sC $(MLX)
	@make clean -sC ./includes/libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_B)
	@make fclean -sC ./includes/libft

re: fclean all

norm:
	python3 -m norminette bonus/ sources/raycasting sources/parsing sources/main.c includes/libft/ includes/constants.h includes/err.h includes/structs.h includes/cub3d.h

.PHONY: all clean fclean re

