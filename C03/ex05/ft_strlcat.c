/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:04:35 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/07 13:26:35 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_length(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;

	len1 = str_length(dest);
	len2 = str_length(src);
	i = 0;
	if (size <= len1)
		len2 += size;
	else
		len2 += len1;
	while (src[i] != '\0' && len1 + 1 < size)
	{
		dest[len1] = src[i];
		len1++;
		i++;
	}
	dest[len1] = '\0';
	return (len2);
}
