#include <stdlib.h>

/**
 * free_grid - frees memory previously allocated for a 2D grid
 * @grid: pointer to the 2D grid to free
 * @height: height of the grid
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}

