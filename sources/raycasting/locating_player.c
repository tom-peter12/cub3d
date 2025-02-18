/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locating_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:29:11 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/26 18:43:42 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_spawn_player_ew(t_game *game, char *str)
{
	if (str[0] == 'E')
	{
		game->fps.dir.x = 0;
		game->fps.dir.y = 1;
		game->fps.plane.x = -0.66;
		game->fps.plane.y = 0;
		game->fps.angle = 0;
	}
	else if (str[0] == 'W')
	{
		game->fps.dir.x = 0;
		game->fps.dir.y = -1;
		game->fps.plane.x = 0.66;
		game->fps.plane.y = 0;
		game->fps.angle = 180;
	}
}

void	ft_spawn_player(t_game *game, char *str)
{
	if (str[0] == 'N')
	{
		game->fps.dir.x = -1;
		game->fps.dir.y = 0;
		game->fps.plane.x = 0;
		game->fps.plane.y = -0.66;
		game->fps.angle = 270;
	}
	else if (str[0] == 'S')
	{
		game->fps.dir.x = 1;
		game->fps.dir.y = 0;
		game->fps.plane.x = 0;
		game->fps.plane.y = 0.66;
		game->fps.angle = 0;
	}
	else
		ft_spawn_player_ew(game, str);
}

void	ft_locate_player(t_game *game)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (i < (int)game->parse.map->height)
	{
		j = 0;
		while (game->parse.map->tab[i] && game->parse.map->tab[i][j])
		{
			str = ft_strchr("NSEW", game->parse.map->tab[i][j]);
			if (str)
			{
				game->fps.pos.x = i + 0.5;
				game->fps.pos.y = j + 0.5;
				ft_spawn_player(game, str);
				return ;
			}
			j++;
		}
		i++;
	}
}
