/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 10:19:08 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/20 10:19:10 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "ft_checks.h"

void	free_liste(t_col **liste)
{
	t_col	*i;
	t_col	*tmp;

	i = *liste;
	while (i)
	{
		tmp = i;
		i = i->next;
		tmp->next = NULL;
		free(tmp);
	}
	liste = NULL;
}

void	init_elem(t_col **elem, char *name, char *syms)
{
	(*elem)->name = name;
	(*elem)->syms = syms;
	(*elem)->occu[0] = 0;
	(*elem)->occu[1] = 0;
	(*elem)->occu[2] = 0;
	(*elem)->occu[3] = 0;
	(*elem)->occu[4] = 0;
	(*elem)->occu[5] = 0;
	(*elem)->next = NULL;
}

void	init_liste(t_col **liste)
{
	t_col	*c00;
	t_col	*c01;
	t_col	*c02;
	t_col	*c03;
	t_col	*c04;

	c00 = (t_col*)malloc(sizeof(t_col));
	c01 = (t_col*)malloc(sizeof(t_col));
	c02 = (t_col*)malloc(sizeof(t_col));
	c03 = (t_col*)malloc(sizeof(t_col));
	c04 = (t_col*)malloc(sizeof(t_col));
	init_elem(&c00, "colle-00", "oooo-|");
	init_elem(&c01, "colle-01", "/\\\\/**");
	init_elem(&c02, "colle-02", "AACCBB");
	init_elem(&c03, "colle-03", "ACACBB");
	init_elem(&c04, "colle-04", "ACCABB");
	c00->next = c01;
	c01->next = c02;
	c02->next = c03;
	c03->next = c04;
	*liste = c00;
}

void	verification(t_col **liste, t_case *caze, char *c)
{
	t_col	*i;
	t_col	*tmp;

	i = *liste;
	if (!i)
		return ;
	while (i && i->next)
	{
		tmp = i->next;
		if (!check(tmp, caze, c))
		{
			i->next = tmp->next;
			free(tmp);
		}
		else
			i = tmp;
	}
	i = *liste;
	if (i)
		if (!check(i, caze, c))
		{
			*liste = i->next;
			free(i);
		}
}
