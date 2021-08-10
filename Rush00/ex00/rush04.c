/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:34:48 by goliano-          #+#    #+#             */
/*   Updated: 2021/06/27 18:05:15 by goliano-         ###   ########.fr       */
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
	if ((f == 0 && c == 0) || (f == b - 1 && c == a - 1 && a > 1 && b > 1))
		ft_putchar('A');
	else if ((f == 0 && c == a - 1) || (f == b - 1 && c == 0))
		ft_putchar('C');
	else if ((f != 0 && f != b - 1) && (c != 0 && c != a - 1))
		ft_putchar(' ');
	else
		ft_putchar('B');
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
