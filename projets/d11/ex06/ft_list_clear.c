/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 11:00:46 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/16 11:00:47 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*i;

	i = *begin_list;
	if (i)
	{
		while (i->next)
		{
			tmp = i;
			i = i->next;
			free(tmp);
			tmp = NULL;
		}
		free(i);
		i = NULL;
		*begin_list = NULL;
	}
}
