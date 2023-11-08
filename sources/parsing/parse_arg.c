/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:37:35 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/08 14:44:21 by tpetros          ###   ########.fr       */
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
	if (ft_check_file(tmp[1]))
		return (ft_double_array_free(tmp), 1);
	ft_double_array_free(tmp);
	tmp = ft_wsplit(parse->so);
	if (ft_check_file(tmp[1]))
		return (ft_double_array_free(tmp), 1);
	ft_double_array_free(tmp);
	tmp = ft_wsplit(parse->we);
	if (ft_check_file(tmp[1]))
		return (ft_double_array_free(tmp), 1);
	ft_double_array_free(tmp);
	tmp = ft_wsplit(parse->ea);
	if (ft_check_file(tmp[1]))
		return (ft_double_array_free(tmp), 1);
	ft_double_array_free(tmp);
	tmp = NULL;
	return (0);
}

int	ft_validate_parsed(t_parse *parse)
{
	if (ft_color(parse))
		return (1);
	if (ft_texture_files(parse))
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

int	ft_validate_args(t_parse *parse, int argc, char **argv)
{
	char	**hold;

	if (argc != 2 || argv[1][0] == '\0')
		return (ft_putendl_fd(INVALID_ARG_NUM, 2), 1);
	hold = ft_wsplit(argv[1]);
	// printf("hold[0]: %s\n", hold[0]);
	if (hold[0] && (ft_strcmp(hold[0] + ft_strlen(hold[0]) - 4, ".cub") != 0
		|| (ft_strcmp(hold[0], ".cub") == 0)))
	{
		ft_putendl_fd(INVALID_FILE_EXT, 2);
		return (1);
	}
	parse->map_file = ft_strdup(hold[0]);
	ft_double_array_free(hold);
	hold = NULL;
	return (0);
}
