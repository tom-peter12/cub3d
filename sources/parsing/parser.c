/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:53:56 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/20 19:15:23 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
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
		if (!ft_is_all_digit(ft_strtrim(colors[i], " \t\n\v\f\r")))
		{
			ft_double_array_free(tmp);
			ft_double_array_free(colors);
			return (ft_putendl_fd(INVALID_COLOR, 2), 1);
		}
		if (ft_atoi(colors[i]) < 0 || ft_atoi(colors[i]) > 255)
		{
			ft_double_array_free(tmp);
			ft_double_array_free(colors);
			return (ft_putendl_fd(COLOR_OUT_OF_RANGE, 2), 1);
		}
	}
	return (0);
}

void	parser(t_parse *parse, int argc, char **argv)
{
	if (ft_init_parse(parse))
		exit_return_freer(parse);
	if (ft_validate_args(parse, argc, argv))
		exit_return_freer(parse);
	if (ft_fill_parser(parse))
		exit_return_freer(parse);
	if (ft_validate_parsed(parse))
		exit_return_freer(parse);
}
