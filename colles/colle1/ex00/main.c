/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 20:02:53 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/12 20:02:55 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "strings.h"
#include "memory.h"
#include "sudoku.h"

int		main(int argc, char **argv)
{
	int		i;
	char	**grille;

	if (argc != 10)
		return (put_error());
	i = 1;
	while (i < argc)
		if (!check_arg(argv[i++]))
			return (put_error());
	grille = resolve(argv, 1, 1, NULL);
	if (grille == NULL)
		return (put_error());
	i = 0;
	while (i < 9)
		ft_putstr(grille[i++]);
	free_grille(grille);
	return (0);
}
