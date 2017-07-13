/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 16:13:52 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/16 16:13:53 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*i;
	t_list	*tmp;

	i = *begin_list;
	while (i)
	{
		if ((*cmp)(i->data, data_ref) == 0)
		{
			if (*begin_list == i)
				*begin_list = i->next;
			tmp = i;
			i = i->next;
			free(tmp);
		}
		else
			i = i->next;
	}
}
