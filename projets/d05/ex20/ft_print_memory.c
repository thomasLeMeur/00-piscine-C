/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:39:42 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/08 19:39:44 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);

void	init_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < 10)
		base[i - 1] = '0' + i - 1;
	while (j++ < 6)
		base[i++ - 1] = 'a' + j - 1;
}

void	print_addr(int step)
{
	int		i;
	char	base[16];
	char	nb[8];

	i = 0;
	init_base(base);
	while (i < 8)
		nb[i++] = '0';
	i = 0;
	while (step != 0)
	{
		nb[8 - i++ - 1] = base[step % 16];
		step /= 16;
	}
	i = 0;
	while (i < 8)
		ft_putchar(nb[i++]);
	ft_putchar(':');
}

void	print_hexa(char *str, int size)
{
	int		i;
	char	base[16];

	i = 0;
	init_base(base);
	while (i < 16 && i < size)
	{
		ft_putchar(base[str[i] / 16]);
		ft_putchar(base[str[i] % 16]);
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
	while (i++ < 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (i % 2 == 0)
			ft_putchar(' ');
	}
}

void	print_line(char *str, int size)
{
	int	i;

	i = 0;
	while (i < 16 && i < size)
	{
		if (str[i] < ' ' || str[i] == 127)
			ft_putchar('.');
		else
			ft_putchar(str[i]);
		i++;
	}
	while (i++ < 16)
		ft_putchar(' ');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	if (size <= 0)
		return (NULL);
	i = 0;
	while (i < size / 16 + 1)
	{
		print_addr(i * 16);
		ft_putchar(' ');
		print_hexa(addr + i * 16, size - i * 16);
		ft_putchar(' ');
		print_line(addr + i * 16, size - i * 16);
		ft_putchar('\n');
		i++;
	}
	return (addr);
}
