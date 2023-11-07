/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:39:18 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/07 14:32:19 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_fill_map_parser(t_parse *parse, char *str)
{
	static int	i;

	if (str)
		parse->map[i] = ft_strdup(str);
	i++;
}

int	ft_fill_attributes(t_parse *parse, char *str)
{
	char	**tmp;
	
	tmp = ft_split(str, ' ');
	if (ft_strcmp(tmp[0], "NO") == 0 && !ft_isattr_dup(parse, NO))
		parse->no = str;
	else if (ft_strcmp(tmp[0], "SO") == 0 && !ft_isattr_dup(parse, SO))
		parse->so = str;
	else if (ft_strcmp(tmp[0], "WE") == 0 && !ft_isattr_dup(parse, WE))
		parse->we = str;
	else if (ft_strcmp(tmp[0], "EA") == 0 && !ft_isattr_dup(parse, EA))
		parse->ea = str;
	else if (ft_strcmp(tmp[0], "F") == 0 && !ft_isattr_dup(parse, F))
		parse->floor = str;
	else if (ft_strcmp(tmp[0], "C") == 0 && !ft_isattr_dup(parse, C))
		parse->floor = str;
	else if (ft_strchr(str, '1') || ft_strchr(str, '0'))
		ft_fill_map_parser(parse, str);
	else if (tmp[0][0] != ' ' && tmp[0][0] != '\n' && tmp[0][0] != '\0')
	{
		printf("%s\n", tmp[0]);
		return (ft_putendl_fd("Error\nInvalid map", 2), 1);
	}
	ft_double_array_free(tmp);
	tmp = NULL;
	return (0);
}

int	ft_fill_parser(t_parse *parse)
{	
	parse->line = get_next_line(parse->map_fd);
	if (!parse->line)
		return (ft_putendl_fd("Error\nFile cannot be empty", 2), 1);
	while (parse->line)
	{
		if (ft_fill_attributes(parse, parse->line))
			return (1);
		free(parse->line);
		parse->line = get_next_line(parse->map_fd);
	}
	return (0);
}
 