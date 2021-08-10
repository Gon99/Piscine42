/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:38:15 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/01 15:51:32 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	return (str);
}

int	is_non_alpha_num(char c)
{
	int		r;

	r = 0;
	if ((c < 'a' || c > 'z') && (c < '0' || c > '9') && (c < 'A' || c > 'Z'))
		r = 1;
	return (r);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (is_non_alpha_num(str[i - 1]) == 1)
			{	
				str[i] = str[i] - 32;
			}
		}
		i++;
	}
	return (str);
}
