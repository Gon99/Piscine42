/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:21:07 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/08 20:11:44 by goliano-         ###   ########.fr       */
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

int	strs_length(char **strs, int size)
{
	int		i;
	int		x;
	int		l;

	x = 0;
	l = 0;
	while (x < size)
	{
		i = 0;
		while (strs[x][i] != '\0')
		{
			l++;
			i++;
		}
		x++;
	}
	return (l);
}

int	add_separator(char *str, char *sep, int index)
{
	int		i;

	i = 0;
	while (sep[i] != '\0')
	{
		str[index] = sep[i];
		index++;
		i++;
	}
	return (index);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*str;
	int		i;
	int		x;
	int		j;

	x = 0;
	j = 0;
	len = str_length(sep);
	len += strs_length(strs, size);
	str = (char *)malloc(sizeof(char) * len);
	while (x < size)
	{
		i = 0;
		while (strs[x][i] != '\0')
		{
			str[j] = strs[x][i];
			j++;
			i++;
		}
		j = add_separator(str, sep, j);
		x++;
	}
	return (str);
}
