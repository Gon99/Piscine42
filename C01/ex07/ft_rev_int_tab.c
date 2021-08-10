/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:16:46 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/14 17:42:46 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		aux;

	i = 0;
	aux = 0;
	if (tab == NULL)
		return ;
	while (i < size / 2)
	{
		aux = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = aux;
		i++;
	}
}

int	main(void)
{
	int	nums[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	int	*pnumbs = nums;
	int i = 0;
	char	a;
	ft_rev_int_tab(pnumbs, 8);
	while (i < 8)
	{
		a = nums[i] + '0';
		write(1, &a, 1);
		i++;
	}
	return (0);
}
