#include "slide_line.h"

int slide_line(int *line, size_t size, int direction)
{
    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return 0;

    int temp[size];
    size_t i, j;

    j = 0;
    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
        {
            if (line[i] != 0)
                temp[j++] = line[i];
        }
        while (j < size)
            temp[j++] = 0;
    }
    else
    {
        for (i = size; i-- > 0; )
        {
            if (line[i] != 0)
                temp[j++] = line[i];
        }
        while (j < size)
            temp[j++] = 0;
    }

    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size - 1; i++)
        {
            if (temp[i] != 0 && temp[i] == temp[i + 1])
            {
                temp[i] *= 2;
                temp[i + 1] = 0;
            }
        }
    }
    else
    {
        for (i = 0; i < size - 1; i++)
        {
            if (temp[i] != 0 && temp[i] == temp[i + 1])
            {
                temp[i] *= 2;
                temp[i + 1] = 0;
            }
        }
    }

    j = 0;
    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
        {
            if (temp[i] != 0)
                line[j++] = temp[i];
        }
        while (j < size)
            line[j++] = 0;
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            if (temp[i] != 0)
                line[size - 1 - j++] = temp[i];
        }
        while (j < size)
            line[size - 1 - j++] = 0;
    }

    return 1;
}