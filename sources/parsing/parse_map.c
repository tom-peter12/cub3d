/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:49:04 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/23 01:36:07 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	map_end(t_parse *parse)
{
	int	i;

	i = 0;
	while (parse->map_tmp && parse->map_tmp[i])
		i++;
	while (i > 0 && !white_space(parse->map_tmp[i - 1]))
		i--;
	return (i);
}

static int	ft_not_enclosed(t_map *map, size_t i, size_t j)
{
	ssize_t	down;
	ssize_t	left;
	ssize_t	right;
	ssize_t	up;
	size_t	len;

	if (i == 0 || i == map->height - 1 || j == 0
		|| j == ft_strlen(map->tab[i]) - 1)
		return (1);
	up = i - 1;
	down = i + 1;
	if (ft_check_up_down(map, j, &down, &up))
		return (1);
	left = j - 1;
	while (left >= 0 && map->tab[i][left] != '1')
		left--;
	right = j + 1;
	len = ft_strlen(map->tab[i]);
	while (right < (ssize_t)len && map->tab[i][right] != '1')
		right++;
	if (up < 0 || down >= (ssize_t)map->height || \
		left < 0 || right >= (ssize_t)len)
		return (1);
	return (0);
}

int	space_to_one(char *str)
{
	int	len;
	int	j;

	if (!str)
		return (1);
	len = ft_strlen(str);
	j = 0;
	while (str[j] == ' ')
		j++;
	while (str && j < len && str[j] != 0)
	{
		if (str[j] == ' ')
			str[j] = '1';
		j++;
	}
	return (0);
}

int	ft_everything_enclosed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i] && i < (int)map->height)
	{
		j = 0;
		while ((j < (int)ft_strlen(map->tab[i])))
		{
			if (map->tab[i][j] == '0' || ft_strchr("NWSE", map->tab[i][j]))
				if (ft_not_enclosed(map, i, j))
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
	char		*strtmp;

	map_len = map_end(parse);
	i = 0;
	ft_init_valid_map(parse, parse->map, map_len);
	while (i < map_len)
	{
		strtmp = ft_strrtrim(parse->map_tmp[i], " \n");
		ft_memcpy(parse->map->tab[i], strtmp, ft_strlen(strtmp) + 1);
		if (space_to_one(parse->map->tab[i]))
			return (1);
		i++;
		free(strtmp);
	}
	parse->map->tab[i] = 0;
	if (ft_everything_enclosed(parse->map))
		return (ft_putendl_fd(MAP_NOT_ENCLOSED, 2), 1);
	return (0);
}
