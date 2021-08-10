/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 11:14:20 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/04 22:14:53 by dmacicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	printMatrix(int ***matrix);

int *fillPatternRow(int c1, int c2, int c3, int c4)
{
	int	*patRow = (int*)malloc(sizeof(int) * 4);
	
	patRow[0] = c1;
	patRow[1] = c2;
	patRow[2] = c3;
	patRow[3] = c4;
	return (patRow);
}

void	ft_putchar(int num)
{
	char x;

	x = num + '0';
	write(1, &x, 1);
}
int	fill_matrix(int **upDown, int **leftRight)
{
	int	iC;
	int iR;
	int iV;
	
	int ***row = (int***)malloc(4*sizeof(int**));
	iR = 0;	
	while (iR < 4)
	{
        row[iR] = (int**) malloc(4*sizeof(int*));
		iC = 0;
        while (iC < 4)
		{
			row[iR][iC] = (int*)malloc(2*sizeof(int));
        	iC++;
		}
		iR++;
	}

	int iP;

	int ****pattern = (int****)malloc(7*sizeof(int***));
	iR = 0;
	while (iR < 7)
	{
        pattern[iR] = (int***) malloc(7*sizeof(int**));
		iC = 0;
        while (iC < 7)
		{
			pattern[iR][iC] = (int**)malloc(6*sizeof(int*));
			iP = 0;
			while (iP < 4)
			{
				pattern[iR][iC][iP] = (int*)malloc(4*sizeof(int));
				iP++;
			}	
			iC++;
		}
		iR++;
	}

	iR = 0;
	while (iR < 4)
	{
		iC = 0;
		while (iC < 4)
		{
			iV = 0;
			while (iV < 2)
			{
				row[iR][iC][iV] = 0;
				iV++;
			}
			iC++;	
		}
		iR++;
	}	

	iR = 0;
	while (iR < 7)
	{
		iC = 0;
		while (iC < 7)
		{
			iV = 0;
			while (iV < 6)
			{
				iP = 0;
				if (iR == 1 && iC == 2)
				{
					if (iV == 0)
						pattern[iR][iC][iV] = fillPatternRow(4,1,2,3); 
					else if (iV == 1)
						pattern[iR][iC][iV] = fillPatternRow(4,2,1,3);
				    else
						pattern[iR][iC][iV]	= fillPatternRow(0,0,0,0);
				}
				else if (iR == 1 && iC == 3)
				{
					if (iV == 0)
						pattern[iR][iC][iV] = fillPatternRow(4,1,3,2); 
					else if (iV == 1)
						pattern[iR][iC][iV] = fillPatternRow(4,2,3,1); 
					else if (iV == 2)
						pattern[iR][iC][iV] = fillPatternRow(4,3,1,2);
				    else
						pattern[iR][iC][iV]	= fillPatternRow(0,0,0,0);
				}
				if (iR == 2 && iC == 1)
				{
					if (iV == 0)
						pattern[iR][iC][iV] = fillPatternRow(3,1,2,4); 
					else if (iV == 1)
						pattern[iR][iC][iV] = fillPatternRow(3,2,1,4); 
				    else
						pattern[iR][iC][iV]	= fillPatternRow(0,0,0,0);
				}
				if (iR == 2 && iC == 2)
				{
					if (iV == 0)
						pattern[iR][iC][iV] = fillPatternRow(3,1,4,2); 
					else if (iV == 1)
						pattern[iR][iC][iV] = fillPatternRow(3,2,4,1); 
					else if (iV == 2)
						pattern[iR][iC][iV] = fillPatternRow(3,4,1,2);
					else if (iV == 3)
						pattern[iR][iC][iV] = fillPatternRow(2,1,4,3); 
					else if (iV == 4)
						pattern[iR][iC][iV] = fillPatternRow(2,4,1,3); 
					else if (iV == 5)
						pattern[iR][iC][iV] = fillPatternRow(1,4,2,3); 
				}
				if (iR == 2 && iC == 3)
				{
					if (iV == 0)
						pattern[iR][iC][iV] = fillPatternRow(3,4,2,1);
					else if (iV == 1)
						pattern[iR][iC][iV] = fillPatternRow(2,4,3,1); 
					else if (iV == 2)
						pattern[iR][iC][iV] = fillPatternRow(1,4,3,2); 
				    else
						pattern[iR][iC][iV]	= fillPatternRow(0,0,0,0);
				}
				if (iR == 3 && iC == 1)
				{
					if (iV == 0)
						pattern[iR][iC][iV] = fillPatternRow(2,1,3,4);
					else if (iV == 1)
						pattern[iR][iC][iV] = fillPatternRow(2,3,1,4);
					else if (iV == 2)
						pattern[iR][iC][iV] = fillPatternRow(1,3,2,4); 
				    else
						pattern[iR][iC][iV]	= fillPatternRow(0,0,0,0);
				}
				if (iR == 3 && iC == 2)
				{
					if (iV == 0)
						pattern[iR][iC][iV] = fillPatternRow(2,3,4,1);
					else if (iV == 1)
						pattern[iR][iC][iV] = fillPatternRow(1,2,4,3);
					else if (iV == 2)
						pattern[iR][iC][iV] = fillPatternRow(1,3,4,2);
				    else
						pattern[iR][iC][iV]	= fillPatternRow(0,0,0,0);
				}
				else
					pattern[iR][iC][iV] = fillPatternRow(0, 0, 0, 0);
				iV++;
			}
			iC++;	
		}
		iR++;
	}

	int	finish;
	int fix = 0;
	int numberFind;
	int lR;
	int uD;

	lR = 0;
	uD = 0;	
	finish = 0;
	numberFind = 0;
	while (!finish)
	{
		if (fix == 0)
		{
			iR = 0;
			while (iR < 4)
			{
				iC = 0;
				while (iC < 4)
				{
					if (4 == upDown[0][iC])
					{
						row[0][iC][0] = 1;
						row[0][iC][1] = 1;
						row[1][iC][0] = 2;
						row[1][iC][1] = 1;
						row[2][iC][0] = 3;
						row[2][iC][1] = 1;
						row[3][iC][0] = 4;
						row[3][iC][1] = 1;
						lR = 1;
						numberFind = iC;			
					}
					else if (4 == upDown[1][iC])
					{
						row[0][iC][0] = 4;
						row[0][iC][1] = 1;
						row[1][iC][0] = 3;
						row[1][iC][1] = 1;
						row[2][iC][0] = 2;
						row[2][iC][1] = 1;
						row[3][iC][0] = 1;
						row[3][iC][1] = 1;
						lR = 1;
						numberFind = iC;
					}
					else if (4 == leftRight[0][iR])
					{
						row[iR][0][0] = 1;
						row[iR][0][1] = 1;
						row[iR][1][0] = 2;
						row[iR][1][1] = 1;
						row[iR][2][0] = 3;
						row[iR][2][1] = 1;
						row[iR][3][0] = 4;
						row[iR][3][1] = 1;
						uD = 1;
						numberFind = iR;
					}
					else if (4 == leftRight[1][iR])
					{
						row[iR][0][0] = 4;
						row[iR][0][1] = 1;
						row[iR][1][0] = 3;
						row[iR][1][1] = 1;
						row[iR][2][0] = 2;
						row[iR][2][1] = 1;
						row[iR][3][0] = 1;
						row[iR][3][1] = 1;
						uD = 1;
						numberFind = iR;
					}
					iC++;
				}
				iR++;
			}
			if (iR == 4)
				fix = 1;
			
		}
		
		if (lR == 1)
		{
			iR = 0;
			iC = 0;
			while (row[iR][iC][1] == 1)
			{
				iC++;
				if(iC == 4)
				{
					iR++;
					iC = 0;
				}
			}
			int lView = leftRight[0][iR];
			int rView = leftRight[1][iR];
			int iF;
			
			int **options = (int**)malloc(sizeof(int*) * 6);

			
			int indexOp;

			indexOp = 0;
			iF = 0;
			while (iF < 6)
			{
				options[iF] = (int*)malloc(sizeof(int) * 4);
				iF++;
			}

			iF = 0;
			while (iF < 6)
			{
				indexOp = 0;
				while (indexOp < 4)
				{
					options[iF][indexOp] = 0;
					indexOp++;
				}
				iF++;
			}
			indexOp = 0;
			iV = 0;
			iF = 0;
			while (iF < 6)
			{
				if(pattern[lView][rView][iF][iC - 1] == row[iR][iC - 1][0])
				{
						options[indexOp] = fillPatternRow(pattern[lView][rView][iF][0], pattern[lView][rView][iF][1], pattern[lView][rView][iF][2], pattern[lView][rView][iF][3]);
					indexOp++;
				}
				iF++;
			}
			iV = 0;
			if(indexOp == 1)
			{
				while (iV < 4)
				{
					row[iR][iV][0] =  options[indexOp - 1][iV];
					iV++;
				}
			}
			lR = 0;
			uD = 1;
		}


		finish++;
	}
	printMatrix(row);
	return (1);
}

