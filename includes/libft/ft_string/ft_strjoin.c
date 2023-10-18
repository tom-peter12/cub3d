/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:36:30 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/30 21:15:02 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_j;
	int		i;
	int		j;

	if (!(s1) || !(s2))
		return (NULL);
	str_j = (char *)malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1);
	i = 0;
	j = 0;
	if (!str_j)
		return (0);
	while (s1[i])
	{
		str_j[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str_j[i] = s2[j];
		j++;
		i++;
	}
	str_j[i] = '\0';
	return (str_j);
}
