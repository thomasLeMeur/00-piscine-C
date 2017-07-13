/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 14:41:28 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/16 14:41:29 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
	void *data_ref, int (*cmp)())
{
	t_list	*i;

	i = begin_list;
	if (i)
	{
		while (i)
		{
			if ((*cmp)(i->data, data_ref) == 0)
				(*f)(i->data);
			i = i->next;
		}
	}
}
