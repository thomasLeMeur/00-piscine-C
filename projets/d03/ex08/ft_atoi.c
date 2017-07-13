/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 12:39:09 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/04 12:39:12 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	g_neg_tmp;

int	ft_atoi(char *str)
{
	int	i;
	int	pow;
	int	size;
	int	result;

	i = 1;
	pow = 1;
	result = 0;
	size = ft_strlen(str);
	g_neg_tmp = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	while (g_neg_tmp < size && (str[g_neg_tmp] >= '0' && str[g_neg_tmp] <= '9'))
		g_neg_tmp++;
	g_neg_tmp -= (str[0] == '-' || str[0] == '+') ? 1 : 0;
	while (i++ < g_neg_tmp)
		pow *= 10;
	g_neg_tmp = (size > 1 && str[0] == '-') ? -1 : 1;
	i = (g_neg_tmp == -1 || str[0] == '+') ? 1 : 0;
	while (i <= size)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (result);
		result += (str[i++] - '0') * pow * g_neg_tmp;
		pow /= 10;
	}
	return (result);
}
