/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:40:58 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/08 14:30:13 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_isattr_dup(t_parse *parse, int dir)
{
	if (parse->dup_check[dir] != 0)
		return (ft_putendl_fd(DUPLICATE_ATTR, 2), 1);
	parse->dup_check[dir] = 1;
	return (0);
}

int	ft_is_dir(char *dir)
{
	int	fd;

	fd = open(dir, O_DIRECTORY);
	if (fd >= 0)
	{
		ft_putendl_fd(NOT_FILE, 2);
		return (close(fd), 1);
	}
	else
		return (0);
}

int	ft_check_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error", 2);
		return (perror(""), 1);
	}
	if (ft_is_dir(path))
		return (1);
	return (0);
}
