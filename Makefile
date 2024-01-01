# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:33:02 by tpetros           #+#    #+#              #
#    Updated: 2024/01/01 17:07:07 by hatesfam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      	:= cub3D
NAME_B     	:= cub3D_b
LIBFT     	:= ./includes/libft/libft.a
MLXMAC    	:= ./includes/mlx/
MLXLINUX  	:= ./includes/mlx_linux/
	
SRC_PATH  	:= sources/
SRC_B_PATH  := bonus/
OBJ_PATH  	:= objects
OBJ_B_PATH  := objects_b
SRC_DIRS  	:= parsing raycasting
SRC_PARSE 	:= parse_arg \
				parse_fill \
				parse_fill_2 \
				parse_init_deinit \
				parse_map \
				parse_util \
				parse_validation \
				parser \

SRC_RAYCAST := dda_algo \
				init \
				locating_player \
				movement \
				r3nd3r_t3xtur3 \
				r3nd3r \
				raycasting \
				utils \
				movement_utils \

SRC 		:= $(addprefix $(SRC_PATH)parsing/, $(addsuffix .c, $(SRC_PARSE))) \
			  $(addprefix $(SRC_PATH)raycasting/, $(addsuffix .c, $(SRC_RAYCAST))) \
			  sources/main.c

SRC_BONUS 		:= $(addprefix $(SRC_PATH)parsing/, $(addsuffix .c, $(SRC_PARSE))) \
			  $(addprefix $(SRC_B_PATH)raycasting/, $(addsuffix .c, $(SRC_RAYCAST))) \
			  bonus/main_bonus.c bonus/raycasting/minimap_bonus.c

OBJS      	:= $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)/%.o, $(SRC))
OBJS_B     	:= $(patsubst $(SRC_B_PATH)%.c, $(OBJ_B_PATH)/%.o, $(SRC_BONUS))

CC        	:= cc
CFLAGS    	:= -Wall -Wextra -Werror -g
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
	@mkdir -p $(addprefix $(OBJ_PATH)/, $(SRC_DIRS))
	
$(OBJ_B_PATH):
	@mkdir -p $(addprefix $(OBJ_B_PATH)/, $(SRC_DIRS))

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
	norminette sources/raycasting sources/parsing sources/main.c includes/libft/ includes/constants.h includes/err.h includes/structs.h includes/cub3d.h

.PHONY: all clean fclean re

