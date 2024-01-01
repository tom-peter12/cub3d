/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:01:59 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/01 14:27:59 by hatesfam         ###   ########.fr       */
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


typedef struct s_gnl
{
	char		*line;
	char		*newline;
	int			countread;
	int			to_copy;
}				t_gnl;

char	*get_next_line(int fd);

#endif
