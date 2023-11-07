/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:53:56 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/07 15:38:32 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_color_validate(char *str)
{
	char	**tmp;
	char	**colors;
	int		i;

	i = -1;
	tmp = ft_split(str, ' ');
	colors = NULL;
	if (tmp && tmp[0] && tmp[1])
		colors = ft_split(tmp[1], ',');
	while (colors && colors[++i])
	{
		if (!ft_is_all_digit(colors[i]))
		{
			ft_double_array_free(tmp);
			ft_double_array_free(colors);
			return (ft_putendl_fd("Error\nColor must be digits", 2), 1);
		}
		if (ft_atoi(colors[i]) < 0 || ft_atoi(colors[i]) > 255)
		{
			ft_double_array_free(tmp);
			ft_double_array_free(colors);
			return (ft_putendl_fd("Error\nColor out of range", 2), 1);
		}
	}
	return (0);
}
