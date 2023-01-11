#include "sandpiles.h"
/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid(int grid[3][3])
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
 * check_unstable - check if a sandpile is unsatable
 *
 * @grid1: grid to ckeck
 *
 * Return: 0 if is unstable 1 otherwise
 */
int check_unstable(int grid1[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (0);
		}
	}
	return (1);
}
/**
 * copy_grid - copy one grid to another.
 *
 * @grid1: first sandpile to be copied
 * @grid2: where grid1 will be copied
 */
void copy_grid(int grid1[3][3], int grid2[3][3])
{
	int row = 0;
	int col = 0;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			grid2[row][col] = grid1[row][col];
		}
	}
}
/**
 * sandpiles_sum - sum two sandpiles
 *
 * @grid1: first sandpile
 * @grid2: second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row = 0;
	int col = 0;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			grid1[row][col] += grid2[row][col];
		}
	}

	if (check_unstable(grid1) == 0)
		print_grid(grid1);

	while (check_unstable(grid1) == 0)
	{
		copy_grid(grid1, grid2);
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				if (grid2[row][col] > 3)
					grid1[row][col] -= 4;
				if (col != 0 && grid2[row][col - 1] > 3)
					grid1[row][col] += 1;
				if (row != 0 && grid2[row - 1][col] > 3)
					grid1[row][col] += 1;
				if (row != 2 && grid2[row + 1][col] > 3)
					grid1[row][col] += 1;
				if (col != 2 && grid2[row][col + 1] > 3)
					grid1[row][col] += 1;
			}
		}
		if (check_unstable(grid1) == 0)
			print_grid(grid1);
	}
}
