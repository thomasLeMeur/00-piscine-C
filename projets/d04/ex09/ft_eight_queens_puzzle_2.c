/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 10:26:33 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/08 10:26:35 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int *places)
{
	int	i;

	i = 0;
	while (i < 8)
		ft_putchar('0' + places[i++]);
	ft_putchar('\n');
}

int		is_ok(int id, int col, int *places)
{
	int	i;

	i = 1;
	while (i <= id)
	{
		if (col == places[i - 1])
			return (0);
		if (col == places[i - 1] + (id - i))
			return (0);
		if (col == places[i - 1] - (id - i))
			return (0);
		i++;
	}
	return (1);
}

void	compute(int id_queen, int *places)
{
	int	i;

	if (id_queen > 8)
	{
		print_line(places);
		return ;
	}
	i = 1;
	while (i <= 8)
	{
		if (is_ok(id_queen, i, places))
		{
			places[id_queen - 1] = i;
			compute(id_queen + 1, places);
			places[id_queen - 1] = 0;
		}
		i++;
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	int	col;
	int	places[8];

	col = 0;
	while (col < 8)
		places[col++] = 0;
	compute(1, places);
}
