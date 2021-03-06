/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 12:00:43 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/04 12:00:46 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	nb;

	nb = 0;
	while (str[nb] != '\0')
	{
		nb++;
	}
	return (nb);
}
