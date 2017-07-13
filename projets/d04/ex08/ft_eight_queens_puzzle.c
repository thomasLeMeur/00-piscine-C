/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 10:25:13 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/08 10:25:16 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_ok(int id, int col, int *places)
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

int	compute(int id_queen, int *places)
{
	int	i;
	int	nb;

	if (id_queen > 8)
		return (1);
	nb = 0;
	i = 1;
	while (i <= 8)
	{
		if (is_ok(id_queen, i, places))
		{
			places[id_queen - 1] = i;
			nb += compute(id_queen + 1, places);
			places[id_queen - 1] = 0;
		}
		i++;
	}
	return (nb);
}

int	ft_eight_queens_puzzle(void)
{
	int	col;
	int	places[8];

	col = 0;
	while (col < 8)
		places[col++] = 0;
	return (compute(1, places));
}
