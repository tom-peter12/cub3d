/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:15:12 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/03 18:03:51 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	*ft_range(int min, int max)
{
	int	i;
	int	*ptr;

	if (max - min > __INT_MAX__)
		return (NULL);
	ptr = (int *)malloc(sizeof(int) * (max - min));
	if (min >= max || ptr == NULL || !ptr)
		return (NULL);
	i = 0;
	while (min < max)
	{
		ptr[i] = min;
		i++;
		min++;
	}
	return (ptr);
}
