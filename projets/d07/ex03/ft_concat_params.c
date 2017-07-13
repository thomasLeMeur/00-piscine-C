/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 09:57:39 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/10 09:57:41 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src, int *incr)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
		*incr += 1;
	}
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	if (argc < 2)
		return ("");
	i = 1;
	size = 0;
	while (i < argc)
		size += ft_strlen(argv[i++]);
	str = (char*)malloc((size + argc) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 1;
	while (i < size + argc - 1)
	{
		ft_strcpy(&str[i], argv[j++], &i);
		str[i++] = '\n';
	}
	str[i - 1] = '\0';
	return (str);
}
