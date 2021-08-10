/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:02:24 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/06 12:12:13 by goliano-         ###   ########.fr       */
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

char	*ft_strstr(char *str, char *to_find)
{
	int		j;
	int		is_ins;
	char	*aux_str;

	is_ins = 0;
	j = 0;
	aux_str = str;
	while (*str != '\0' && is_ins == 0)
	{
		if (*str == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
				is_ins = 1;
		}
		else
			j = 0;
		str++;
	}
	if (str_length(to_find) == 0)
		return (aux_str);
	if (is_ins == 0)
		return (NULL);
	return (str - j);
}
