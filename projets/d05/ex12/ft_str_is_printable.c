/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 12:19:06 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/08 12:19:08 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_print(char c)
{
	return (c >= ' ' && c <= '~');
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (!is_print(str[i++]))
			return (0);
	return (1);
}
