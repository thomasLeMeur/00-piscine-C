/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 12:09:59 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/21 20:42:18 by embailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/compute.h"
#include "../includes/init_tab.h"
#include "../includes/ft_out.h"

void	change_max(t_rules *rules, int nb, int x, int y)
{
	rules->max = nb;
	rules->x_max = x;
	rules->y_max = y;
}

int		compute(int **tab, t_rules *rules)
{
	int	i;
	int	j;

	i = 1;
	if (!tab || tab[0][0] == -1)
		return (0);
	while (i < rules->nb_lig)
	{
		j = 1;
		while (j < rules->nb_col)
		{
			if (tab[i][j] > 0)
			{
				tab[i][j] = MIN(tab[i][j - 1], tab[i - 1][j]);
				tab[i][j] = MIN(tab[i][j], tab[i - 1][j - 1]) + 1;
				if (tab[i][j] > rules->max)
					change_max(rules, tab[i][j], j, i);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		**init_tab(char *file, t_rules *rules)
{
	int		i;
	int		fd;
	char	c;
	char	*buf;
	char	*buffer;
	int		**tab;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	buf = read_instructions(fd);
	if (buf[0] == 0)
	{
		if (buf)
			free(buf);
		return ((close(fd)) ? NULL : NULL);
	}
	if (!init_rules(buf, rules))
	{
		if (buf)
			free(buf);
		return ((close(fd)) ? NULL : NULL);
	}
	if (buf)
		free(buf);
	buffer = read_first_line(fd, rules);
	if (buffer[0] == 0)
		return ((close(fd)) ? NULL : NULL);
	tab = malloc(rules->nb_lig * sizeof(int*));
	tab[0] = ft_strdup(buffer, rules);
	if (buffer)
		free(buffer);
	if (tab[0][0] == -1)
		return ((close(fd)) ? NULL : NULL);
	i = 0;
	while (++i < rules->nb_lig)
	{
		tab[i] = malloc(rules->nb_col * sizeof(int));
		if (!check_line_and_copy(fd, tab[i], rules))
		{
			tab[0][0] = -1;
			return ((close(fd)) ? NULL : NULL);
		}
	}
	if (read(fd, &c, 1))
		tab[0][0] = -1;
	close(fd);
	return (tab);
}
