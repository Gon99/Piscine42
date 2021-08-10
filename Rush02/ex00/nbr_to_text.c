/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:03:59 by dpoveda-'s group  #+#    #+#             */
/*   Updated: 2021/07/11 22:44:43 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_str(char *str);
char	*ft_itoa(unsigned int num);
char	*find_entry(char *str, char *to_find);
int		ft_strlen(char *str);
int		handle_dic(char *dict);
void	hundreds(char *nbr, int *index, char *dict);
void	tens(char *nbr, int *index, char *dict);
void	units(char *nbr, int *index, char *dict);
void	set_word(char *nbr, int ind, int set_index, char *dict);
void	free_str(char *ptr);

char	*remove_dict_extra_sp(char *dict)
{
	int		i;
	int		j;
	int		is_entry;
	char	*new_dict;

	is_entry = 0;
	new_dict = (char *)malloc(sizeof(char) * (ft_strlen(dict) + 2));
	if (new_dict == NULL)
		return (NULL);
	i = -1;
	j = 0;
	new_dict[0] = '\n';
	while (dict[++i])
	{
		if (dict[i - 1] == ':')
			is_entry = 1;
		else if (dict[i] != ' ' && is_entry == 1)
			is_entry = 2;
		if (dict[i] != ' ' && is_entry == 0)
			new_dict[++j] = dict[i];
		else if (is_entry == 2)
			new_dict[++j] = dict[i];
	}
	new_dict[++j] = '\0';
	return (new_dict);
}

char	*get_dict_entry_str(char *nbr)
{
	int		i;
	int		len;
	char	*temp;

	len = ft_strlen(nbr);
	temp = (char *)malloc(sizeof(char) * (len + 3));
	if (temp == NULL)
		return (NULL);
	temp[0] = '\n';
	i = 0;
	while (++i < len + 2)
		temp[i] = nbr[i - 1];
	temp[len + 2] = ':';
	temp[len + 3] = '\0';
	return (temp);
}

char	*get_dict_entry(char *nbr, char *dict)
{
	int		i;
	int		entry_start;
	int		entry_len;
	char	*temp;
	char	*entry;

	temp = find_entry(dict, get_dict_entry_str(nbr));
	i = -1;
	while (temp[++i] != ':')
		;
	entry_start = ++i;
	entry_len = 0;
	while (temp[i++] != '\n')
		entry_len++;
	entry = (char *)malloc(sizeof(char) * entry_len + 1);
	if (entry == NULL)
		return (NULL);
	i = -1;
	while (++i < entry_len)
		entry[i] = temp[entry_start + i];
	entry[i] = '\0';
	return (entry);
}

// English count sets of 10^3 (3 zeros) -> set_index keep track of actual set
int	nbr_to_text(char *nbr, char *dict)
{
	int	set_index;
	int	index;

	index = 0;
	while (index < ft_strlen(nbr))
	{
		set_index = (ft_strlen(nbr) - (index + 1)) / 3;
		while (set_index == (ft_strlen(nbr) - (index + 1)) / 3 && nbr[index])
		{
			if ((ft_strlen(nbr) - index) % 3 == 0 && nbr[index] != '0')
				hundreds(nbr, &index, dict);
			else if ((ft_strlen(nbr) - index) % 3 == 2 && nbr[index] != '0')
				tens(nbr, &index, dict);
			else if (nbr[index] != '0')
				units(nbr, &index, dict);
			else if (ft_strlen(nbr) == 1)
				units(nbr, &index, dict);
			index++;
		}
		if (set_index > 0)
			set_word(nbr, index - 1, set_index, dict);
	}
	print_str("\n");
	return (0);
}

int	check_dict_and_print(char *nbr, char *dict)
{
	dict = remove_dict_extra_sp(dict);
	if (handle_dic(dict) == 0)
		return (1);
	nbr_to_text(nbr, dict);
	return (0);
}
