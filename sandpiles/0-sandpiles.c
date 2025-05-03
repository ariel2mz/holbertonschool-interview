#include <stdio.h>

#define SIZE 3


/**
 * is_unstable - Checks if a sandpile is unstable
 * @grid: 3x3 grid
 *
 * Return: 1 if unstable, 0 if stable
 */
int is_unstable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (grid[i][j] > 3)
                return (1);
        }
    }
    return (0);
}

/**
 * topple - Performs one toppling operation
 * @grid: 3x3 grid to update
 */
void topple(int grid[3][3])
{
    int temp[3][3] = {{0}};
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (grid[i][j] > 3)
            {
                temp[i][j] -= 4;
                if (i > 0)
                    temp[i - 1][j] += 1;
                if (i < SIZE - 1)
                    temp[i + 1][j] += 1;
                if (j > 0)
                    temp[i][j - 1] += 1;
                if (j < SIZE - 1)
                    temp[i][j + 1] += 1;
            }
        }
    }

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            grid[i][j] += temp[i][j];
        }
    }
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First 3x3 grid (will be updated in-place)
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    while (is_unstable(grid1))
    {
        print_grid(grid1);
        topple(grid1);
    }
}
