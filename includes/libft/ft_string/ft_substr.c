/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:57:54 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/30 21:15:02 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (len >= s_len)
		substr = (char *)malloc((s_len + 1));
	else
		substr = (char *)malloc((len + 1));
	if (!substr)
		return (0);
	while ((start < s_len) && (i < len && i < s_len))
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
