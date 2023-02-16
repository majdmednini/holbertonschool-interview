#include <stdio.h>
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * stable_matrix - check if the matrix is stable
 * @grid: 3x3 grid
 * Return: 1 stable otherwise 0
 */
static int stable_matrix(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * sum_grid - add matrix
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 *
 */
static void sum_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 * sandpiles_sum - sum of two sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int grid_tmp[3][3];

	sum_grid(grid1, grid2);

	while (!stable_matrix(grid1))
	{
		print_grid(grid1);

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				grid_tmp[i][j] = 0;

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid1[i][j] -= 4;

					if (i - 1 >= 0)
						grid_tmp[i - 1][j] += 1;
					if (j + 1 < 3)
						grid_tmp[i][j + 1] += 1;
					if (i + 1 < 3)
						grid_tmp[i + 1][j] += 1;
					if (j - 1 >= 0)
						grid_tmp[i][j - 1] += 1;
				}
			}
		}
		sum_grid(grid1, grid_tmp);
	}
}