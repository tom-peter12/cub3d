/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:49:04 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/25 17:41:34 by tpetros          ###   ########.fr       */
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

int	check_up_bottom(t_valid_map *map, int pos)
{
	int	i;
	int	len;
	
	i = 0;
	len = ft_strlen(map->tab[pos]) - 1;
	while (i < len)
	{
		if (map->tab[pos][i] != '1' && map->tab[pos][i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int check_edges(t_valid_map *map, int i)
{
    int len;
    int j;

    len = ft_strlen(map->tab[i]) - 2;
    j = 0;
    while (map->tab[i][j] == ' ')
        j++;
    if (map->tab[i][j] != '1')
        return (1);
    while (len > j && map->tab[i][len] == ' ')
        len--;
    if (map->tab[i][len] != '1')
        return (1);
    for (int k = j + 1; k < len; k++)
    {
        if (map->tab[i][k] == ' ')
            map->tab[i][k] = '1';
    }
    return (0);
}

int	check_side_ways(t_valid_map *map)
{
	int	i;
	
	i = 0;
	while (map->tab && map->tab[i])
	{
		if (check_edges(map, i))
			return (1);
		i++;
	}
	return (0);
}

int	ft_map_bordered(t_valid_map *map)
{
	if (check_up_bottom(map, 0))
		return (ft_putendl_fd(MAP_NOT_ENCLOSED, 2), 1);
	if (check_up_bottom(map, map->height - 1))
		return (ft_putendl_fd(MAP_NOT_ENCLOSED, 2), 1);
	if (check_side_ways(map))
		return (ft_putendl_fd(MAP_NOT_ENCLOSED,2), 1);
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

void	change_space_to_one(t_valid_map *map)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		len = ft_strlen(map->tab[i]) - 1;
		while (j < len)
		{
			if (map->tab[i][j] == ' ')
				map->tab[i][j] = '1';
			j++;
		}
		i++;
	}
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
	change_space_to_one(&map);
	if (ft_everything_enclosed(&map))
		return (1);
	ft_double_array_printer(map.tab);
	return (0);
}
