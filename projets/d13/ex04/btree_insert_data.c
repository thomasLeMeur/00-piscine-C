/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 10:52:48 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/18 10:52:49 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	if (!*root)
		return ((void)(*root = btree_create_node(item)));
	if ((*cmpf)((*root)->item, item) <= 0)
	{
		if ((*root)->right)
			btree_insert_data(&((*root)->right), item, cmpf);
		else
			(*root)->right = btree_create_node(item);
		return ;
	}
	if ((*root)->left)
		btree_insert_data(&((*root)->left), item, cmpf);
	else
		(*root)->left = btree_create_node(item);
}
