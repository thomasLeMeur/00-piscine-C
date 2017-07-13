/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 13:51:28 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/03 13:51:31 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

char	g_n1;
char	g_n2;
char	g_n3;

void	ft_print_comb(void)
{
	g_n1 = '0';
	while (g_n1 <= '6')
	{
		g_n2 = g_n1 + 1;
		while (g_n2 <= '8')
		{
			g_n3 = g_n2 + 1;
			while (g_n3 <= '9')
			{
				ft_putchar(g_n1);
				ft_putchar(g_n2);
				ft_putchar(g_n3);
				ft_putchar(',');
				ft_putchar(' ');
				g_n3++;
			}
			g_n2++;
		}
		g_n1++;
	}
	ft_putchar('7');
	ft_putchar('8');
	ft_putchar('9');
}
