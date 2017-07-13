/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 19:03:53 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/08 19:03:55 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_hexa(char c)
{
	int		i;
	int		j;
	char	base[16];
	char	nb[2];

	i = 0;
	while (i++ < 10)
		base[i - 1] = '0' + i - 1;
	j = 0;
	while (j++ < 6)
		base[i++ - 1] = 'a' + j - 1;
	nb[0] = '0';
	nb[1] = '0';
	i = (c < 16) ? 1 : 0;
	while (c != 0)
	{
		nb[i++] = base[c % 16];
		c /= 16;
	}
	ft_putchar(nb[0]);
	ft_putchar(nb[1]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] <= '~')
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			print_hexa(str[i]);
		}
		i++;
	}
}
