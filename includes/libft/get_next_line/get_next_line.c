/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:01:46 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/24 00:14:05 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_all_read(int fd, char *left_stat)
{
	char	*buff_read;
	int		read_bytes;

	read_bytes = 1;
	buff_read = (char *)ft_calloc((sizeof(char) * (size_t)BUFFER_SIZE + 2), 1);
	if (!buff_read)
		return (NULL);
	while (!ft_strchr(buff_read, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff_read, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes <= -1)
		{
			free(buff_read);
			return (NULL);
		}
		buff_read[read_bytes] = '\0';
		left_stat = ft_strjoin(left_stat, buff_read);
	}
	free(buff_read);
	return (left_stat);
}

char	*ft_stripped_line(char *stat_chars)
{
	char	*line_stripped;
	size_t	i;

	i = 0;
	if (!stat_chars[i])
		return (NULL);
	while (stat_chars[i] && stat_chars[i] != '\n')
		i++;
	if (stat_chars[i++] == '\n')
		i++;
	line_stripped = (char *) malloc(sizeof(char) * (i + 1));
	if (!line_stripped)
		return (NULL);
	i = -1;
	while (stat_chars[++i] && stat_chars[i] != '\n')
		line_stripped[i] = stat_chars[i];
	if (stat_chars[i] == '\n')
		line_stripped[i++] = '\n';
	line_stripped[i] = '\0';
	return (line_stripped);
}

char	*ft_left_chars(char *extraline)
{
	size_t	i;
	size_t	j;
	char	*the_rest;

	i = 0;
	j = 0;
	while (extraline[i] && extraline[i] != '\n')
		i++;
	if (extraline[i] == '\0')
	{
		free(extraline);
		return (NULL);
	}
	if (extraline[i] == '\n')
		i++;
	the_rest = (char *) malloc(sizeof(char) * (ft_strlen(extraline + i) + 1));
	if (!the_rest)
		return (NULL);
	while (extraline[i])
		the_rest[j++] = extraline[i++];
	the_rest[j] = '\0';
	free(extraline);
	return (the_rest);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*extra_chars;

	if (fd < 0 || BUFFER_SIZE > INT_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	extra_chars = ft_all_read(fd, extra_chars);
	if (!extra_chars)
		return (NULL);
	next_line = ft_stripped_line(extra_chars);
	extra_chars = ft_left_chars(extra_chars);
	return (next_line);
}
