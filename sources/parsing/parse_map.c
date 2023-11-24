/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:49:04 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/24 22:30:29 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int white_space(char *str)
{
    int i;

    i = 0;
    while (str && str[i])
    {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
            return (1);
        i++;
    }
    return (0);
}

int	map_end(t_parse *parse)
{
	int	i;

	i = 0;
	while (parse->map && parse->map[i])
		i++;
	while (i > 0 && !white_space(parse->map[i - 1]))
        i--;
	return (i);		
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
	if (ft_map_bordered(&map))
		return (1);
	return (0);	
}
