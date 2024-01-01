/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r3nd3r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:09:03 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/18 21:26:39 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render(t_game *game, int i)
{
	int	j;

	j = 0;
	while (j < game->ray.dda.draw_start)
	{
		game->cmlx.addr[j * WIN_WIDTH + i] = clr_rgb(game->parse.map->c_ceil);
		j++;
	}
	while (j < WIN_HEIGHT)
	{
		game->cmlx.addr[j * WIN_WIDTH + i] = clr_rgb(game->parse.map->c_floor);
		(j)++;
	}
	texture_rendering(game, i);
}
