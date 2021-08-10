/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:14:58 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/13 09:50:33 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int		*range;
	int		l;
	int		i;

	if (min >= max)
		return (NULL);
	i = 0;
	l = max - min;
	range = (int *)malloc(l * sizeof(int));
	while (min < max)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}
