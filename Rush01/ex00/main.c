/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 11:12:13 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/04 22:05:45 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		initialize_limits(char *str, int **up_and_down, int **left_and_right);
int		validate_matrix(int **arr);
int		first_validation(char *str);
int		fill_matrix(int **upDown, int **leftRight);

int	main(int argc, char **argv)
{
	int	**up_down;
	int	**left_right;

	up_down = (int **)malloc(sizeof(int *) * 2);
	left_right = (int **)malloc(sizeof(int *) * 2);
	if (up_down == NULL || left_right == NULL)
		write (1, "Problemas de memoria con el malloc", 34);
	else if (argc == 2)
	{
		initialize_limits(argv[1], up_down, left_right);
		if (!first_validation(argv[1]))
			write (1, "Los parámetros introducidos, no son válidos.", 46);
		else if (!validate_matrix(up_down) || !validate_matrix(left_right))
			write (1, "Los límites proporcionados, no son válidos.", 45);
		else
			fill_matrix(up_down, left_right);
	}
	else
		write (1, "Meta un único parámetro para ejecutar el programa.", 46);
	return (0);
}
