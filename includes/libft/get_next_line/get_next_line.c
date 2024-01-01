/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:01:46 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/01 14:49:13 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	dst = malloc(len);
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

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			countread = -1;
	int			to_copy;

	line = ft_strdupp(buf);
	countread = read(fd, buf, BUFFER_SIZE);
	if (countread == -1) {
    	return NULL;
}
	while (!(ft_strchr(line, '\n')) && (countread > 0))
	{
		buf[countread] = '\0';
		line = ft_strjoinn(line, buf, countread);
		countread = read(fd, buf, BUFFER_SIZE);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strlcpyy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpyy(buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return (line);
}

// void	init_gnl(t_gnl *gnl)
// {
// 	gnl->line = NULL;
// 	gnl->newline = NULL;
// 	gnl->countread = -1;
// 	gnl->to_copy = 0;
// }

// char	*get_next_line(int fd)
// {
// 	static char	buf[BUFFER_SIZE + 1];
// 	t_gnl		gnl;

// 	ft_memset(&gnl, 0, sizeof(t_gnl));
// 	gnl.line = ft_strdupp(buf);
// 	gnl.countread = read(fd, buf, BUFFER_SIZE);
// 	while (!(ft_strchr(gnl.line, '\n')) && (gnl.countread  > 0))
// 	{
// 		buf[gnl.countread] = '\0';
// 		gnl.line = ft_strjoinn(gnl.line, buf, gnl.countread);
// 		gnl.countread = read(fd, buf, BUFFER_SIZE);
// 	}
// 	if (ft_strlen(gnl.line) == 0)
// 		return (free(gnl.line), NULL);
// 	gnl.newline = ft_strchr(gnl.line, '\n');
// 	if (gnl.newline != NULL)
// 	{
// 		gnl.to_copy = gnl.newline - gnl.line + 1;
// 		ft_strlcpyy(buf, gnl.newline + 1, BUFFER_SIZE + 1);
// 	}
// 	else
// 	{
// 		gnl.to_copy = ft_strlen(gnl.line);
// 		ft_strlcpyy(buf, "", BUFFER_SIZE + 1);
// 	}
// 	gnl.line[gnl.to_copy] = '\0';
// 	return (gnl.line);
// }


int main(void)
{
	int		fd;
	char	*line;

	fd = open("/Users/hatesfam/Desktop/my_42work/cub3d/assets/maps/ai.cub", O_RDONLY);
		line = get_next_line(fd);
	while (line)
	{
		printf("[%s]\n", line);
		free(line);
		line = get_next_line(fd);
	}
}
// void	ft_strlcpyy_utils(char *buf, char **line, char **newline)
// {
// 	int			to_copy;

// 	to_copy = 0;
// 	if ((*newline) != NULL)
// 	{
// 		to_copy = (*newline) - (*line) + 1;
// 		ft_strlcpyy((buf), (*newline) + 1, BUFFER_SIZE + 1);
// 	}
// 	else
// 	{
// 		to_copy = ft_strlen((*line));
// 		ft_strlcpyy((buf), "", BUFFER_SIZE + 1);
// 	}
// 	(*line)[to_copy] = '\0';
// }

// char	*get_next_line(int fd)
// {
// 	static char	buf[BUFFER_SIZE + 1];
// 	char		*line;
// 	char		*newline;
// 	int			countread;

// 	line = ft_strdupp(buf);
// 	countread = read(fd, buf, BUFFER_SIZE);
// 	while (!(ft_strchr(line, '\n')) && (countread > 0))
// 	{
// 		buf[countread] = '\0';
// 		line = ft_strjoinn(line, buf, countread);
// 		countread = read(fd, buf, BUFFER_SIZE);
// 	}
// 	if (ft_strlen(line) == 0)
// 		return (free(line), NULL);
// 	newline = ft_strchr(line, '\n');
// 	ft_strlcpyy_utils(buf, &line, &newline);
// 	return (line);
// }
