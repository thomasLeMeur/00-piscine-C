/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 14:51:54 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/03 14:51:57 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_number(char n1, char n2, char n3, char n4)
{
	ft_putchar(n1);
	ft_putchar(n2);
	ft_putchar(' ');
	ft_putchar(n3);
	ft_putchar(n4);
}

char	g_n1;
char	g_n2;
char	g_n3;
char	g_n4;

void	ft_print_comb2(void)
{
	g_n1 = '0';
	while (g_n1 <= '9')
	{
		g_n2 = '0';
		while (g_n2++ <= '9')
		{
			if (!(g_n1 == '9' && g_n2 - 1 == '8'))
			{
				g_n3 = g_n1;
				while (g_n3++ <= '9')
				{
					g_n4 = (g_n3 - 1 == g_n1) ? g_n2 : '0';
					while (g_n4 <= '9')
					{
						print_number(g_n1, g_n2 - 1, g_n3 - 1, g_n4++);
						ft_putchar(',');
						ft_putchar(' ');
					}
				}
			}
		}
		g_n1++;
	}
	print_number('9', '8', '9', '9');
}
