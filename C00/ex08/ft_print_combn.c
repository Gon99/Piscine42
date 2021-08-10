/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:47:02 by goliano-          #+#    #+#             */
/*   Updated: 2021/06/29 12:33:39 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	case_1(void)
{
	int		i;

	i = '0';
	while (i < '9')
	{
		write(1, &i, 1);
		write(1, ",", 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "9", 1);
}

void	print_commas(void)
{
	write(1, ",", 1);
	write(1, " ", 1);
}

void	print_sol(int *nums, int n)
{
	int		x;
	int		i;
	char	c;

	i = 1;
	x = 1;
	while (i < n)
	{
		if (nums[i - 1] >= nums[i])
			x = 0;
		i++;
	}
	if (x != 0)
	{
		i = 0;
		while (i < n)
		{
			c = nums[i] + '0';
			write(1, &c, 1);
			i++;
		}
		if (nums[0] < (10 - n))
			print_commas();
	}
}

void	initialize_arr(int *nums, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		nums[i] = 0;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int		nums[9];
	int		i;

	i = 0;
	if (n >= 10 || n <= 0)
		return ;
	if (n == 1)
		case_1();
	initialize_arr(nums, n);
	while (n > 1 && nums[0] <= (10 - n))
	{
		print_sol(nums, n);
		nums[n - 1]++;
		i = n;
		while (i != 0 && n > 1)
		{
			i--;
			if (nums[i] > 9)
			{
				nums[i] = 0;
				nums[i - 1]++;
			}
		}
	}
}
