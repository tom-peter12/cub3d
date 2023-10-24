/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:28:34 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/24 17:29:24 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_init_parser(t_parse *parse)
{
	parse->line = NULL;
	parse->map_file = NULL;
	parse->map_fd = -1;
	parse->map = (char **) ft_calloc(1, sizeof(char *));
	if (!parse->map)
		return (ft_putendl_fd("Error\nAllocation failed", 2), 1);
	parse->ceiling = NULL;
	parse->floor = NULL;
	parse->no = NULL;
	parse->so = NULL;
	parse->we = NULL;
	parse->ea = NULL;
	return (0);
}
