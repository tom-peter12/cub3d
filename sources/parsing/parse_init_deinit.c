/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init_deinit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:51 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/22 14:26:45 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_init_parse(t_parse *parse)
{
	parse->no = NULL;
	parse->so = NULL;
	parse->we = NULL;
	parse->ea = NULL;
	parse->floor = NULL;
	parse->ceiling = NULL;
	parse->dup_check = (int *)malloc(7 * sizeof(int));
	if (!parse->dup_check)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	ft_bzero(parse->dup_check, 7 * sizeof(int));
	if (!parse->map_file)
		parse->map_file = NULL;
	parse->map_height = 0;
	parse->map_width = 0;
	return (0);
}
void	exit_return_freer(t_parse *parse)
{
	if (parse->no)
		free(parse->no);
	if (parse->so)
		free(parse->so);
	if (parse->we)
		free(parse->we);
	if (parse->ea)
		free(parse->ea);
	if (parse->floor)
		free(parse->floor);
	if (parse->ceiling)
		free(parse->ceiling);
	if (parse->map)
		ft_double_array_free(parse->map);
	if (parse->dup_check)
		free(parse->dup_check);
	if (parse->map_fd)
		close(parse->map_fd);
	exit(1);
}
