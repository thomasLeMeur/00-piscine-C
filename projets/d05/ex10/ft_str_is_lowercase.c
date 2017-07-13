/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 12:15:51 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/08 12:15:53 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_min(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (!is_min(str[i++]))
			return (0);
	return (1);
}
