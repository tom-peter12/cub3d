/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:59:16 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/24 18:08:13 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strreplace(char **pold, const char *new)
{
	if (!pold)
		return NULL;
	if (*pold)
		free(*pold);
	if (new)
		*pold = ft_strdup(new);
	else
		*pold = NULL;
	return (*pold);
}

