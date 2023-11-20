/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:39:18 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/20 19:12:49 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_is_map_last(t_parse *parse)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (parse->dup_check[i] == 0)
			return (ft_putendl_fd(MAP_NOT_LAST, 2), 1);
		i++;
	}
	return (0);
}

void	ft_fill_map_parser(t_parse *parse, char *str)
{
	static int	i;
	
	if (str)
		parse->map[i] = ft_strdup(str);
	i++;
	if (i == parse->map_height)
		parse->map[i] = 0;
}


int	ft_fill_attributes(t_parse *parse, char *str)
{
	char		**tmp;
	
	tmp = ft_split(str, ' ');
	if (ft_strcmp(tmp[0], "NO") == 0 && !ft_isattr_dup(parse, NO))
		parse->no = ft_strdup(str);
	else if (ft_strcmp(tmp[0], "SO") == 0 && !ft_isattr_dup(parse, SO))
		parse->so = ft_strdup(str);
	else if (ft_strcmp(tmp[0], "WE") == 0 && !ft_isattr_dup(parse, WE))
		parse->we = ft_strdup(str);
	else if (ft_strcmp(tmp[0], "EA") == 0 && !ft_isattr_dup(parse, EA))
		parse->ea = ft_strdup(str);
	else if (ft_strcmp(tmp[0], "F") == 0 && !ft_isattr_dup(parse, F))
		parse->floor = ft_strdup(str);
	else if (ft_strcmp(tmp[0], "C") == 0 && !ft_isattr_dup(parse, C))
		parse->ceiling = ft_strdup(str);
	else if (tmp[0][0] == '1' || ft_strchr(tmp[0], '0'))
		ft_fill_map_parser(parse, str);
	else if (tmp[0][0] != ' ' && tmp[0][0] != '\n' && tmp[0][0] != '\0')
	{
		ft_putendl_fd(UNKNOWN_IDENTIFIER, 2);
		return (ft_double_array_free(tmp), 1);
	}
	ft_double_array_free(tmp);
	tmp = NULL;
	return (0);
}

int	ft_empty_field(t_parse *parse)
{
	if (parse->no == NULL )
		return (ft_putendl_fd(MISSING_NO, 2), 1);
	else if (parse->so == NULL)
		return (ft_putendl_fd(MISSING_SO, 2), 1);
	else if (parse->we == NULL)
		return (ft_putendl_fd(MISSING_WE, 2), 1);
	else if (parse->ea == NULL)
		return (ft_putendl_fd(MISSING_EA, 2), 1);
	else if (parse->floor == NULL)
		return (ft_putendl_fd(MISSING_F, 2), 1);
	else if (parse->ceiling == NULL)
		return (ft_putendl_fd(MISSING_C, 2), 1);
	return (0);
}

void	ft_map_dimension(t_parse *parse)
{
	char	**tmp;
	int		f;

	(0 || (parse->map_fd = open(parse->map_file, O_RDONLY)) || (f = 0));
	parse->line = get_next_line(parse->map_fd);
	while (parse->line)
	{
		tmp = ft_split(parse->line, ' ');
		if ((int)ft_strlen(tmp[0]) - 1 > parse->map_width)
			parse->map_width = ft_strlen(tmp[0]) - 1;
		if (tmp[0][0] == '1' || tmp[0][0] == '0')
			(0 || ((parse->map_height++) && (f++)));
		if (f > 0 && ft_strcmp(tmp[0], "\n") == 0)
		{
			ft_putendl_fd(NEW_LINE_IN_MAP, 2);
			free(parse->line);
			ft_double_array_free(tmp);
			close(parse->map_fd);
			exit_return_freer(parse);
		}
		free(parse->line);
		ft_double_array_free(tmp);
		parse->line = get_next_line(parse->map_fd);
	}
	close(parse->map_fd);
	free(parse->line);
}

int	ft_fill_parser(t_parse *parse)
{
	ft_map_dimension(parse);
	printf("map dim %d X %d\n", parse->map_width, parse->map_height);
	parse->map = (char **)malloc(sizeof(char *) * parse->map_height + 1);
	if (parse->map == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	parse->map_fd = open(parse->map_file, O_RDONLY);
	parse->line = get_next_line(parse->map_fd);
	if (!parse->line)
		return (ft_putendl_fd(EMPTY_MAP, 2), 1);
	while (parse->line)
	{
		if (ft_fill_attributes(parse, parse->line))
			return (1);
		free(parse->line);
		parse->line = get_next_line(parse->map_fd);
	}
	if (ft_empty_field(parse))
		return (1);
	return (0);
}
