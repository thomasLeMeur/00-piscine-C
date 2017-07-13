/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 11:29:44 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/08 11:29:49 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_maj(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int		is_min(char c)
{
	return (c >= 'a' && c <= 'z');
}

int		is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int		is_alpha_num(char c)
{
	return (is_maj(c) || is_min(c) || is_digit(c));
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_maj(str[i]) || is_min(str[i]))
		{
			if (i == 0 || !is_alpha_num(str[i - 1]))
			{
				if (is_min(str[i]))
					str[i] = str[i] - 'a' + 'A';
			}
			else
			{
				if (is_maj(str[i]))
					str[i] = str[i] - 'A' + 'a';
			}
		}
		i++;
	}
	return (str);
}
