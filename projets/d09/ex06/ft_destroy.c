/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 23:05:02 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/10 23:05:04 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ultimator.h>
#include <stdlib.h>

void	ft_destroy(char ***factory)
{
	int	i;
	int	j;

	i = 0;
	while (factory[i] != NULL)
	{
		j = 0;
		while (factory[i][j] != NULL)
		{
			free(factory[i][j]);
			factory[i][j] = NULL;
			j++;
		}
		free(*factory[i]);
		factory[i] = NULL;
		i++;
	}
}
