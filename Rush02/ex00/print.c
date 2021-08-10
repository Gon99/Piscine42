/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:11:35 by dpoveda-'s group  #+#    #+#             */
/*   Updated: 2021/07/11 16:50:21 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		print_char(str[i]);
}

void	print_error_dict(void)
{
	print_str("Dict error\n");
}

void	print_error(void)
{
	print_str("Error\n");
}
