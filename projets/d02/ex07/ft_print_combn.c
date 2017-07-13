/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 19:39:11 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/03 19:39:13 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	g_i;
char	g_buffer[10];

void	really_print(int size)
{
	g_i = 0;
	while (g_i < size)
	{
		ft_putchar(g_buffer[g_i++]);
	}
}

void	print_recursive(int depth, int depth_max, char n)
{
	if (g_buffer[0] == '0' + (10 - depth_max))
	{
		really_print(depth_max);
		return ;
	}
	if (depth == depth_max)
	{
		really_print(depth_max);
		ft_putchar(',');
		ft_putchar(' ');
		return ;
	}
	while (n - '0' <= 10 - depth_max + depth)
	{
		g_buffer[depth] = n;
		print_recursive(depth + 1, depth_max, ++n);
	}
}

void	ft_print_combn(int n)
{
	g_i = 0;
	while (g_i < n)
	{
		g_buffer[g_i++] = '\0';
	}
	print_recursive(0, n, '0');
}
