/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 19:17:04 by vperez            #+#    #+#             */
/*   Updated: 2015/09/05 21:56:49 by vperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	colle(int x, int y)
{
	int nbx;
	int nby;

	nby = 0;
	while (nby < y)
	{
		nbx = 0;
		while (nbx < x)
		{
			if (nby == 0 && (nbx == 0 || nbx == x - 1))
				ft_putchar('o');
			else if (nby == y - 1 && (nbx == 0 || nbx == x - 1))
				ft_putchar('o');
			else if (nby == 0 || nby == y - 1)
				ft_putchar('-');
			else if (nbx == 0 || nbx == x - 1)
				ft_putchar('|');
			else
				ft_putchar(' ');
			nbx++;
		}
		ft_putchar('\n');
		nby++;
	}
}
