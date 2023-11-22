/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_array_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:58:20 by tpetros           #+#    #+#             */
/*   Updated: 2023/11/21 11:07:05 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/libft.h"

size_t	ft_double_array_len(char **str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}
