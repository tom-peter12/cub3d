/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:39:10 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/22 19:33:33 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *src, int c)
{
	unsigned char	*str;
	unsigned char	character;

	if (!src)
		return (NULL);
	str = (unsigned char *)src;
	character = (unsigned char)c;
	while (*str != character)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
