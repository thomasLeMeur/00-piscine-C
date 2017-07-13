/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 11:38:08 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/13 11:38:09 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		write(1, &str[i++], 1);
		write(1, " ", 1);
	}
	write(1, &str[i], 1);
	write(1, "\n", 1);
}

int		check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '.' || (str[i] >= '1' && str[i] <= '9')))
			return (0);
		i++;
	}
	return ((i != 9) ? 0 : 1);
}

int		put_error(void)
{
	write(1, "Erreur\n", 7);
	return (0);
}

void	ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}
