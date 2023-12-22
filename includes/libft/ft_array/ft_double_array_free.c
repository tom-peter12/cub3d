/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_array_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:31:05 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/22 20:01:37 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
	arr = NULL;
}

// void	ft_double_array_free(char **arr)
// {
// 	int i;

// 	i = 0;
// 	if (!arr)
// 		return ;
// 	while (arr[i])
// 	{
// 		if (arr[i])
// 			free(arr[i]);
// 		i++;
// 	}
// 	free(arr);
// }
