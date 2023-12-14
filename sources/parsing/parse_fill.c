/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:39:18 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/14 16:09:49 by tpetros          ###   ########.fr       */
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
		return (1);
	c_f_val_arr = ft_split(c_f_val, ',');
	if (ft_double_array_len(c_f_val_arr) != 3)
	{
		ft_double_array_free(c_f_val_arr);
		return (ft_putendl_fd(COLOR_SHOULD_RGB, 2), 1);
	}
	if (ft_color_validate(c_f_val_arr))
		return (1);
	color_fill(parse, c_f_val_arr, c_f);
	return (0);
}

void	check_and_save_path(t_parse *parse, char **str)
{
	char	*stripped;

	stripped = ft_strtrim(str[1], "\n");
	if (ft_check_file(stripped))
		exit_return_freer(parse);
	if (ft_strcmp(str[0], "NO") == 0)
		parse->textures[NO] = ft_strdup(stripped);
	else if (ft_strcmp(str[0], "SO") == 0)
		parse->textures[SO] = ft_strdup(stripped);
	else if (ft_strcmp(str[0], "WE") == 0)
		parse->textures[WE] = ft_strdup(stripped);
	else if (ft_strcmp(str[0], "EA") == 0)
		parse->textures[EA] = ft_strdup(stripped);
}

void	ft_texture_filler(t_parse *parse, char **tmp)
{
	if (ft_double_array_len(tmp) != 2)
	{
		ft_double_array_free(tmp);
		ft_putendl_fd(MISSING_TEXTURE_PATH, 2);
		exit_return_freer(parse);
	}
	if (ft_strcmp(tmp[0], "NO") == 0 && !ft_isattr_dup(parse, NO))
		check_and_save_path(parse, tmp);
	else if (ft_strcmp(tmp[0], "SO") == 0 && !ft_isattr_dup(parse, SO))
		check_and_save_path(parse, tmp);
	else if (ft_strcmp(tmp[0], "WE") == 0 && !ft_isattr_dup(parse, WE))
		check_and_save_path(parse, tmp);
	else if (ft_strcmp(tmp[0], "EA") == 0 && !ft_isattr_dup(parse, EA))
		check_and_save_path(parse, tmp);
}

int	ft_fill_attributes(t_parse *parse)
{
	static int	i;
	char		**tmp;
	char		*stripped;
		
	tmp = ft_msplit(parse->line, " ");
	stripped = ft_strtrim(tmp[0], "\n");
	if (i == 0 && ft_strchr(stripped, '1') && is_defo_map_line(stripped))
		i = 1;
	if (i == 0)
	{
		if (ft_strcmp(stripped, "NO") == 0 || ft_strcmp(stripped, "SO") == 0
			|| ft_strcmp(stripped, "WE") == 0 || ft_strcmp(stripped, "EA") == 0)
				ft_texture_filler(parse, tmp);			
		else if (ft_strcmp(stripped, "C") == 0 || ft_strcmp(stripped, "F") == 0)
			ft_ceiling_floor(parse, stripped);
		else if (stripped[0] != ' ' && stripped[0] != '\n' && stripped[0] != '\0')
		{
			free(stripped);
			ft_putendl_fd(UNKNOWN_IDENTIFIER, 2);
			return (ft_double_array_free(tmp), 1);
		}
	}
	else
		ft_fill_map_parser(parse);
	free(stripped);
	ft_double_array_free(tmp);
	return (0);
}

void	ft_map_dimension(t_parse *parse)
{
	char	**tmp;
	int		start_counting;
	int		len;

	start_counting = 0;
	len = 0;
	while (parse->line)
	{
		tmp = ft_split(parse->line, ' ');
		if (tmp && tmp[0])
		{
			len = ft_strlen(tmp[0]) - 1;
			if (len > parse->map_width)
				parse->map_width = len;
			if (start_counting || tmp[0][0] == '1' || tmp[0][0] == '0')
			{
				if (!start_counting)
					start_counting = 1;
				parse->map_height++;
			}
		}
		ft_double_array_free(tmp);
		free(parse->line);
		parse->line = get_next_line(parse->map_fd);
	}
	close(parse->map_fd);
}

int	ft_fill_parser(t_parse *parse)
{
	parse->map_fd = open(parse->map_file, O_RDONLY);
	parse->line = get_next_line(parse->map_fd);
	if (!parse->line)
		return (ft_putendl_fd("Error\nEmpty File", 2), 1);
	ft_map_dimension(parse);
	if (parse->map_height == 0)
		return (ft_putendl_fd(EMPTY_MAP, 2), 1);
	parse->map_tmp = ft_calloc(sizeof(char *), parse->map_height + 1);
	if (parse->map_tmp == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	parse->map_fd = open(parse->map_file, O_RDONLY);
	parse->line = get_next_line(parse->map_fd);
	while (parse->line)
	{
		if (ft_fill_attributes(parse))
			return (1);
		free(parse->line);
		parse->line = get_next_line(parse->map_fd);
	}
	return (0);
}
