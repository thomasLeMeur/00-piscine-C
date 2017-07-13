/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 10:34:26 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/16 10:34:27 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		nb;
	t_list	*i;

	nb = 0;
	i = begin_list;
	if (i)
	{
		nb++;
		while (i->next)
		{
			i = i->next;
			nb++;
		}
	}
	return (nb);
}
