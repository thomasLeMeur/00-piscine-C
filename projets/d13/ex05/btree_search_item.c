/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 11:18:33 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/18 11:18:34 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	t_btree	*elem;

	if (!root)
		return (NULL);
	if (root->left)
	{
		if ((*cmpf)(root->left->item, data_ref) == 0)
			return (root->left);
		elem = btree_search_item(root->left, data_ref, cmpf);
		if (elem)
			return (elem);
	}
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root);
	if (root->right)
	{
		if ((*cmpf)(root->right->item, data_ref) == 0)
			return (root->right);
		elem = btree_search_item(root->right, data_ref, cmpf);
		if (elem)
			return (elem);
	}
	return (NULL);
}
