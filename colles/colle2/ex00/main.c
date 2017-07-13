/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 11:26:39 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/20 21:53:29 by ntizio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>

#include "utilities.h"
#include "ft_print.h"

void	do_first_line(t_col **liste, t_case *caze)
{
	char	c[2];

	c[1] = 0;
	while (read(0, &c[0], 1))
	{
		if (c[0] == '\0' || (c[0] == '\n' && !caze->col))
			return ;
		if (c[0] == '\n')
		{
			caze->larg = caze->col;
			caze->lig++;
			caze->col = 0;
			c[1] = c[0];
			return ;
		}
		verification(liste, caze, c);
		if (!*liste)
			return ((void)(caze->lig = -1));
		caze->col++;
		c[1] = c[0];
	}
}

void	do_other_lines(t_col **liste, t_case *caze)
{
	char	c[2];

	c[1] = '\n';
	while (read(0, &c[0], 1))
	{
		if (c[0] == '\0' || (c[0] == '\n' && !caze->col))
			return ;
		if (c[0] == '\n' || c[0] == '\0')
		{
			if (caze->col != caze->larg && caze->lig == 1)
				return ((void)(caze->lig = -1));
			if (caze->col != caze->larg + 1 && caze->lig > 1)
				return ((void)(caze->lig = -1));
			caze->col = 0;
			caze->lig++;
		}
		verification(liste, caze, c);
		if (!*liste)
			return ((void)(caze->lig = 0));
		caze->col++;
		c[1] = c[0];
	}
}

void	clean_buf(int nb_lig)
{
	char	c;

	if (nb_lig == -1)
		while (read(0, &c, 1))
			if (c == '\n')
				return ;
}

int		main(void)
{
	int		larg;
	int		nb_lig;
	t_col	*liste;
	t_case	caze;

	liste = NULL;
	init_liste(&liste);
	larg = 0;
	nb_lig = 0;
	caze.lig = 0;
	caze.col = 0;
	caze.larg = 0;
	do_first_line(&liste, &caze);
	if ((!caze.larg || !caze.lig) && liste)
		caze.lig = 0;
	else if (caze.lig == -1)
		;
	else
		do_other_lines(&liste, &caze);
	ft_print_result(liste, caze);
	ft_putchar('\n');
	free_liste(&liste);
	clean_buf(caze.lig);
	return (0);
}
