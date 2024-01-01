/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:01:59 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/01 16:16:07 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../includes/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

static char	g_buf[BUFFER_SIZE + 1];

char	*get_next_line(int fd);

#endif
