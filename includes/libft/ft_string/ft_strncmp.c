/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:01:50 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/30 21:15:02 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*q;

	i = 0;
	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((p[i] == q[i]) && (p[i] != '\0' && q[i] != '\0') && (i < n - 1))
	{
		i++;
	}
	return ((int )(p[i] - q[i]));
}
