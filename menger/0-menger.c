#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * hole - asdasdasdas
 * @row: row
 * @col: col
 * Return: 1 o 0
 */
static int hole(int row, int col)
{
    while (row > 0 || col > 0)
    {
        if (row % 3 == 1 && col % 3 == 1)
            return 1;  // This is a hole
        row /= 3;
        col /= 3;
    }
    return 0;
}

/**
 * menge - adssadas
 * @level: the level of the sponge
 */
void menger(int level)
{
    if (level < 0)
        return;

    int size = pow(3, level);
    int row, col;

    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            if (hole(row, col))
                putchar(' ');
            else
                putchar('#');
        }
        putchar('\n');
    }
}