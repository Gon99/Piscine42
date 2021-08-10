/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:46:40 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/11 22:48:59 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		ft_strlen(char *str);
void	print_error_dict(void);
void	print_error(void);

int	fill_fd(char *file)
{
	int		fd;

	fd = 0;
	if (ft_strlen(file) == 0)
		fd = open("numbers.dict", O_RDONLY);
	else
		fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error_dict();
		return (-1);
	}
	return (fd);
}

int	fill_file_c(int fd, char *file_c)
{
	int		sz;

	sz = read(fd, file_c, 690);
	if (sz == 0)
	{
		print_error_dict();
		return (0);
	}
	file_c[sz] = '\0';
	return (sz);
}

int	open_file(char *str, char *file_c)
{
	int		fd;
	int		sz;

	fd = fill_fd(str);
	if (fd < 0)
		return (0);
	sz = fill_file_c(fd, file_c);
	if (sz <= 0)
		return (0);
	if (close(fd) < 0)
	{
		print_error();
		return (0);
	}
	close(fd);
	return (1);
}
