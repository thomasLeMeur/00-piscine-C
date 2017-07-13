/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 11:30:16 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/13 11:30:17 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	test_lig(char **grille, int lig, int nb)
{
	int	i;

	i = 0;
	while (i < 9)
		if (grille[lig][i++] == '0' + nb)
			return (0);
	return (1);
}

int	test_col(char **grille, int col, int nb)
{
	int	i;

	i = 1;
	while (i <= 9)
		if (grille[i++][col - 1] == '0' + nb)
			return (0);
	return (1);
}

int	test_square(char **grille, int lig, int col, int nb)
{
	int	x;
	int	y;

	x = ((col - 1) / 3) * 3;
	y = ((lig - 1) / 3) * 3 + 1;
	lig = y;
	while (lig < y + 3)
	{
		col = x;
		while (col < x + 3)
			if (grille[lig][col++] == '0' + nb)
				return (0);
		lig++;
	}
	return (1);
}

int	test_case(char **grille, int lig, int col, int nb)
{
	if (!test_lig(grille, lig, nb))
		return (0);
	if (!test_col(grille, col, nb))
		return (0);
	if (!test_square(grille, lig, col, nb))
		return (0);
	return (1);
}
