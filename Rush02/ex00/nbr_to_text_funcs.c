/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_text_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:37:37 by dpoveda-'s group  #+#    #+#             */
/*   Updated: 2021/07/11 22:17:17 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	print_str(char *str);
char	*get_dict_entry(char *nbr, char *dict);
char	*ft_itoa(unsigned int num);
int		ft_strlen(char *str);

void	print_sp(int index)
{
	if (index != 0)
		print_str(" ");
}

void	set_word(char *nbr, int ind, int set_index, char *dict)
{
	int				i;
	unsigned int	pow10;

	if (nbr[ind] != '0' || nbr[ind - 1] != '0' || nbr[ind - 2] != '0')
		print_str(" ");
	i = -1;
	pow10 = 1;
	while (++i < set_index)
		pow10 *= 1000;
	if (nbr[ind] != '0' || nbr[ind - 1] != '0' || nbr[ind - 2] != '0')
		print_str(get_dict_entry(ft_itoa(pow10), dict));
}

void	hundreds(char *nbr, int *index, char *dict)
{
	char	*temp;

	print_sp(*index);
	temp = (char *)malloc(sizeof(char) + 1);
	if (temp == NULL)
		return ;
	temp[0] = nbr[*index];
	temp[1] = '\0';
	print_str(get_dict_entry(temp, dict));
	print_str(" ");
	print_str(get_dict_entry("100", dict));
	free(temp);
}

void	units(char *nbr, int *index, char *dict)
{
	char	*temp;

	print_sp(*index);
	if (nbr[*index] == '0' && ft_strlen(nbr) != 1)
		return ;
	temp = (char *)malloc(sizeof(char) + 1);
	if (temp == NULL)
		return ;
	temp[0] = nbr[*index];
	temp[1] = '\0';
	print_str(get_dict_entry(temp, dict));
	free(temp);
}

void	tens(char *nbr, int *index, char *dict)
{
	char	*temp;

	print_sp(*index);
	temp = (char *)malloc(sizeof(char) * 2 + 1);
	if (temp == NULL)
		return ;
	temp[0] = nbr[*index];
	if (nbr[*index] == '1')
	{
		*index += 1;
		temp[1] = nbr[*index];
		temp[2] = '\0';
		print_str(get_dict_entry(temp, dict));
	}
	else
	{
		temp[1] = '0';
		temp[2] = '\0';
		print_str(get_dict_entry(temp, dict));
	}
	free(temp);
}
