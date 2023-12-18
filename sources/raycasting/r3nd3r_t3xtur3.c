/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r3nd3r_t3xtur3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:50:03 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/18 21:40:03 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int tex_width, tex_height;

void	tex_side(t_game *game)
{
	if (game->ray.dda.side == 0 && game->ray.ray_vec.x > 0)
	{
		tex_width = game->texture[NO].width;
		tex_height = game->texture[NO].height;
	}
	else if (game->ray.dda.side == 0 && game->ray.ray_vec.x < 0)
	{
		tex_width = game->texture[SO].width;
		tex_height = game->texture[SO].height;
	}
	else if (game->ray.dda.side == 1 && game->ray.ray_vec.x > 0)
	{
		tex_width = game->texture[EA].width;
		tex_height = game->texture[EA].height;
	}
	else if (game->ray.dda.side == 1 && game->ray.ray_vec.x < 0)
	{
		tex_width = game->texture[WE].width;
		tex_height = game->texture[WE].height;
	}
}


int	get_color(t_game *game)
{
	int	color;

	color = 0;
	if (game->ray.dda.side == 0 && game->ray.ray_vec.x > 0)
		color = *(game->texture[NO].addr + (tex_width * game->tex_y + game->tex_x));
	else if (game->ray.dda.side == 0 && game->ray.ray_vec.x < 0)
		color = *(game->texture[SO].addr + (tex_width * game->tex_y + game->tex_x));
	else if (game->ray.dda.side == 1 && game->ray.ray_vec.y > 0)
		color = *(game->texture[EA].addr + (tex_width * game->tex_y + game->tex_x));
	else if (game->ray.dda.side == 1 && game->ray.ray_vec.y < 0)
		color = *(game->texture[WE].addr + (tex_width * game->tex_y + game->tex_x));
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
	game->tex_x = (int)-(wallx * (double)tex_height);
	if (game->ray.dda.side == 0 && game->ray.ray_vec.x > 0)
		game->tex_x = tex_height - game->tex_x - 1;
	if (game->ray.dda.side == 1 && game->ray.ray_vec.y < 0)
		game->tex_x = tex_height - game->tex_x - 1;
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
	step = 1.0 * tex_width / game->ray.dda.line_height;
	texpos = (game->ray.dda.draw_start - WIN_HEIGHT / 2 + \
		game->ray.dda.line_height / 2) * step;
	y = game->ray.dda.draw_start;
	while (y < game->ray.dda.draw_end + 1)
	{
		game->tex_y = (int)texpos & (tex_width - 1);
		texpos += step;
		color = get_color(game);
		if (game->ray.dda.side == 1)
			color = (color >> 1) & 8355711;
		game->cmlx.addr[y * WIN_WIDTH + i] = color;
		y++;
	}
}
