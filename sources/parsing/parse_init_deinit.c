/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init_deinit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:51 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/28 18:55:15 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_init_ceiling_floor(t_parse *parse)
{
	parse->map->c_ceil = ft_calloc(2, sizeof(t_color));
	if (!parse->map->c_ceil)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	parse->map->c_ceil->r = -1;
	parse->map->c_ceil->b = -1;
	parse->map->c_ceil->g = -1;
	parse->map->c_floor = ft_calloc(2, sizeof(t_color));
	if (!parse->map->c_floor)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	parse->map->c_floor->r = -1;
	parse->map->c_floor->b = -1;
	parse->map->c_floor->g = -1;
	return (0);
}

int	ft_init_parse(t_parse *parse)
{
	parse->textures = (char **)ft_calloc(5, sizeof(char *));
	if (!parse->textures)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	parse->dup_check = (int *)ft_calloc(7, sizeof(int));
	if (!parse->dup_check)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	parse->map_file = NULL;
	parse->map_height = 0;
	parse->map_tmp = NULL;
	parse->line = NULL;
	parse->map_width = 0;
	parse->map = ft_calloc(2, sizeof(t_map));
	if (!parse->map)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	if (ft_init_ceiling_floor(parse))
		return (1);
	return (0);
}

void	exit_return_freer(t_parse *parse, int flag)
{
	if (parse->textures)
		ft_double_array_free(parse->textures);
	if (parse->map_tmp)
		ft_double_array_free(parse->map_tmp);
	if (parse->dup_check)
		free(parse->dup_check);
	if (parse->map_fd)
		close(parse->map_fd);
	if (parse->map)
	{
		if (parse->map->c_ceil)
			free(parse->map->c_ceil);
		if (parse->map->c_floor)
			free(parse->map->c_floor);
		if (parse->map->tab)
			ft_double_array_free(parse->map->tab);
		free(parse->map);
	}
	if (parse->line)
		free(parse->line);
	if (parse->map_file)
		free(parse->map_file);
	exit(flag);
}

int	ft_init_valid_map(t_parse *parse, t_map *map, int len)
{
	size_t	i;

	i = 0;
	map->tab = ft_calloc(sizeof(char *), len + 1);
	if (!map->tab)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	map->width = parse->map_width;
	map->height = len;
	while (i < map->height)
	{
		map->tab[i] = ft_calloc(sizeof(char), map->width + 1);
		if (!map->tab[i])
			return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
		i++;
	}
	return (0);
}
