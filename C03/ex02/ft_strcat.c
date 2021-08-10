/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:31:31 by goliano-          #+#    #+#             */
/*   Updated: 2021/06/30 12:20:54 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	str_length(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		l1;
	int		l2;

	l1 = str_length(src);
	l2 = str_length(dest);
	i = 0;
	while (i < l1)
	{
		dest[l2] = src[i];
		l2++;
		i++;
	}
	dest[l2] = '\0';
	return (dest);
}
