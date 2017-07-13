/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 17:01:21 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/15 17:01:22 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operations.h"
#include "ft_strings.h"
#include "ft_opp.h"

int		ft_get_op(char *str)
{
	int	i;

	i = 0;
	while (*g_opptab[i].op && ft_strcmp(str, g_opptab[i].op) != 0)
		i++;
	return (i);
}

void	ft_do(int n1, int n2, void (*func)(int, int))
{
	func(n1, n2);
}

void	ft_compute(int n1, int n2, int op)
{
	ft_do(n1, n2, g_opptab[op].func);
}

void	ft_usage(int a, int b)
{
	a = 0;
	write(1, "error : only [ ", 15);
	while (g_opptab[a++].op)
	{
		b = 0;
		while (g_opptab[a - 1].op[b])
			ft_putchar(g_opptab[a - 1].op[b++]);
		ft_putchar(' ');
	}
	ft_putstr("] are accepted.");
}
