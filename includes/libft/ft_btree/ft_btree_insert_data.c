/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:15:38 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/19 19:15:30 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_btree_insert_data(t_btree **root, void *item, \
		int (*cmpf)(void *, void *))
{
	if (!root || !item || !cmpf)
		return ;
	if (*root == NULL)
		*root = ft_btree_create_node(item);
	else if (cmpf((*root)->item, item) < 0)
		ft_btree_insert_data(&(*root)->right, item, cmpf);
	else
		ft_btree_insert_data(&(*root)->left, item, cmpf);
}
