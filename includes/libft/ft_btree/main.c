/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:14:34 by tpetros           #+#    #+#             */
/*   Updated: 2023/10/02 22:18:31 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr(void *str)
{
	printf("%s\n", (char *)str);
}

int main(void)
{
	t_btree *root;

	root = ft_btree_create_node("1");
	root->left = ft_btree_create_node("2");
	root->right = ft_btree_create_node("3");
	root->left->left = ft_btree_create_node("4");
	root->left->right = ft_btree_create_node("5");
	root->right->left = ft_btree_create_node("6");
	root->right->right = ft_btree_create_node("7");
	// ft_btree_apply_prefix(root, &ft_putstr);
	// printf("\n");
	// ft_btree_apply_infix(root, &ft_putstr);
	// printf("\n");
	// ft_btree_apply_suffix(root, &ft_putstr);
	// ft_btree_insert_data(&root, "0", &strcmp);
	// printf("\n");
	// ft_btree_apply_infix(root, &ft_putstr);
	
	// char *data_ref = "6";

	// printf("%s\n", (char *)ft_btree_search_item(root, data_ref, &strcmp));
	
	printf("%d\n", ft_btree_level_count(root));
	return (0);
}
