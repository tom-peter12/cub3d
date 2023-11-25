/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:49:04 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/25 14:07:07 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	white_space(char *str)
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

static int	map_end(t_parse *parse)
{
	int	i;

	i = 0;
	while (parse->map && parse->map[i])
		i++;
	while (i > 0 && !white_space(parse->map[i - 1]))
		i--;
	return (i);
}

static int	ft_is_enclosed(t_valid_map *map, size_t i, size_t j)
{
	ssize_t	down;
	ssize_t	left;
	ssize_t	right;
	ssize_t	up;
	size_t	len;

	up = i;
	while (up >= 0 && map->tab[up][j] != '1')
		up--;
	down = i;
	while (down < (ssize_t)map->height && map->tab[down][j] != '1')
		down++;
	left = j;
	while (left >= 0 && map->tab[i][left] != '1')
		left--;
	right = j;
	len = ft_strlen(map->tab[i]) - 1;
	while (right < (ssize_t)len && map->tab[i][right] != '1')
		right++;
	if (up < 0 || down >= (ssize_t)map->height || left < 0
		|| right >= (ssize_t)len)
		return (ft_putendl_fd(MAP_NOT_ENCLOSED, 2), 1);
	return (0);
}

static int	ft_everything_enclosed(t_valid_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(map->tab[i]) - 1)
		{
			if (map->tab[i][j] == '0' || ft_strchr("NWSE", map->tab[i][j]))
				if (ft_is_enclosed(map, i, j))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_closed_map(t_parse *parse)
{
	int			map_len;
	int			i;
	t_valid_map	map;

	map_len = map_end(parse);
	i = 0;
	ft_init_valid_map(parse, &map, map_len);
	while (i < map_len)
	{
		if (!white_space(parse->map[i]))
			return (ft_putendl_fd(NEW_LINE_IN_MAP, 2), 1);
		map.tab[i] = ft_strdup(parse->map[i]);
		i++;
	}
	map.tab[i] = 0;
	if (ft_everything_enclosed(&map))
		return (1);
	return (0);
}
