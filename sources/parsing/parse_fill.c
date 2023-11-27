/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:39:18 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/27 21:12:59 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_fill_map_parser(t_parse *parse, char *str)
{
	static int	i;

	if (str)
		parse->map[i] = ft_strdup(str);
	i++;
	if (i == parse->map_height)
		parse->map[i] = 0;
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

int	ft_fill_attributes(t_parse *parse, char *str)
{
	char		**tmp;
	static int	i = 0;
	char		*stripped;

	tmp = ft_msplit(str, " ");
	stripped = ft_strtrim(tmp[0], "\n");
	if (i == 0 && ft_strchr(stripped, '1') && is_defo_map_line(stripped))
		i = 1;
	if (i == 0)
	{
		if (ft_strcmp(stripped, "NO") == 0 && !ft_isattr_dup(parse, NO))
			parse->no = ft_strdup(str);
		else if (ft_strcmp(stripped, "SO") == 0 && !ft_isattr_dup(parse, SO))
			parse->so = ft_strdup(str);
		else if (ft_strcmp(stripped, "WE") == 0 && !ft_isattr_dup(parse, WE))
			parse->we = ft_strdup(str);
		else if (ft_strcmp(stripped, "EA") == 0 && !ft_isattr_dup(parse, EA))
			parse->ea = ft_strdup(str);
		else if (ft_strcmp(stripped, "F") == 0 && !ft_isattr_dup(parse, F))
			parse->floor = ft_strdup(str);
		else if (ft_strcmp(stripped, "C") == 0 && !ft_isattr_dup(parse, C))
			parse->ceiling = ft_strdup(str);
		else if (stripped[0] != ' ' && stripped[0] != '\n' && stripped[0] != '\0')
		{
			free(stripped);
			ft_putendl_fd(UNKNOWN_IDENTIFIER, 2);
			return (ft_double_array_free(tmp), 1);
		}
	}
	else
		ft_fill_map_parser(parse, str);
	free(stripped);
	ft_double_array_free(tmp);
	return (0);
}

void	ft_map_dimension(t_parse *parse)
{
	char	**tmp;
	int		start_counting;
	int		len;

	(0 || (start_counting = 0) || (len = 0));
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
	parse->map = ft_calloc(sizeof(char *), parse->map_height + 1);
	if (parse->map == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	parse->map_fd = open(parse->map_file, O_RDONLY);
	parse->line = get_next_line(parse->map_fd);
	while (parse->line)
	{
		if (ft_fill_attributes(parse, parse->line))
			return (1);
		free(parse->line);
		parse->line = get_next_line(parse->map_fd);
	}
	return (0);
}
