/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:43:40 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/05 13:33:21 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0 || (nb == 0 && power != 0))
		return (0);
	else if (power == 0 || (nb == 0 && power == 0))
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}
