/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:52:54 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/13 17:47:37 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		l;
	int		*aux_range;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	i = 0;
	l = max - min;
	aux_range = (int *)malloc(l * sizeof(int));
	if (range == NULL)
		return (-1);
	while (min < max)
	{
		aux_range[i] = min;
		min++;
		i++;
	}
	*range = aux_range;
	return (l);
}
