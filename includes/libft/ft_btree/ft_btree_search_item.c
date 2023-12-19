/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:57:09 by tpetros           #+#    #+#             */
/*   Updated: 2023/12/19 19:13:04 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_btree_search_item(t_btree *root, void *data_ref, \
			int (*cmpf)(void *, void *))
{
	void	*left_search;
	void	*right_search;

	if (!root || !cmpf || !data_ref)
		return (NULL);
	left_search = ft_btree_search_item(root->left, data_ref, cmpf);
	if (left_search)
		return (left_search);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	right_search = ft_btree_search_item(root->right, data_ref, cmpf);
	if (right_search)
		return (right_search);
	return (NULL);
}
