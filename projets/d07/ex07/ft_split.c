/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 18:13:39 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/10 18:13:41 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char *c, char *charset, int *count, int is_changed)
{
	int	i;
	int	size_charset;

	i = 0;
	while (c[i] != '\0' && charset[i] != '\0' && c[i] == charset[i])
		i++;
	size_charset = 0;
	while (charset[size_charset] != '\0')
		size_charset++;
	if (i == size_charset)
	{
		if (is_changed == 1)
			*count += i - 1;
		return (1);
	}
	if (is_changed == 1)
		*count += 1;
	return (0);
}

void	ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int		count_words(char *str, char *charset)
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
		if (is_separator(&str[i], charset, &i, 1))
		{
			if (nb_char > 0)
				nb_words++;
			nb_char = 0;
		}
		else
			nb_char++;
	}
	if (!is_separator(&str[i - 1], charset, &i, 0))
		return (nb_words + 1);
	else
		return (nb_words);
}

void	check_str(char *str, char **tab, char *charset)
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
		if (is_separator(&str[i], charset, &i, 0))
		{
			if (nb_char > 0)
			{
				tab[j] = (char*)malloc((nb_char + 1) * sizeof(**tab));
				ft_strncpy(tab[j++], &str[k + 1], nb_char);
			}
			k += nb_char + is_separator(&str[i], charset, &i, 0);
			nb_char = 0;
		}
		else
			nb_char++;
		is_separator(&str[i], charset, &i, 1);
	}
}

char	**ft_split(char *str, char *charset)
{
	int		nb_mots;
	char	**tab;

	nb_mots = count_words(str, charset);
	tab = (char**)malloc((nb_mots + 1) * sizeof(*tab));
	if (tab == NULL)
		return (NULL);
	check_str(str, tab, charset);
	tab[nb_mots] = 0;
	return (tab);
}