void	printMatrix(int ***matrix)
{
	ft_putchar(matrix[0][0][0]);
	write(1, " ", 1);
	ft_putchar(matrix[0][1][0]);
	write(1, " ", 1);
	ft_putchar(matrix[0][2][0]);
	write(1, " ", 1);
	ft_putchar(matrix[0][3][0]);
	write(1, "\n", 1);
	ft_putchar(matrix[1][0][0]);
	write(1, " ", 1);
	ft_putchar(matrix[1][1][0]);
	write(1, " ", 1);
	ft_putchar(matrix[1][2][0]);
	write(1, " ", 1);
	ft_putchar(matrix[1][3][0]);
	write(1, "\n", 1);
	ft_putchar(matrix[2][0][0]);
	write(1, " ", 1);
	ft_putchar(matrix[2][1][0]);
	write(1, " ", 1);
	ft_putchar(matrix[2][2][0]);
	write(1, " ", 1);
	ft_putchar(matrix[2][3][0]);
	write(1, "\n", 1);
	ft_putchar(matrix[3][0][0]);
	write(1, " ", 1);
	ft_putchar(matrix[3][1][0]);
	write(1, " ", 1);
	ft_putchar(matrix[3][2][0]);
	write(1, " ", 1);
	ft_putchar(matrix[3][3][0]);
	write(1, "\n", 1);
}
