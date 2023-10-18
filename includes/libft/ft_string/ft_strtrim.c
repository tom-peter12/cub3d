/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:09:54 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/30 21:15:02 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;

	if (!(s1) || !(set))
		return (NULL);
	left = 0;
	right = ft_strlen(s1) - 1;
	while (s1[left] && ft_strchr(set, s1[left]))
	{
		left++;
	}
	while (s1[right] && ft_strrchr(set, s1[right]) && (right > left))
	{
		right--;
	}
	return (ft_substr(s1, left, right - left + 1));
}
