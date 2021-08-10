/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 11:14:20 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/04 22:14:47 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int *malloc_arr(char *str, int pos)
{
	int *arr;
	int arr_index;

	arr = (int*)malloc(sizeof(int) * 4);
	if (arr == NULL)
	{	
		write(1, "Error de memoria", 16);
		return arr;
	}
	arr_index = 0;
	while (arr_index < 4)
	{
		if (str[pos] == ' ')
			pos++;
		arr[arr_index] = str[pos] - '0';
		arr_index++;
		pos++;
	}
	return arr;
}

void	initialize_limits(char *str, int **up_and_down, int **left_and_right)
{
	int	i;
	int pos;

	i = 0;
	pos = 0;
	while (i < 2)
	{
		up_and_down[i] = malloc_arr(str, pos);
		left_and_right[i] = malloc_arr(str, pos + 16);
		i++;
		pos += 8;
	}
}

int first_validation(char *str)
{
	int i;
	int is_valid;

	i = 0;
	is_valid  = 1;
	while (str[i] != '\0')
	{
		if (((str[i] < '1' ||  str[i] > '4') && 0 == i % 2) || (1 == i % 2 && str[i] != ' '))
		{			
			is_valid = 0;
			break;
		}
		i++;
	}
	return (is_valid);
}

int	validate_matrix(int **arr)
{
	int i;
	int is_valid;
	
	i = 0;
	is_valid = 1;
	while (i < 4 && is_valid  == 1)
	{
		if (arr[0][i] == 4)
			is_valid = arr[1][i] == 1;
		if (arr[0][i] == 3)
			is_valid = arr[1][i] <= 2;
		if (arr[0][i] == 2)
			is_valid = arr[1][i] <= 3;
		if (arr[0][i] == 1)
			is_valid =  arr[1][i] >= 2;
		i++;
	}
	return (is_valid);
}
