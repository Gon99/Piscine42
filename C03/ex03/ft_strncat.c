/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:22:27 by goliano-          #+#    #+#             */
/*   Updated: 2021/06/30 12:33:26 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	str_length(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int					l1;
	unsigned int		i;

	l1 = str_length(dest);
	i = 0;
	while (src[i] != '\0')
	{
		if (i == nb)
			break ;
		dest[l1] = src[i];
		l1++;
		i++;
	}
	dest[l1] = '\0';
	return (dest);
}
