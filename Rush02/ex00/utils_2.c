/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:00:11 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/07/11 23:01:30 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	handle_dic(char *dict)
{
	int		i;
	i = 0;
	while (dict[i] != '\0')
	{
		if (dict[i] == ':' && dict[i + 1] == '\n')
			return (0);
		if (dict[i] == '\n' && dict[i + 1] == '\n')
			return (0);
		if (dict[i] == '\n' && dict[i + 1] == ':')
			return (0);
		i++;
	}
	return (1);
}
