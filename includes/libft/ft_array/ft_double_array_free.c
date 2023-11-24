/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_array_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:31:05 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/24 13:23:58 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/libft.h"

void	ft_double_array_free(char **arr)
{
	char	**tmp;

	tmp = arr;
	if (!arr)
		return ;
	while (tmp && *tmp)
	{
		if (*tmp)
			free(*tmp);
		*tmp = NULL;
		tmp++;
	}
	free(arr);
}
