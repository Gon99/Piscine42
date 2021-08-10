/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:11:01 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/07 11:38:58 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		r;

	r = 0;
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
		{
			r = 1;
			break ;
		}
		if (s2[i] > s1[i])
		{
			r = -1;
			break ;
		}
		i++;
	}
	return (r);
}

void	print_sol(char **sol, int size)
{
	int		i;
	int		j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (sol[i][j] != '\0')
		{
			write(1, &sol[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*aux;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			aux = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = aux;
			i = 1;
		}
		else
			i++;
	}
	print_sol(argv, argc);
	return (0);
}
