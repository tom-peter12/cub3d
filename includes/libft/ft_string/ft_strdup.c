/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:32:23 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/08 14:45:17 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*duplicated;
	int		i;

	i = 0;
	duplicated = (char *)malloc((ft_strlen(src) * sizeof(char)) + 1);
	if (!duplicated)
		return (NULL);
	while (src && src[i] != '\0')
	{
		duplicated[i] = src[i];
		i++;
	}
	duplicated[i] = '\0';
	return (duplicated);
}
