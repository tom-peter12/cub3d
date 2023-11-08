/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:32:23 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/08 16:33:02 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_validate_args(t_parse *parse, int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
		return (ft_putendl_fd(INVALID_ARG_NUM, 2), 1);
	if (argv[1] && (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub") != 0
			|| (ft_strcmp(argv[1], ".cub") == 0)))
	{
		ft_putendl_fd(INVALID_FILE_EXT, 2);
		return (1);
	}
	parse->map_file = ft_strdup(argv[1]);
	return (0);
}
