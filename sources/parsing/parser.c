/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:53:56 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/25 14:20:50 by tpetros          ###   ########.fr       */
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
static int ft_invalid_char(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_strchr("FC,0123456789 \t\n", str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_color_validate(char *str)
{
	char	**colors;
	int		i;

	if (ft_invalid_char(str))
		return (ft_putendl_fd(INVALID_CHAR_COLOR, 2), 1);
	i = 0;
	colors = ft_msplit(str, " ,\n");
	if (ft_double_array_len(colors) != 4)
	{
		ft_double_array_free(colors);
		return (ft_putendl_fd(COLOR_SHOULD_RGB, 2), 1);
	}
	while (colors && colors[++i])
	{
		if (!ft_is_all_digit(colors[i]))
		{
			ft_double_array_free(colors);
			return (ft_putendl_fd(INVALID_COLOR, 2), 1);
		}
		if (ft_atoi(colors[i]) < 0 || ft_atoi(colors[i]) > 255)
		{
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
