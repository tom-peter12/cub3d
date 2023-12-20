/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:39:18 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/20 21:17:18 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_and_save_path(t_parse *parse, char **str, int index)
{
	char	*stripped;

	stripped = ft_strtrim(str[1], "\n");
	if (parse->textures[index])
	{
		ft_putendl_fd(DUPLICATE_ATTR, 2);
		free(stripped);
		exit_return_freer(parse, 1);
	}
	if (ft_check_file(stripped))
	{
		free(stripped);
		exit_return_freer(parse, 1);
	}
	if (ft_strcmp(str[0], "NO") == 0)
		parse->textures[NO] = ft_strdup(stripped);
	else if (ft_strcmp(str[0], "SO") == 0)
		parse->textures[SO] = ft_strdup(stripped);
	else if (ft_strcmp(str[0], "WE") == 0)
		parse->textures[WE] = ft_strdup(stripped);
	else if (ft_strcmp(str[0], "EA") == 0)
		parse->textures[EA] = ft_strdup(stripped);
	free(stripped);
}

void	ft_texture_filler(t_parse *parse, char **tmp, char *strpd)
{
	if (ft_double_array_len(tmp) != 2)
	{
		ft_double_array_free(tmp);
		free(strpd);
		ft_putendl_fd(MISSING_TEXTURE_PATH, 2);
		exit_return_freer(parse, 1);
	}
	if (ft_strcmp(tmp[0], "NO") == 0)
		check_and_save_path(parse, tmp, NO);
	else if (ft_strcmp(tmp[0], "SO") == 0)
		check_and_save_path(parse, tmp, SO);
	else if (ft_strcmp(tmp[0], "WE") == 0)
		check_and_save_path(parse, tmp, WE);
	else if (ft_strcmp(tmp[0], "EA") == 0)
		check_and_save_path(parse, tmp, EA);
}

int	ft_fill_attributes(t_parse *parse)
{
	static int	i;
	char		**tmp;
	char		*strpd;

	tmp = ft_msplit(parse->line, " ");
	strpd = ft_strtrim(tmp[0], "\n");
	if (i == 0 && ft_strchr(strpd, '1') && is_defo_map_line(strpd))
		i = 1;
	if (i == 0)
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
	}
	else
		ft_fill_map_parser(parse);
	
	// ft_putendl_fd(parse->map_tmp[0], 1);
	// ft_putchar_fd('[', 1);
	// ft_putchar_fd(parse->map_tmp[0][36], 1);
	// ft_putchar_fd(']', 1);
	// ft_putchar_fd('\n', 1);
	
	return (free(strpd), ft_double_array_free(tmp), 0);
}

void	ft_map_dimension(t_parse *parse)
{
	char	**tmp;
	int		start_counting;
	int		len;

	start_counting = 0;
	len = 0;
	while (parse->line)
	{
		tmp = ft_split(parse->line, ' ');
		if (tmp && tmp[0])
		{
			len = ft_strlen(tmp[0]) - 1;
			if (len > parse->map_width)
				parse->map_width = len;
			if (start_counting || tmp[0][0] == '1' || tmp[0][0] == '0')
			{
				if (!start_counting)
					start_counting = 1;
				parse->map_height++;
			}
		}
		ft_double_array_free(tmp);
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
	parse->map_tmp = (char **)malloc(sizeof(char *) * parse->map_height + 1);
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
	// ft_double_array_printer(parse->map_tmp);
	close(parse->map_fd);
	return (0);
}
