/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:25:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/16 19:19:34 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_win(t_data *data)
{
	data->cmlx->ptr = mlx_init();
	data->cmlx->mlx_win = mlx_new_window(data->cmlx->ptr, WIN_WIDTH, WIN_HEIGHT,
			"Wolfe... Nah cub3D");
	mlx_loop(data->cmlx);
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
	exit(1);
}

void	parser(t_parse *parse, int argc, char **argv)
{
	if (ft_init_parse(parse))
		exit_return_freer(parse);
	if (ft_validate_args(parse, argc, argv))
		exit_return_freer(parse);
	if (ft_fill_parser(parse))
		exit_return_freer(parse);
	if (ft_validate_parsed(parse))
		exit_return_freer(parse);
}

int	main(int argc, char **argv)
{
	t_parse	parse;

	parser(&parse, argc, argv);
	// ft_init_win(data);
	return (0);
}
