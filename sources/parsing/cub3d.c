/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:25:48 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/08 14:58:16 by tpetros          ###   ########.fr       */
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

void	ft_init_parse(t_parse *parse)
{
	parse->no = NULL;
	parse->so = NULL;
	parse->we = NULL;
	parse->ea = NULL;
	parse->floor = NULL;
	parse->ceiling = NULL;
	parse->map = (char **)malloc(sizeof(char *) * 100);
	if (parse->map == NULL)
		return (ft_putendl_fd(MALLOC_FAIL, 2));
	parse->dup_check = (int *)malloc(7 * sizeof(int));
	if (!parse->dup_check)
		return (ft_putendl_fd(MALLOC_FAIL, 2));
	ft_bzero(parse->dup_check, 7 * sizeof(int));
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_parse	parse;

	ft_init_parse(&parse);
	if (ft_validate_args(&parse, argc, argv))
		return (1);
	if (ft_validate_cub(&parse))
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	// ft_init_win(data);
	return (0);
}
