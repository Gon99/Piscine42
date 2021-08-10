/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:09:34 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/07 10:14:59 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_length(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int		i;
	int		is_valid;
	int		bl;
	int		j;

	i = 0;
	is_valid = 1;
	j = 1;
	bl = str_length(base);
	if (bl < 2)
		is_valid = 0;
	while (base[i] != '\0' && is_valid == 1)
	{
		if (base[i] == '+' || base[i] == '-')
			is_valid = 0;
		while (base[j] != '\0' && is_valid == 1)
		{
			if (base[i] == base[j])
				is_valid = 0;
			j++;
		}
		i++;
		j = i + 1;
	}
	return (is_valid);
}

void	calculate_base(unsigned int nbr, char *base)
{
	int					i;
	unsigned int		bl;

	i = 0;
	bl = str_length(base);
	if (nbr < bl)
		write(1, &base[nbr], 1);
	else
	{
		i = nbr % bl;
		calculate_base(nbr / bl, base);
		write(1, &base[i], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int		i;

	i = 0;
	if (is_valid_base(base) == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		i = -nbr;
	}
	else
		i = nbr;
	calculate_base(i, base);
}
