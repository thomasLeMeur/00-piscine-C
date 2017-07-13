/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 12:24:14 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/21 20:29:06 by embailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/ft_out.h"
#include "../includes/utilities.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_tab(int **tab, t_rules *rules)
{
	int	i;
	int	j;

	i = 0;
	fill_result(tab, rules);
//	printf("%d, et %d\n", rules->nb_lig, rules->nb_col);
	while (i < rules->nb_lig)
	{
		j = 0;
		while (j < rules->nb_col)
		{
			if (tab[i][j] == 0)
			{
//				printf("O");
				ft_putchar(rules->obstacle);
			}
			else if (tab[i][j] < rules->max)
			{
//				printf("X\n");
				ft_putchar(rules->vide);
			}
			else if (tab[i][j] == rules->max)
			{
				if (i <= rules->y_max && j <= rules->x_max)
					ft_putchar(rules->plein);
				else
					ft_putchar(rules->vide);
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
