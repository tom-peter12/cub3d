/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:39:18 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/08 14:52:15 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_is_map_last(t_parse *parse)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (parse->dup_check[i] == 0)
			return (ft_putendl_fd(MAP_NOT_LAST, 2), 1);
		i++;
	}
	return (0);
}

int	ft_fill_map_parser(t_parse *parse, char *str)
{
	static int	i;
	
	if (ft_is_map_last(parse))
		return (1);
	if (str)
		parse->map[i] = ft_strdup(str);
	i++;
	return (0);
}


int	ft_fill_attributes(t_parse *parse, char *str)
{
	char	**tmp;
	
	tmp = ft_split(str, ' ');
	if (ft_strcmp(tmp[0], "NO") == 0 && !ft_isattr_dup(parse, NO))
		parse->no = ft_strdup(str);
	else if (ft_strcmp(tmp[0], "SO") == 0 && !ft_isattr_dup(parse, SO))
		parse->so = ft_strdup(str);
	else if (ft_strcmp(tmp[0], "WE") == 0 && !ft_isattr_dup(parse, WE))
		parse->we = ft_strdup(str);
	else if (ft_strcmp(tmp[0], "EA") == 0 && !ft_isattr_dup(parse, EA))
		parse->ea = ft_strdup(str);
	else if (ft_strcmp(tmp[0], "F") == 0 && !ft_isattr_dup(parse, F))
		parse->floor = ft_strdup(str);
	else if (ft_strcmp(tmp[0], "C") == 0 && !ft_isattr_dup(parse, C))
		parse->ceiling = ft_strdup(str);
	else if (ft_strchr(tmp[0], '1') || ft_strchr(tmp[0], '0'))
	{
		if (ft_fill_map_parser(parse, str))
			return (1);
	}
	else if (tmp[0][0] != ' ' && tmp[0][0] != '\n' && tmp[0][0] != '\0')
		return (1);
	ft_double_array_free(tmp);
	tmp = NULL;
	return (0);
}

int	ft_fill_parser(t_parse *parse)
{
	parse->line = get_next_line(parse->map_fd);
	if (!parse->line)
		return (ft_putendl_fd(EMPTY_MAP, 2), 1);
	while (parse->line)
	{
		if (ft_fill_attributes(parse, parse->line))
			return (1);
		// printf("%s", parse->line);
		free(parse->line);
		parse->line = get_next_line(parse->map_fd);
	}
	// printf("%s", parse->no);
	// printf("%s", parse->so);
	// printf("%s", parse->we);
	// printf("%s", parse->ea);
	// printf("%s", parse->floor);
	// printf("%s\n", parse->ceiling);
	// ft_double_array_printer(parse->map);
	return (0);
}
 