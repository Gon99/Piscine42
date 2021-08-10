/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 10:50:44 by goliano-          #+#    #+#             */
/*   Updated: 2021/06/29 18:17:38 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_resp(char f, char s, char t)
{
	write(1, &f, 1);
	write(1, &s, 1);
	write(1, &t, 1);
	if (f != '7' || s != '8' || t != '9')
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb(void)
{
	char	f;
	char	s;
	char	t;

	f = '0';
	s = '1';
	t = '2';
	while (t <= '9')
	{
		write_resp(f, s, t);
		if (t == '9')
		{
			s++;
			t = s + 1;
		}
		else
			t++;
		if (s == '9')
		{
			f++;
			s = f + 1;
			t = s + 1;
		}
	}
}
