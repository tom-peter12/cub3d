/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:36:24 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/30 21:15:02 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*p;
	unsigned char		*q;

	p = (unsigned char *) s1;
	q = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while ((*p == *q) && n - 1 > 0)
	{
		p++;
		q++;
		n--;
	}
	return ((int)(*p - *q));
}
