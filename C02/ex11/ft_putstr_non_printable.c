/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:58:14 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/02 12:29:28 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	isPrintable(char c)
{
	int		res;

	res = 1;
	if (c < 32 || c == 127)
		res = 0;
	return (res);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	decToHex(int num, char *hexanum_decimal, int j)
{
	int		var;

	while (num != 0)
	{
		var = num % 16;
		if (var < 10)
			var = var + 48;
		else
			var = var + 87;
		hexanum_decimal[j++] = var;
		num /= 16;
	}
	if (j == 3)
	{
		var = hexanum_decimal[1];
		hexanum_decimal[1] = hexanum_decimal[2];
		hexanum_decimal[2] = var;
	}
	else
	{
		var = hexanum_decimal[1];
		hexanum_decimal[1] = '0';
		hexanum_decimal[2] = var;
	}
}

void	add_hexadecimal(char *str, char *hexa, int pos)
{
	int		i;
	char	str_aux[10000];
	int		aux_p;
	int		aux_p2;
	int		r;

	i = 0;
	r = 0;
	ft_strcpy(str_aux, str);
	aux_p = pos + 1;
	aux_p2 = pos;
	while (hexa[i] != '\0')
	{
		r++;
		str[pos] = hexa[i];
		i++;
		pos++;
	}
	while (str_aux[aux_p] != '\0')
	{
		str[aux_p2 + r - 1] = str_aux[aux_p];
		aux_p++;
		aux_p2++;
		i++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		j;
	int		i;
	char	hexanum_decimal[3];
	int		r;

	i = 0;
	j = 0;
	r = 0;
	while (str[i] != '\0')
	{
		if (!isPrintable(str[i]))
		{
			hexanum_decimal[j] = '\\';
			j++;
			decToHex(str[i], hexanum_decimal, j);
			add_hexadecimal(str, hexanum_decimal, i);
		}
		i++;
	}
	while (str[r] != '\0')
	{
		write(1, &str[r], 1);
		r++;
	}
}
