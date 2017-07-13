/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 13:02:20 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/11 13:02:21 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_perso.h"
#include <stdlib.h>

int		g_neg_tmp;

int		nb_persos(char *str)
{
	int	i;
	int	nb;

	if (!str[0])
		return (0);
	i = 0;
	nb = 0;
	while (str[i])
		if (str[i++] == ';')
			nb++;
	return (nb + 1);
}

char	*ft_strdup(char *src, int size)
{
	char	*ptr;
	int		i;

	ptr = (char*)malloc((size + 1) * sizeof(*ptr));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i++ < size)
		ptr[i - 1] = src[i - 1];
	ptr[i - 1] = '\0';
	return (ptr);
}

int		natoi(char *str, int size)
{
	int	i;
	int	pow;
	int	result;

	i = 1;
	pow = 1;
	result = 0;
	g_neg_tmp = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	while (g_neg_tmp < size && (str[g_neg_tmp] >= '0' && str[g_neg_tmp] <= '9'))
		g_neg_tmp++;
	g_neg_tmp -= (str[0] == '-' || str[0] == '+') ? 1 : 0;
	while (i++ < g_neg_tmp)
		pow *= 10;
	g_neg_tmp = (size > 1 && str[0] == '-') ? -1 : 1;
	i = (g_neg_tmp == -1 || str[0] == '+') ? 1 : 0;
	while (i <= size)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (result);
		result += (str[i++] - '0') * pow * g_neg_tmp;
		pow /= 10;
	}
	return (result);
}

t_perso	**ft_decrypt(char *str)
{
	int		i;
	int		j;
	int		k;
	int		nb_mots;
	t_perso	**result;

	nb_mots = nb_persos(str);
	result = (t_perso**)malloc(nb_mots * sizeof(t_perso*));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_mots)
	{
		k = j;
		while (str[j] != '|')
			j++;
		result[i] = (t_perso*)malloc(1 * sizeof(t_perso));
		result[i]->age = natoi(&str[i], j - k);
		k = ++j;
		while (str[j] && str[j] != ';')
			j++;
		result[i++]->name = strndup(&str[k], j++ - k);
	}
	return (result);
}
