/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 10:01:00 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/16 10:01:01 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*i;
	t_list	*new;

	i = *begin_list;
	if (i)
	{
		while (i->next)
			i = i->next;
		new = ft_create_elem(data);
		if (new)
			i->next = new;
	}
	else
		*begin_list = ft_create_elem(data);
}
