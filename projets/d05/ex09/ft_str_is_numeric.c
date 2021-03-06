/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 12:10:58 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/08 12:11:00 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (!is_digit(str[i++]))
			return (0);
	return (1);
}
