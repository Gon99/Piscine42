/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:19:31 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/06 12:40:13 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int		i;
	int		is_prime;

	i = 2;
	is_prime = 1;
	while (i < nb - 1 && is_prime == 1)
	{
		if (nb % i == 0)
			is_prime = 0;
		i++;
	}
	if (nb <= 1)
		is_prime = 0;
	return (is_prime);
}
