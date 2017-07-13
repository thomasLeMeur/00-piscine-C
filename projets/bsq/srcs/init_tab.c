/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embailla <embailla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 14:45:24 by embailla          #+#    #+#             */
/*   Updated: 2015/09/21 20:54:31 by embailla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/init_tab.h"
#include "../includes/ft_out.h"

char	*read_instructions(int fd)
{
	int		index;
	char	*buf;
	char	c;
	int		size;

	size = 1;
	index = 0;
	buf = ft_realloc(NULL, &size);
	while (read(fd, &c, 1))
	{
		if (index >= size)
			buf = ft_realloc(buf, &size);
		if (c >= '0' && c <= '9')
			buf[index++] = c;
		else if (c != '\n' && index != 0)
			buf[index++] = c;
		else if (c != '\n' && index == 0)
		{
			buf[0] = 0;
			return (buf);
		}
		else
		{
			buf[index] = '\0';
			return (buf);
		}
	}
	return (buf);
}

int		init_rules(char *buf, t_rules *rules)
{
	long long	nb1;
	int			nb2;
	int			i;

	nb1 = ft_atoi(buf, 0, 0);
	nb2 = nb1;
	if (nb1 != nb2)
		return (0);
	rules->max = 0;
	rules->nb_lig = nb2;
	i = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	if (buf[i] == '\0')
		return (0);
	rules->vide = buf[i++];
	if (buf[i] == '\0')
		return (0);
	rules->obstacle = buf[i++];
	if (buf[i] == '\0')
		return (0);
	rules->plein = buf[i++];
	return ((buf[i] == '\0') ? 1 : 0);
}

char	*read_first_line(int fd, t_rules *rules)
{
	int		index;
	int		size;
	char	*buffer;
	char	c;

	index = 0;
	size = 1;
	rules->max = 0;
	buffer = ft_realloc(NULL, &size);
	while (read(fd, &c, 1))
	{
		if (index >= size)
			buffer = ft_realloc(buffer, &size);
		if ((c == rules->vide || c == rules->obstacle) && c != '\n')
			buffer[index++] = c;
		else if (c != '\n')
		{
			buffer[0] = 0;
			return (buffer);
		}
		else
		{
			rules->nb_col = index;
			buffer[index] = '\0';
			return (buffer);
		}
	}
	return (buffer);
}
int		check_line_and_copy(int fd, int *lig, t_rules *rules)
{
	int		i;
	char	c;

	i = 0;
	while (read(fd, &c, 1))
	{
		if (i >= rules->nb_col || c == '\n')
			return ((i == rules->nb_col) ? 1 : 0);
		if (c != rules->vide && c != rules->obstacle)
			return (0);
		lig[i++] = (c == rules->vide) ? 1 : 0;
	}
	return (1);
}
