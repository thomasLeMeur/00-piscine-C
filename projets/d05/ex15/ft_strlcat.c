/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <tle-meur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 12:56:29 by tle-meur          #+#    #+#             */
/*   Updated: 2015/09/08 12:56:31 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				j;
	unsigned int	z;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (i < size && src[j] != '\0')
		dest[i++] = src[j++];
	if (i == size)
		dest[i - 1] = '\0';
	z = i;
	while (z < size)
		dest[z++] = '\0';
	while (src[j++] != '\0')
		i++;
	return (i);
}
