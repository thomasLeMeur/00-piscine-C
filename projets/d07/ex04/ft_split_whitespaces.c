/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 11:39:50 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/10 11:39:51 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	*ft_strncpy(char *src, unsigned int n)
{
	unsigned int	i;
	char			*dest;

	i = 0;
	dest = (char*)malloc((n + 1) * sizeof(char));
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		count_words(char *str)
{
	int	i;
	int	nb_char;
	int	nb_words;

	if (str[0] == '\0')
		return (0);
	i = 0;
	nb_char = 0;
	nb_words = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i++]))
		{
			if (nb_char > 0)
				nb_words++;
			nb_char = 0;
		}
		else
			nb_char++;
	}
	return ((!is_separator(str[i - 1])) ? nb_words + 1 : nb_words);
}

void	check_str(char *str, char **tab)
{
	int		i;
	int		j;
	int		k;
	int		nb_char;

	i = 0;
	j = 0;
	k = 0;
	nb_char = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i++]))
		{
			if (nb_char > 0)
				tab[j++] = ft_strncpy(&str[k], nb_char);
			k += nb_char + 1;
			nb_char = 0;
		}
		else
			nb_char++;
	}
	if (nb_char)
		tab[j] = ft_strncpy(&str[k], nb_char);
}

char	**ft_split_whitespaces(char *str)
{
	int		nb_mots;
	char	**tab;

	nb_mots = count_words(str);
	tab = (char**)malloc((nb_mots + 1) * sizeof(*tab));
	if (tab == NULL)
		return (NULL);
	check_str(str, tab);
	tab[nb_mots] = 0;
	return (tab);
}
