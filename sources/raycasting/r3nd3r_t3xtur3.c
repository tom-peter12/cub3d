/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r3nd3r_t3xtur3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:50:03 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/19 19:32:26 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	tex_side(t_game *game)
{
	if (game->ray.dda.side == 0 && game->ray.ray_vec.x > 0)
	{
		game->tex_dim.x = game->texture[NO].width;
		game->tex_dim.y = game->texture[NO].height;
	}
	else if (game->ray.dda.side == 0 && game->ray.ray_vec.x < 0)
	{
		game->tex_dim.x = game->texture[SO].width;
		game->tex_dim.y = game->texture[SO].height;
	}
	else if (game->ray.dda.side == 1 && game->ray.ray_vec.x > 0)
	{
		game->tex_dim.x = game->texture[EA].width;
		game->tex_dim.y = game->texture[EA].height;
	}
	else if (game->ray.dda.side == 1 && game->ray.ray_vec.x < 0)
	{
		game->tex_dim.x = game->texture[WE].width;
		game->tex_dim.y = game->texture[WE].height;
	}
}

int	get_color(t_game *game)
{
	int	color;

	color = 0;
	if (game->ray.dda.side == 0 && game->ray.ray_vec.x > 0)
		color = *(game->texture[NO].addr + \
			(int)(game->tex_dim.y * game->tex_y + game->tex_x));
	else if (game->ray.dda.side == 0 && game->ray.ray_vec.x < 0)
		color = *(game->texture[SO].addr + \
			(int)(game->tex_dim.y * game->tex_y + game->tex_x));
	else if (game->ray.dda.side == 1 && game->ray.ray_vec.y > 0)
		color = *(game->texture[EA].addr + \
			(int)(game->tex_dim.y * game->tex_y + game->tex_x));
	else if (game->ray.dda.side == 1 && game->ray.ray_vec.y < 0)
		color = *(game->texture[WE].addr + \
			(int)(game->tex_dim.y * game->tex_y + game->tex_x));
	return (color);
}

void	texture_addr(t_game *game)
{
	game->texture[NO].addr = (int *)mlx_get_data_addr(game->texture[NO].img, \
		&game->texture[NO].bpp, &game->texture[NO].ll, &game->texture[NO].en);
	game->texture[SO].addr = (int *)mlx_get_data_addr(game->texture[SO].img, \
		&game->texture[SO].bpp, &game->texture[SO].ll, &game->texture[SO].en);
	game->texture[EA].addr = (int *)mlx_get_data_addr(game->texture[EA].img, \
		&game->texture[EA].bpp, &game->texture[EA].ll, &game->texture[EA].en);
	game->texture[WE].addr = (int *)mlx_get_data_addr(game->texture[WE].img, \
		&game->texture[WE].bpp, &game->texture[WE].ll, &game->texture[WE].en);
}

void	texture_mapping(t_game *game)
{
	double	wallx;

	if (game->ray.dda.side == 0)
		wallx = game->fps.pos.y + game->ray.dda.wall_dist * game->ray.ray_vec.y;
	else
		wallx = game->fps.pos.x + game->ray.dda.wall_dist * game->ray.ray_vec.x;
	wallx -= floor(wallx);
	game->tex_x = (int)(wallx * game->tex_dim.x);
	if (game->ray.dda.side == 0 && game->ray.ray_vec.x < 0)
		game->tex_x = game->tex_dim.x - game->tex_x - 1;
	if (game->ray.dda.side == 1 && game->ray.ray_vec.y > 0)
		game->tex_x = game->tex_dim.x - game->tex_x - 1;
	texture_addr(game);
}

void	texture_rendering(t_game *game, int i)
{
	double	step;
	double	texpos;
	int		y;
	int		color;

	color = 0;
	tex_side(game);
	texture_mapping(game);
	step = 1.0 * game->tex_dim.y / game->ray.dda.line_height;
	texpos = (game->ray.dda.draw_start - WIN_HEIGHT / 2 + \
		game->ray.dda.line_height / 2) * step;
	y = game->ray.dda.draw_start;
	while (y < game->ray.dda.draw_end + 1)
	{
		game->tex_y = (int)texpos & (int)(game->tex_dim.y - 1);
		texpos += step;
		color = get_color(game);
		game->cmlx.addr[y * WIN_WIDTH + i] = color;
		y++;
	}
}
