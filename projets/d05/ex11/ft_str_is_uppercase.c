/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 12:17:41 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/08 12:17:43 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_maj(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (!is_maj(str[i++]))
			return (0);
	return (1);
}
