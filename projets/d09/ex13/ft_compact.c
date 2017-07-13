/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 12:44:19 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/11 12:44:20 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		ft_compact(char **tab, int length)
{
	int	i;
	int	j;

	i = 0;
	new_length = 0;
	while (i < length)
	{
		if (*tab[i] == 0)
		{
			j = 1;
			while (tab[i + j] < length && tab[i + j] == 0)
				j++;
			if (i + j < length)
			{
				ft_swap(&tab[i], &tab[j]);
				new_length++;
			}
		}
		i++;
	}
	return (new_length);
}
