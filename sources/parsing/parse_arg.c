/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:37:35 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/21 03:53:47 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_validate_args(t_parse *parse, int argc, char **argv)
{
	if (argc == 1 || argv[1][0] == '\0')
		return (ft_putendl_fd(CUB_FILE_MISSING, 1), 1);
	if (argc > 2)
		return (ft_putendl_fd(INVALID_ARG_NUM, 2), 1);
	if (argv[1] && (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub") != 0
			|| (ft_strcmp(argv[1], ".cub") == 0)))
	{
		ft_putendl_fd(INVALID_FILE_EXT, 2);
		return (1);
	}
	parse->map_file = ft_strdup(argv[1]);
	if (ft_check_file(parse->map_file))
		return (1);
	return (0);
}

char	*ft_strrtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;

	if (!(s1) || !(set))
		return (NULL);
	left = 0;
	right = ft_strlen(s1);
	if (right == 0)
		return (NULL);
	right--;
	while (s1[right] && ft_strchr(set, s1[right]))
	{
		right--;
	}
	return (ft_substr(s1, left, right - left + 1));
}
