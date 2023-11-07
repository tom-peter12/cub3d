/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:40:58 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/07 14:31:05 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_isattr_dup(t_parse *parse, int dir)
{
	if (parse->dup_check[dir] != 0)
		return (ft_putendl_fd("Error\nDuplicate attribute", 2), 1);
	parse->dup_check[dir] = 1;
	return (0);
}

int	ft_is_dir(char *dir)
{
	int	fd;

	fd = open(dir, O_DIRECTORY);
	if (fd >= 0)
	{
		ft_putendl_fd("Error\nPlease provide a file", 2);
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
		ft_putstr_fd("\e[0;31mError: \e[0m", 2);
		ft_putendl_fd(path, 2);
		return (perror(""), 1);
	}
	if (ft_is_dir(path))
		return (1);
	return (0);
}
