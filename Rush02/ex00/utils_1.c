/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:46:05 by dpoveda-'s group  #+#    #+#             */
/*   Updated: 2021/07/11 20:24:18 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	ft_intlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(unsigned int num)
{
	int		i;
	char	*str;

	i = ft_intlen(num);
	str = (char *)malloc(sizeof(char) * (ft_intlen(num) + 1));
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		str[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
	return (str);
}

char	*find_entry(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0' && str[i + j + 1] == ':')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

unsigned int	str_to_int(char *str)
{
	int					i;
	unsigned long int	nb;

	i = -1;
	nb = 0;
	while (str[++i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i] - 48);
	return (nb);
}

unsigned int	ft_atoi(char *str)
{
	int					i;
	unsigned long int	nb;

	i = -1;
	nb = 0;
	nb = str_to_int(&str[i]);
	i = -1;
	while (str[++i] == '0')
		;
	i -= 1;
	while (str[++i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i] - '0');
	if (nb > 4294967295)
		nb = 0;
	return (nb);
}
