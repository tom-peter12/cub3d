/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:29:28 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/28 13:03:54 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_entity(t_entity *info, bool is_player)
{
	if (is_player)
	{
		info->max_iter = 4;
		info->angle_offset = 180;
		info->clr = 0xFF0000;
	}
	else
	{
		info->max_iter = 11;
		info->angle_offset = 0;
		info->clr = 0x00FF00;
	}
}

void	draw_entity(t_game *game, bool is_player)
{
	t_entity	info;
	t_vector2	begin;
	double		i;

	ft_init_entity(&info, is_player);
	info.rotation_angle = game->fps.angle + 30 + info.angle_offset;
	while (info.rotation_angle >= game->fps.angle - 30 + info.angle_offset)
	{
		begin.x = 100;
		begin.y = 100;
		i = 0;
		while (i < info.max_iter)
		{
			begin.x += cos(info.rotation_angle * M_PI / 180);
			begin.y += sin(info.rotation_angle * M_PI / 180);
			game->cmlx.addr[(int)begin.x * WIN_WIDTH + (int)begin.y] = info.clr;
			i++;
		}
		info.rotation_angle -= 0.25;
	}
}

void	draw_mini_map(t_game *game, t_vector2 *iter, t_vector2 *pixel_pos)
{
	if (((iter->y) / MINIMAP_SCALE) >= 0 && ((iter->y) / MINIMAP_SCALE) < \
		(int)game->parse.map->height && ((iter->x) / MINIMAP_SCALE) >= 0 && \
			((iter->x) / MINIMAP_SCALE) < (int)game->parse.map->width)
	{
		if (game->parse.map->tab[(int)((iter->y) / MINIMAP_SCALE)] \
			[(int)(iter->x / MINIMAP_SCALE)] == '1')
			game->cmlx.addr[(int)pixel_pos->x * WIN_WIDTH + \
			(int)pixel_pos->y] = 0;
		else if (ft_strchr("NSWE0", game->parse.map->tab[(int)((iter->y) / \
			MINIMAP_SCALE)][(int)((iter->x) / MINIMAP_SCALE)]))
			game->cmlx.addr[(int)pixel_pos->x * WIN_WIDTH + \
			(int)pixel_pos->y] = clr_rgb(game->parse.map->c_floor);
		else
			game->cmlx.addr[(int)pixel_pos->x * WIN_WIDTH + \
			(int)pixel_pos->y] = 0x0000FF;
	}
	else
		game->cmlx.addr[(int)pixel_pos->x * WIN_WIDTH + \
		(int)pixel_pos->y] = 0x0000FF;
	(iter->x)++;
	pixel_pos->x++;
}

void	minimap2d(t_game *game)
{
	t_vector2	pos_mini;
	t_vector2	iter;
	t_vector2	pixel_pos;

	pos_mini.x = game->fps.pos.y * MINIMAP_SCALE;
	pixel_pos.y = 0;
	pos_mini.y = game->fps.pos.x * MINIMAP_SCALE;
	iter.x = pos_mini.x - MINIMAP_CENTER;
	iter.y = pos_mini.y - MINIMAP_CENTER;
	while (iter.y < pos_mini.y + MINIMAP_CENTER)
	{
		iter.x = pos_mini.x - MINIMAP_CENTER;
		pixel_pos.x = 0;
		while (iter.x < pos_mini.x + MINIMAP_CENTER)
			draw_mini_map(game, &iter, &pixel_pos);
		iter.y++;
		pixel_pos.y++;
	}
	draw_entity(game, true);
	draw_entity(game, false);
}
