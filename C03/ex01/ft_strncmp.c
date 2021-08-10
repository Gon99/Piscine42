/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:02:53 by goliano-          #+#    #+#             */
/*   Updated: 2021/06/30 10:31:03 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int		i;
	unsigned int		r;

	i = 0;
	r = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (i == n)
			break ;
		if (s1[i] > s2[i])
		{
			r = 1;
			break ;
		}
		if (s1[i] < s2[i])
		{
			r = -1;
			break ;
		}
		i++;
	}
	return (r);
}
