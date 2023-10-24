/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:39:18 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/24 17:39:40 by tpetros          ###   ########.fr       */
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

int	ft_fill_parser(t_parse *parse)
{
	char	**tmp;
	
	parse->line = get_next_line(parse->map_fd);
	if (!parse->line)
		return (ft_putendl_fd("Error\nFile cannot be empty", 2), 1);
	while (parse->line)
	{
		tmp = ft_split(parse->line, ' ');
		if (ft_strcmp(tmp[0], "NO") == 0)
			parse->no = parse->line;
		else if (ft_strcmp(tmp[0], "SO") == 0)
			parse->so = parse->line;
		else if (ft_strcmp(tmp[0], "WE") == 0)
			parse->we = parse->line;
		else if (ft_strcmp(tmp[0], "EA") == 0)
			parse->ea = parse->line;
		else if (ft_strcmp(tmp[0], "F") == 0)
			parse->floor = parse->line;
		else if (ft_strcmp(tmp[0], "C") == 0)
			parse->floor = parse->line;
		else if (ft_strchr(parse->line, '1') || ft_strchr(parse->line, '0'))
			ft_fill_map_parser(parse, parse->line);
		else if (tmp[0][0] != ' ' && tmp[0][0] != '\n' && tmp[0][0] != '\0')
			break ;
		free(parse->line);
		parse->line = get_next_line(parse->map_fd);
		ft_double_array_free(tmp);
		tmp = NULL;
	}
	return (0);
}
