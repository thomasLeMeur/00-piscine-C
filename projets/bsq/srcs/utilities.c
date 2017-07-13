/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 12:50:43 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/21 20:52:17 by embailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/utilities.h"

long long	ft_atoi(char *str, int nb, int sig)
{
	if (!str)
		return (0);
	if ((*str == '-' || *str == '+') && !nb && !sig)
		return (ft_atoi(str + 1, nb, (*str == '-') ? -1 : 1));
	if (!*str || *str < '0' || *str > '9')
		return (nb);
	sig = (sig) ? sig : 1;
	return (ft_atoi(str + 1, nb * 10 + sig * (*str - '0'), sig));
}

int			*ft_strdup(char *src, t_rules *rules)
{
	int	*new;
	int	i;

	if (!src)
		return (NULL);
	new = (int*)malloc(rules->nb_col * sizeof(int));
	if (!new)
		return (new);
	i = 0;
	while (src[i])
	{
		if (src[i] != rules->vide && src[i] != rules->obstacle)
		{
			new[0] = -1;
			return (new);
		}
		else
			new[i] = (src[i] == rules->vide) ? 1 : 0;
		i++;
	}
	return (new);
}

char		*ft_realloc(char *src, int *size)
{
	int		i;
	char	*new;

	i = 0;
	*size *= 2;
	if (!src)
		return ((char*)malloc((*size + 1) * sizeof(char)));
	new = (char*)malloc((*size + 1) * sizeof(char));
	if (!new)
		return (new);
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	while (i < *size)
		new[i++] = '\0';
	new[i] = '\0';
	free(src);
	return (new);
}

void		free_tab(int **tab, t_rules *rules)
{
	int	i;

	if (tab)
	{
		i = 0;
		while (i < rules->nb_lig)
		{
			if (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
	}
}

void		fill_result(int **tab, t_rules *rules)
{
	int	i;
	int	j;

	i = rules->y_max - rules->max + 1;
	while (i <= rules->y_max)
	{
		j = rules->x_max - rules->max + 1;
		while (j <= rules->x_max)
			tab[i][j++] = rules->max;
		i++;
	}
}
