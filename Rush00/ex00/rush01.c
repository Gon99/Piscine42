/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <goliano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:32:24 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/12 12:43:12 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	are_negative(int a, int b)
{
	int		is_negative;

	is_negative = 1;
	if (a < 0 || b < 0)
		is_negative = 0;
	return (is_negative);
}

void	conditions(int f, int c, int b, int a)
{
	if ((f == 0 && c == 0) || (f == b - 1 && c == a - 1 && b > 1 && a > 1))
		ft_putchar('/');
	else if ((f == 0 && c == a - 1) || (f == b - 1 && c == 0))
		ft_putchar('\\');
	else if ((f != 0 && f != b - 1) && (c != 0 && c != a - 1))
		ft_putchar(' ');
	else
		ft_putchar('*');
}

void	rush(int a, int b)
{
	int		f;
	int		c;

	f = 0;
	c = 0;
	if (are_negative(a, b) == 1)
	{
		while (f < b)
		{
			while (c < a)
			{
				conditions(f, c, b, a);
				c++;
			}
			ft_putchar('\n');
			c = 0;
			f++;
		}
	}
	else
		write(1, "Invalid parameter.", 18);
}
