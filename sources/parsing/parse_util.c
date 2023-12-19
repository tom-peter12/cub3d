/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:40:58 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/19 21:39:55 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	white_space(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_up_down(t_map *map, size_t j, ssize_t *down, ssize_t *up)
{
	while (*up >= 0 && map->tab[*up][j] != '1')
	{
		if (*up == 0 || map->tab[*up][j] == '\0')
			return (1);
		(*up)--;
	}
	while (*down < (ssize_t)map->height && map->tab[*down][j] != '1')
	{
		if (*down == (ssize_t)map->height || map->tab[*down][j] == '\0')
			return (1);
		(*down)++;
	}
	return (0);
}

int	ft_isattr_dup(t_parse *parse, int dir)
{
	if (parse->dup_check[dir] > 1)
		return (ft_putendl_fd(DUPLICATE_ATTR, 2), 1);
	parse->dup_check[dir]++;
	return (0);
}

int	ft_is_dir(char *dir)
{
	int	fd;

	fd = open(dir, O_DIRECTORY);
	if (fd >= 0)
	{
		ft_putendl_fd(NOT_FILE, 2);
		return (close(fd), 1);
	}
	return (0);
}

int	ft_check_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putendl_fd(path, 2);
		return (perror(""), 1);
	}
	if (ft_is_dir(path))
		return (1);
	return (0);
}
