/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 15:20:01 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/16 15:20:02 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*i;

	i = begin_list;
	if (i)
	{
		while (i)
		{
			if ((*cmp)(i->data, data_ref) == 0)
				break ;
			i = i->next;
		}
	}
	return (i);
}
