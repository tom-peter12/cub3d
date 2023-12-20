/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:53:56 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/21 03:52:34 by hatesfam         ###   ########.fr       */
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

int	ft_invalid_char(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_strchr("0123456789", str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_color_validate(char **str)
{
	int		i;
	char	*tmp;

	i = -1;
	while (str && str[++i])
	{
		tmp = ft_strtrim(str[i], " ");
		if (ft_strlen(tmp) == 0)
			return (free(tmp), ft_putendl_fd(COLOR_SHOULD_RGB, 1), 1);
		if (ft_invalid_char(tmp))
			return (free(tmp), ft_putendl_fd(INVALID_CHAR_COLOR, 2), 1);
		if (ft_atoi(tmp) < 0 || ft_atoi(tmp) > 255)
		{
			free(tmp);
			return (ft_putendl_fd(COLOR_OUT_OF_RANGE, 2), 1);
		}
		free(tmp);
	}
	return (0);
}

void	parser(t_parse *parse, int argc, char **argv)
{
	if (ft_init_parse(parse))
		exit_return_freer(parse, 1);
	if (ft_validate_args(parse, argc, argv))
		exit_return_freer(parse, 1);
	if (ft_fill_parser(parse))
		exit_return_freer(parse, 1);
	if (ft_validate_parsed(parse))
		exit_return_freer(parse, 1);
}
