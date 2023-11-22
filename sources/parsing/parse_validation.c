/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:32:23 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/22 14:27:05 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	int	f;

	i = 0;
	f = 0;
	while (i < parse->map_height && parse->map[i])
	{
		j = 0;
		while (parse->map[i][j])
		{
			if (ft_strchr("NSEW", parse->map[i][j]))
				f++;
			else if (parse->map[i][j] != '1' && parse->map[i][j] != ' ' &&
				parse->map[i][j] != '0' && parse->map[i][j] != '\n')
				return (ft_putendl_fd(UNKNOWN_IDENTIFIER, 2), 1);
			j++;
		}
		i++;
	}
	if (f > 1)
		return(ft_putendl_fd(MULTIPLE_PLAYER_POS, 2), 1);
	else if (f < 1)
		return (ft_putendl_fd(PLAYER_POS_NOT_FOUND, 2), 1);
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

