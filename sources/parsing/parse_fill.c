/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:39:18 by tpetros           #+#    #+#             */
/*   Updated: 2024/01/01 14:02:35 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_texture_filler(t_parse *parse, t_trims *trims)
{
	if (ft_double_array_len(trims->tmp) != 2)
	{
		if (ft_double_array_len(trims->tmp) < 2)
			ft_putendl_fd(MISSING_TEXTURE_PATH, 2);
		else if (ft_double_array_len(trims->tmp) > 2)
			ft_putendl_fd(EXTRA_TOKEN_FOR_PATH, 2);
		ft_double_array_free(trims->tmp);
		free(trims->strpd);
		exit_return_freer(parse, 1);
	}
	if (ft_strcmp(trims->tmp[0], "NO") == 0)
		check_and_save_path(parse, trims, NO);
	else if (ft_strcmp(trims->tmp[0], "SO") == 0)
		check_and_save_path(parse, trims, SO);
	else if (ft_strcmp(trims->tmp[0], "WE") == 0)
		check_and_save_path(parse, trims, WE);
	else if (ft_strcmp(trims->tmp[0], "EA") == 0)
		check_and_save_path(parse, trims, EA);
}

static int	ft_fill_attributes_util(t_parse *parse, t_trims *trims)
{
	if (ft_strcmp(trims->strpd, "NO") == 0 || \
		ft_strcmp(trims->strpd, "SO") == 0 || \
			ft_strcmp(trims->strpd, "WE") == 0 || \
				ft_strcmp(trims->strpd, "EA") == 0)
		ft_texture_filler(parse, trims);
	else if (ft_strcmp(trims->strpd, "C") == 0 || \
		ft_strcmp(trims->strpd, "F") == 0)
	{
		if (ft_ceiling_floor(parse, trims->strpd))
			return (free(trims->strpd), ft_double_array_free(trims->tmp), 1);
	}
	else if (trims->strpd[0] != ' ' && trims->strpd[0] \
		!= '\n' && trims->strpd[0] != '\0')
		return (free(trims->strpd), ft_putendl_fd(UNKNOWN_IDENTIFIER, 2), \
			ft_double_array_free(trims->tmp), 1);
	return (0);
}

int	ft_fill_attributes(t_parse *parse)
{
	static int	i;
	t_trims		trims;
	static int	map_line = 1;

	trims.trimmed_p_line = ft_strrtrim(parse->line, " \n");
	if ((!trims.trimmed_p_line || trims.trimmed_p_line[0] == '\0'))
	{
		if (i == 1 && map_line < parse->map_height)
			return (ft_putendl_fd(EMPTY_LINE_IN_MAP, 2), 1);
		return (0);
	}
	trims.tmp = ft_msplit(trims.trimmed_p_line, " ");
	trims.strpd = ft_strtrim(trims.tmp[0], " \n");
	if (i == 0 && (ft_strchr(trims.tmp[0], '1') || \
		ft_strchr(trims.tmp[0], '0')) && is_defo_map_line(trims.strpd))
		i = 1;
	if (i == 0)
	{
		if (ft_fill_attributes_util(parse, &trims))
			return (free(trims.trimmed_p_line), 1);
		ft_double_array_free(trims.tmp);
	}
	else
		ft_fill_map_parser(parse, trims.tmp, &map_line);
	return (free(trims.trimmed_p_line), free(trims.strpd), 0);
}

void	ft_map_dimension(t_parse *parse)
{
	int				start_counting;
	static int		null_end = 0;
	int				len;

	start_counting = 0;
	len = 0;
	while (parse->line)
	{
		len = ft_strlen(parse->line) - 1;
		if (len > parse->map_width)
			parse->map_width = len;
		if (start_counting || is_defo_map_line(parse->line))
		{
			if (!is_defo_map_line(parse->line))
				null_end++;
			else
				null_end = 0;
			if (!start_counting)
				start_counting = 1;
			parse->map_height++;
		}
		free(parse->line);
		parse->line = get_next_line(parse->map_fd);
	}
	parse->map_height -= null_end;
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
