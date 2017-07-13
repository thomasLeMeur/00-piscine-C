/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 20:10:48 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/12 20:11:02 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

char	**fill_case(char **grille, int lig, int col, char **solution)
{
	int	i;
	int	is_solution;

	i = 1;
	is_solution = (solution) ? 1 : 0;
	while (i <= 9)
	{
		if (test_case(grille, lig, col, i))
		{
			grille[lig][col - 1] = '0' + i;
			solution = resolve(grille, lig, col + 1, solution);
			if (solution)
				is_solution++;
			if (!solution && is_solution)
				return (solution);
		}
		i++;
	}
	grille[lig][col - 1] = '.';
	return (solution);
}

char	**resolve(char **grille, int lig, int col, char **solution)
{
	if (lig == 10)
	{
		if (!solution)
			return (alloc_grille(grille));
		else
			return (free_grille(solution));
	}
	if (col == 10)
		return (resolve(grille, lig + 1, 1, solution));
	if (grille[lig][col - 1] != '.')
		return (resolve(grille, lig, col + 1, solution));
	return (fill_case(grille, lig, col, solution));
}
