/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:51 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/08 16:35:27 by tpetros          ###   ########.fr       */
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
	parse->map = (char **)malloc(sizeof(char *) * 100);
	if (parse->map == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	parse->dup_check = (int *)malloc(7 * sizeof(int));
	if (!parse->dup_check)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	ft_bzero(parse->dup_check, 7 * sizeof(int));
	return (0);
}
