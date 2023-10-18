/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:38:06 by tpetros           #+#    #+#             */
/*   Updated: 2023/09/30 23:58:27 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_btree *ft_btree_create_node(void *item)
{
	t_btree		*b_tree;
	
	if (!item)
		return (NULL);
	b_tree = (t_btree *) malloc(sizeof(t_btree) + 1);
	if (!b_tree)
		return (NULL);
	b_tree->item = item;
	b_tree->left = NULL;
	b_tree->right = NULL;
	return (b_tree);
}

