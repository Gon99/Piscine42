/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:19:21 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/15 18:06:48 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"

int	str_length(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char	*str)
{
	int		i;
	char	*aux;

	aux = (char *)malloc(sizeof(char) * str_length(str) + 1);
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		aux[i] = str[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			x;
	t_stock_str	*tabla;

	tabla = malloc(sizeof(t_stock_str) * ac + 1);
	if (tabla == NULL)
		return (NULL);
	x = 0;
	while (x < ac)
	{
		tabla[x].size = str_length(av[x]);
		tabla[x].str = av[x];
		tabla[x].copy = ft_strcpy(av[x]);
		x++;
	}
	tabla[x].size = 0;
	tabla[x].str = 0;
	tabla[x].copy = 0;
	return (tabla);
}
