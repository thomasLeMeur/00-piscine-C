/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 23:24:43 by jgan              #+#    #+#             */
/*   Updated: 2015/09/06 23:30:27 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_first(int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar('A');
		else if (i == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		i++;
	}
	ft_putchar('\n');
}

void	ft_mid(int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j + 1 < y - 1)
	{
		i = 0;
		while (i < x)
		{
			if (i == 0 || i == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

void	ft_last(int x, int y)
{
	int i;

	if (y > 1)
	{
		i = 0;
		while (i < x)
		{
			if (i == 0)
				ft_putchar('A');
			else if (i == x - 1)
				ft_putchar('C');
			else
				ft_putchar('B');
			i++;
		}
		ft_putchar('\n');
	}
}

void	colle(int x, int y)
{
	ft_first(x);
	ft_mid(x, y);
	ft_last(x, y);
}
