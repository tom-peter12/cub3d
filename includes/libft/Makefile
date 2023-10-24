# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 17:16:53 by tpetros           #+#    #+#              #
#    Updated: 2023/10/24 18:10:09 by tpetros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_FILES = ft_array/ft_rev_int_tab.c \
			ft_array/ft_sort_int_tab.c \
			ft_array/ft_print_array.c \
			ft_array/ft_double_array_free.c \
			ft_array/ft_double_array_printer.c \
			ft_ascii_check/ft_is_negative.c \
			ft_ascii_check/ft_isalnum.c \
			ft_ascii_check/ft_isalpha.c \
			ft_ascii_check/ft_isascii.c \
			ft_ascii_check/ft_isdigit.c \
			ft_ascii_check/ft_isprint.c \
			ft_btree/ft_btree_create_node.c \
			ft_btree/ft_btree_apply_prefix.c \
			ft_btree/ft_btree_apply_suffix.c \
			ft_btree/ft_btree_apply_infix.c \
			ft_btree/ft_btree_level_count.c \
			ft_btree/ft_btree_insert_data.c \
			ft_linked_list/ft_lstadd_back.c \
			ft_linked_list/ft_lstadd_front.c \
			ft_linked_list/ft_lstclear.c \
			ft_linked_list/ft_lstdelone.c \
			ft_linked_list/ft_lstiter.c \
			ft_linked_list/ft_lstlast.c \
			ft_linked_list/ft_lstmap.c \
			ft_linked_list/ft_lstnew.c \
			ft_linked_list/ft_lstsize.c \
			ft_math/ft_div_mod.c \
			ft_math/ft_fibonacci.c \
			ft_math/ft_find_next_prime.c \
			ft_math/ft_is_prime.c \
			ft_math/ft_iterative_factorial.c \
			ft_math/ft_iterative_power.c \
			ft_math/ft_range.c \
			ft_math/ft_recursive_factorial.c \
			ft_math/ft_recursive_power.c \
			ft_math/ft_sqrt.c \
			ft_math/ft_swap.c \
			ft_math/ft_ultimate_div_mod.c \
			ft_math/ft_ultimate_range.c \
			ft_memory/ft_bzero.c \
			ft_memory/ft_calloc.c \
			ft_memory/ft_memchr.c \
			ft_memory/ft_memcmp.c \
			ft_memory/ft_memcpy.c \
			ft_memory/ft_memmove.c \
			ft_memory/ft_memset.c \
			ft_out/ft_putchar_fd.c \
			ft_out/ft_putendl_fd.c \
			ft_out/ft_putnbr_base.c \
			ft_out/ft_putnbr_fd.c \
			ft_out/ft_putstr_fd.c \
			ft_out/ft_putstr_non_printable.c \
			ft_string/ft_split.c \
			ft_string/ft_str_is_alpha.c \
			ft_string/ft_str_is_lowercase.c \
			ft_string/ft_str_is_numeric.c \
			ft_string/ft_str_is_printable.c \
			ft_string/ft_str_is_uppercase.c \
			ft_string/ft_strcapitalize.c \
			ft_string/ft_strcat.c \
			ft_string/ft_strchr.c \
			ft_string/ft_strcmp.c \
			ft_string/ft_strcpy.c \
			ft_string/ft_strdup.c \
			ft_string/ft_striteri.c \
			ft_string/ft_strjoin.c \
			ft_string/ft_strlcat.c \
			ft_string/ft_strlcpy.c \
			ft_string/ft_strlen.c \
			ft_string/ft_strlowcase.c \
			ft_string/ft_strmapi.c \
			ft_string/ft_strncat.c \
			ft_string/ft_strncmp.c \
			ft_string/ft_strncpy.c \
			ft_string/ft_strnstr.c \
			ft_string/ft_strrchr.c \
			ft_string/ft_strreplace.c \
			ft_string/ft_strstr.c \
			ft_string/ft_strtrim.c \
			ft_string/ft_strupcase.c \
			ft_string/ft_substr.c \
			ft_to/ft_atoi.c \
			ft_to/ft_itoa.c \
			ft_to/ft_tolower.c \
			ft_to/ft_toupper.c \
			get_next_line/get_next_line.c \

CC = cc
RM = rm -rf

CFLAGS = -Wall -Werror -Wextra

OBJS = ${SRC_FILES:.c=.o}

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}


clean:
	${RM} ${OBJS}
	
fclean: clean
	${RM} ${NAME}

re:	fclean all