/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:45:00 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/11 23:01:10 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_intlen(unsigned int n);
int		ft_strlen(char *str);
int		check_dict_and_print(char *nbr, char *dict);
int		open_file(char *str, char *file);
void	print_error(void);
void	print_error_dict(void);
int		ft_atoi(char *str);
char	*ft_itoa(unsigned int num);

int	handle_params(int argc, char **argv, char *nbr, char *file_c)
{
	if (argc == 2)
	{
		open_file("", file_c);
		if (ft_atoi(nbr) == 0 && nbr[0] != '0')
			return (-1);
	}
	else if (argc == 3)
	{
		open_file(argv[1], file_c);
		if (ft_atoi(nbr) == 0 && nbr[0] != '0')
			return (-1);
	}
	else
		return (-1);
	return (1);
}

char	*rm_garbage(char *nbr)
{
	int		i;
	int		j;
	int		len;
	int		start;
	char	*new_nbr;

	i = -1;
	start = -1;
	len = 0;
	while (nbr[++i])
	{
		if ((nbr[i] != '0' || i == ft_strlen(nbr) - 1) && start == -1)
			start = i;
		if (start != -1)
			len++;
	}
	new_nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (new_nbr == NULL)
		return (NULL);
	i = start - 1;
	j = -1;
	while (nbr[++i])
		new_nbr[++j] = nbr[i];
	new_nbr[++j] = '\0';
	return (new_nbr);
}

char	*rm_plus(char *nbr)
{
	int		i;
	char	*new_nbr;

	if (nbr[0] == '+')
		new_nbr = (char *)malloc(sizeof(char) * ft_strlen(nbr));
	else
		new_nbr = (char *)malloc(sizeof(char) * (ft_strlen(nbr) + 1));
	i = -1;
	if (nbr[0] == '+')
	{
		while (nbr[++i])
			new_nbr[i] = nbr[i + 1];
		new_nbr[i] = '\0';
		return (new_nbr);
	}
	return (nbr);
}

int	main(int argc, char **argv)
{
	char	*file_c;
	char	*nbr;

	nbr = argv[argc - 1];
	nbr = rm_plus(nbr);
	nbr = rm_garbage(nbr);
	file_c = (char *)malloc(690 * sizeof(char));
	if (file_c == NULL)
		return (1);
	if (handle_params(argc, argv, nbr, file_c) == -1)
	{
		print_error();
		return (1);
	}
	if (check_dict_and_print(nbr, file_c))
		print_error_dict();
	free(nbr);
	free(file_c);
	return (0);
}
