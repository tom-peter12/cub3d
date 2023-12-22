/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:39:18 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/23 00:47:09 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_texture_filler(t_parse *parse, char **tmp, char *strpd)
{
	if (ft_double_array_len(tmp) != 2)
	{
		if (ft_double_array_len(tmp) < 2)
			ft_putendl_fd(MISSING_TEXTURE_PATH, 2);
		else if (ft_double_array_len(tmp) > 2)
			ft_putendl_fd(EXTRA_TOKEN_FOR_PATH, 2);
		ft_double_array_free(tmp);
		free(strpd);
		exit_return_freer(parse, 1);
	}
	(void)strpd;
	if (ft_strcmp(tmp[0], "NO") == 0)
		check_and_save_path(parse, tmp, NO);
	else if (ft_strcmp(tmp[0], "SO") == 0)
		check_and_save_path(parse, tmp, SO);
	else if (ft_strcmp(tmp[0], "WE") == 0)
		check_and_save_path(parse, tmp, WE);
	else if (ft_strcmp(tmp[0], "EA") == 0)
		check_and_save_path(parse, tmp, EA);
}

static int	ft_fill_attributes_util(t_parse *parse, char **tmp, char *strpd)
{
	if (ft_strcmp(strpd, "NO") == 0 || ft_strcmp(strpd, "SO") == 0 \
		|| ft_strcmp(strpd, "WE") == 0 || ft_strcmp(strpd, "EA") == 0)
		ft_texture_filler(parse, tmp, strpd);
	else if (ft_strcmp(strpd, "C") == 0 || ft_strcmp(strpd, "F") == 0)
	{
		if (ft_ceiling_floor(parse, strpd))
			return (free(strpd), 1);
	}
	else if (strpd[0] != ' ' && strpd[0] != '\n' && strpd[0] != '\0')
		return (free(strpd), ft_putendl_fd(UNKNOWN_IDENTIFIER, 2), \
			ft_double_array_free(tmp), 1);
	return (0);
}

int	ft_fill_attributes(t_parse *parse)
{
	static int	i;
	char		**tmp;
	char		*strpd;
	char		*trimmed_p_line;
	static int	map_line = 1;

	trimmed_p_line = ft_strrtrim(parse->line, " \n");
	if ((!trimmed_p_line || trimmed_p_line[0] == '\0'))
	{
		if (i == 1 && map_line < parse->map_height)
			return (ft_putendl_fd(EMPTY_LINE_IN_MAP, 2), 1);
		if (trimmed_p_line)
			free(trimmed_p_line);
		map_line++;
		return (0);
	}
	tmp = ft_msplit(trimmed_p_line, " ");
	strpd = ft_strtrim(tmp[0], " \n");
	if (i == 0 && ft_strchr(tmp[0], '1') && is_defo_map_line(strpd))
		i = 1;
	if (i == 0)
	{
		if (ft_fill_attributes_util(parse, tmp, strpd))
			return (1);
	}
	else
		ft_fill_map_parser(parse);
	map_line++;
	return (free(trimmed_p_line), free(strpd), ft_double_array_free(tmp), 0);
}

void	ft_map_dimension(t_parse *parse)
{
	int		start_counting;
	int		len;

	start_counting = 0;
	len = 0;
	while (parse->line)
	{
		len = ft_strlen(parse->line) - 1;
		if (len > parse->map_width)
			parse->map_width = len;
		if (start_counting || is_defo_map_line(parse->line))
		{
			if (!start_counting)
				start_counting = 1;
			parse->map_height++;
		}
		free(parse->line);
		parse->line = get_next_line(parse->map_fd);
	}
}

int	ft_fill_parser(t_parse *parse)
{
	parse->map_fd = open(parse->map_file, O_RDONLY);
	parse->line = get_next_line(parse->map_fd);
	if (!parse->line)
		return (ft_putendl_fd(EMPTY_FILE, 2), 1);
	ft_map_dimension(parse);
	close(parse->map_fd);
	if (parse->map_height == 0)
		return (ft_putendl_fd(EMPTY_MAP, 2), 1);
	parse->map_tmp = ft_calloc(sizeof(char *), (parse->map_height + 1));
	if (parse->map_tmp == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	parse->map_fd = open(parse->map_file, O_RDONLY);
	parse->line = get_next_line(parse->map_fd);
	while (parse->line)
	{
		if (ft_fill_attributes(parse))
			return (1);
		free(parse->line);
		parse->line = get_next_line(parse->map_fd);
	}
	close(parse->map_fd);
	return (0);
}
