/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:38:16 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/14 17:28:48 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	int		is_space;

	is_space = 0;
	if (c == '\n' || c == '\t' || c == '\r' \
			|| c == ' ' || c == '\v')
		is_space = 1;
	return (is_space);
}

int	ft_atoi(char *str)
{
	int		neg;
	int		res;

	res = 0;
	neg = 0;
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			break ;
		res = 10 * res + *str - '0';
		str++;
	}
	if (neg % 2 == 1)
		res = -res;
	return (res);
}
