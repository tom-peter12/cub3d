/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init_deinit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:51 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/28 18:44:26 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_init_parse(t_parse *parse)
{
	parse->textures = (char **)ft_calloc(5, sizeof(char *));
	if (!parse->textures)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	parse->dup_check = (int *)ft_calloc(7, sizeof(int));
	if (!parse->dup_check)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	if (!parse->map_file)
		parse->map_file = NULL;
	parse->map_height = 0;
	parse->map_tmp = NULL;
	parse->map_width = 0;
	parse->map = ft_calloc(2, sizeof(t_map));
	parse->map->c_ceil = ft_calloc(2, sizeof(t_color));
	parse->map->c_floor = ft_calloc(2, sizeof(t_color));
	return (0);
}
void	exit_return_freer(t_parse *parse)
{
	if (parse->textures)
		ft_double_array_free(parse->textures);
	if (parse->map_tmp)
		ft_double_array_free(parse->map_tmp);
	if (parse->dup_check)
		free(parse->dup_check);
	if (parse->map_fd)
		close(parse->map_fd);
	exit(1);
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
