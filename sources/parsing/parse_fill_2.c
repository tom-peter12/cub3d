/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:23:59 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/19 21:48:25 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_fill_map_parser(t_parse *parse)
{
	static int	i;

	if (parse->line)
		parse->map_tmp[i] = ft_strdup(parse->line);
	i++;
	if (i == parse->map_height)
		parse->map_tmp[i] = 0;
}

int	is_defo_map_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != '\n' || str[i] != ' ' || str[i] != 'W' || str[i] != 'N'
				|| str[i] != 'S' || str[i] != 'E' || str[i] != '1'
				|| str[i] != '0'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_comma_check(char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (ft_putendl_fd(INVALID_CHAR_COLOR, 2), 1);
	return (0);
}

void	color_fill(t_parse *parse, char **color, char *c_f)
{
	if (ft_strcmp(c_f, "C") == 0)
	{
		parse->map->c_ceil->r = ft_atoi(color[0]);
		parse->map->c_ceil->g = ft_atoi(color[1]);
		parse->map->c_ceil->b = ft_atoi(color[2]);
	}
	else
	{
		parse->map->c_floor->r = ft_atoi(color[0]);
		parse->map->c_floor->g = ft_atoi(color[1]);
		parse->map->c_floor->b = ft_atoi(color[2]);
	}
}

int	ft_ceiling_floor(t_parse *parse, char *c_f)
{
	char	*c_f_val;
	char	**c_f_val_arr;
	int		i;

	i = 0;
	while (parse->line[i] != ' ')
		i++;
	c_f_val = ft_substr(parse->line, i + 1, ft_strlen(parse->line) - 3);
	if (ft_comma_check(c_f_val))
		return (free(c_f_val), 1);
	c_f_val_arr = ft_split(c_f_val, ',');
	if (ft_double_array_len(c_f_val_arr) != 3)
	{
		ft_double_array_free(c_f_val_arr);
		return (free(c_f_val), ft_putendl_fd(COLOR_SHOULD_RGB, 2), 1);
	}
	if (ft_color_validate(c_f_val_arr))
		return (free(c_f_val), ft_double_array_free(c_f_val_arr), 1);
	if (!ft_isattr_dup(parse, C))
	color_fill(parse, c_f_val_arr, c_f);
	free(c_f_val);
	return (0);
}
