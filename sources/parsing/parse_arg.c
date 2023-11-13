/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:37:35 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/13 13:07:31 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_returner(char *src)
{
	char	**tmp;
	char	*ret;

	tmp = ft_split(src, ' ');
	ret = ft_strtrim(tmp[1], " \t\r\v\f");
	ft_double_array_free(tmp);
	tmp = NULL;
	return (ret);
}

int	ft_color(t_parse *parse)
{
	if (ft_color_validate(parse->floor))
		return (1);
	if (ft_color_validate(parse->ceiling))
		return (1);
	return (0);
}

int	ft_texture_files(t_parse *parse)
{
	char	**tmp;

	tmp = ft_wsplit(parse->no);
	if (!tmp[1] || ft_check_file(tmp[1]))
		return (ft_putendl_fd(MISSIN_NO_PATH, 1), ft_double_array_free(tmp), 1);
	ft_double_array_free(tmp);
	tmp = ft_wsplit(parse->so);
	if (!tmp[1] || ft_check_file(tmp[1]))
		return (ft_putendl_fd(MISSIN_SO_PATH, 1), ft_double_array_free(tmp), 1);
	ft_double_array_free(tmp);
	tmp = ft_wsplit(parse->we);
	if (!tmp[1] || ft_check_file(tmp[1]))
		return (ft_putendl_fd(MISSIN_WE_PATH, 1), ft_double_array_free(tmp), 1);
	ft_double_array_free(tmp);
	tmp = ft_wsplit(parse->ea);
	if (!tmp[1] || ft_check_file(tmp[1]))
		return (ft_putendl_fd(MISSIN_EA_PATH, 1), ft_double_array_free(tmp), 1);
	ft_double_array_free(tmp);
	tmp = NULL;
	return (0);
}

int	ft_check_map(t_parse *parse, int i, int j)
{
	(void) parse;
	(void) i;
	(void) j;
	return (0);
}

int	ft_valid_map(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (parse->map[i])
	{
		j = 0;
		while (parse->map[i][j])
		{
			if (ft_strchr(" 102NSEW\n", parse->map[i][j]))
			{
				if (ft_check_map(parse, i, j))
					return (1);
			}
			else if (parse->map[i][j] != '1' && parse->map[i][j] != ' ')
				return (ft_putendl_fd(UNKNOWN_IDENTIFIER, 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_validate_parsed(t_parse *parse)
{
	if (ft_color(parse))
		return (1);
	if (ft_texture_files(parse))
		return (1);
	if (ft_valid_map(parse))
		return (1);
	return (0);
}

int	ft_validate_cub(t_parse *parse)
{
	if (ft_check_file(parse->map_file))
		return (1);
	parse->map_fd = open(parse->map_file, O_RDONLY);
	if (ft_fill_parser(parse))
		return (1);
	if (ft_validate_parsed(parse))
		return (1);
	return (0);
}
