/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 14:33:53 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/11 14:33:55 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src, int *count)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	*count += i;
}

char	*ft_join(char **tab, char *sep)
{
	int		size_sep;
	int		size;
	int		i;
	int		j;
	char	*tmp;

	size_sep = ft_strlen(sep);
	size = 0;
	i = 0;
	while (tab[i] != NULL)
		size += ft_strlen(tab[i++]) + size_sep;
	size -= size_sep;
	tmp = (char*)malloc((size + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		ft_strcpy(&tmp[j], tab[i], &j);
		if (tab[i + 1] != NULL)
			ft_strcpy(&tmp[j], sep, &j);
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}
