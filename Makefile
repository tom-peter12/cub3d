# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:33:02 by tpetros           #+#    #+#              #
#    Updated: 2023/12/22 17:50:32 by tpetros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      	= cub3D
LIBFT     	= ./includes/libft/libft.a
MLXMAC    	= ./includes/mlx/
MLXLINUX  	= ./includes/mlx_linux/
	
SRC_PATH  	= sources/
OBJ_PATH  	= objects
SRC_DIRS  	= parsing raycasting
SRC_PARSE 	= parse_arg \
				parse_fill \
				parse_fill_2 \
				parse_init_deinit \
				parse_map \
				parse_util \
				parse_validation \
				parser \

SRC_RAYCAST = dda_algo \
				init \
				locating_player \
				movement \
				r3nd3r_t3xtur3 \
				r3nd3r \
				raycasting \
				utils \

SRC 		= $(addprefix $(SRC_PATH)parsing/, $(addsuffix .c, $(SRC_PARSE))) \
			  $(addprefix $(SRC_PATH)raycasting/, $(addsuffix .c, $(SRC_RAYCAST))) \
			  sources/main.c

OBJS      	= $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)/%.o, $(SRC))
FSANITIZE 	= -g3 -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined
	
CC        	= cc
CFLAGS    	= -Wall -Wextra -Werror
RM        	= rm -rf
MacLinker 	= -Lincludes/mlx -lmlx -framework OpenGL -framework AppKit
LinuxLink 	= -Lincludes/mlx_linux -lmlx_Linux -L/usr/lib -Iincludes/mlx_linux -lXext -lX11 -lm -lz

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
	make -C ./includes/libft  2> /dev/null

$(NAME): $(OBJS)
	@echo "Compiling mlx"
	$(MAKE) -C $(MLX) 2> /dev/null
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  $(LINKER)  -o $(NAME)


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
	git commit -m "AT $(shell date +%Y%m%d%H%M%S) BY $(shell whoami)"
	git push

.PHONY: all clean fclean re

