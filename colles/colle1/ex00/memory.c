/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 11:34:13 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/13 11:34:14 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

char	**alloc_grille(char **model)
{
	int		i;
	char	**grille;

	i = 0;
	grille = (char**)malloc(9 * sizeof(char*));
	while (i < 9)
	{
		grille[i] = (char*)malloc(10 * sizeof(char));
		ft_strcpy(grille[i], model[i + 1]);
		i++;
	}
	return (grille);
}

char	**free_grille(char **grille)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		free(grille[i]);
		grille[i++] = NULL;
	}
	free(grille);
	grille = NULL;
	return (NULL);
}
