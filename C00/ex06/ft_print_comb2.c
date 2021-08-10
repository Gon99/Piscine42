/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:48:54 by goliano-          #+#    #+#             */
/*   Updated: 2021/06/29 18:20:01 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_sol(char *arr)
{
	write(1, &arr[0], 1);
	write(1, &arr[1], 1);
	write(1, " ", 1);
	write(1, &arr[2], 1);
	write(1, &arr[3], 1);
	if (arr[0] != '9' || arr[1] != '8' || arr[2] != '9' || arr[3] != '9')
		write(1, ",", 1);
	if (arr[0] != '9' || arr[2] != '9' || arr[3] != '9' || arr[1] != '8')
		write(1, " ", 1);
}

void	ft_print_comb2(void)
{
	char	arr[4];
	int		x;
	int		y;

	x = 00;
	y = 00;
	while (x < 99)
	{
		while (y < 99)
		{
			y++;
			arr[3] = y % 10 + '0';
			arr[2] = y / 10 + '0';
			arr[1] = x % 10 + '0';
			arr[0] = x / 10 + '0';
			print_sol(arr);
		}
		x++;
		y = x;
	}
}
