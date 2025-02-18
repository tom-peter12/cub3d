/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:01:46 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/01 18:12:28 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	g_buf[BUFFER_SIZE + 1];

static size_t	ft_strlcpyy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < srcsize && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

static char	*ft_strdupp(const char *src)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(src) + 1;
	dst = ft_calloc(1, len);
	if (dst == NULL)
		return (NULL);
	ft_strlcpyy(dst, src, len);
	return (dst);
}

static char	*ft_strjoinn(char *s1, char const *s2, size_t len)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = len;
	join = (char *)ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpyy(join, s1, s1_len + 1);
	ft_strlcpyy((join + s1_len), s2, s2_len + 1);
	free(s1);
	return (join);
}

static char	*read_to_buffer(int fd, char *line)
{
	int	countread;

	while (!ft_strchr(line, '\n'))
	{
		countread = read(fd, g_buf, BUFFER_SIZE);
		if (countread <= 0)
			break ;
		g_buf[countread] = '\0';
		line = ft_strjoinn(line, g_buf, countread);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*newline;
	int		to_copy;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdupp(g_buf);
	line = read_to_buffer(fd, line);
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	if (newline)
	{
		to_copy = newline - line + 1;
		ft_strlcpyy(g_buf, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpyy(g_buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return (line);
}
