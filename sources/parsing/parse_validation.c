/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:32:23 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/28 19:03:20 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	empty_texture_field(t_parse *parse)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!parse->textures[i])
			return (ft_putendl_fd(MISSING_TEXTURE_PATH, 2), 1);
		i++;
	}
	return (0);
}

int	ft_valid_map(t_parse *parse)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	f = 0;
	while (i < parse->map_height && parse->map_tmp[i])
	{
		j = 0;
		while (parse->map_tmp[i][j])
		{
			if (ft_strchr("NSEW", parse->map_tmp[i][j]))
				f++;
			else if (parse->map_tmp[i][j] != '1' && parse->map_tmp[i][j] != ' ' &&
				parse->map_tmp[i][j] != '0' && parse->map_tmp[i][j] != '\n')
					return (ft_putendl_fd(UNKNOWN_IDENTIFIER, 2), 1);
			j++;
		}
		i++;
	}
	if (f > 1)
		return(ft_putendl_fd(MULTIPLE_PLAYER_POS, 2), 1);
	else if (f < 1)
		return (ft_putendl_fd(PLAYER_POS_NOT_FOUND, 2), 1);
	if (ft_closed_map(parse))
		return (1);
	return (0);
}

int	ft_validate_parsed(t_parse *parse)
{
	if (empty_texture_field(parse))
		return (1);
	if (ft_valid_map(parse))
		return (1);
	return (0);
}
