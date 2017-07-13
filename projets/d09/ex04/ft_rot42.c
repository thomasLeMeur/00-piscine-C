/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 21:54:45 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/10 21:54:47 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_min(char c)
{
	return (c >= 'a' && c <= 'z');
}

int		is_maj(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int		is_alpha(char c)
{
	return (is_min(c) || is_maj(c));
}

void	rotate(char *c)
{
	if (is_min(*c))
		*c = ((*c - 'a' + 42) % 26) + 'a';
	else
		*c = ((*c - 'A' + 42) % 26) + 'A';
}

char	*ft_rot42(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_alpha(str[i]))
			rotate(&str[i]);
		i++;
	}
	return (str);
}
