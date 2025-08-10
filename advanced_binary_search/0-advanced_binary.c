#include <stdio.h>
#include <stddef.h>
#include "search_algos.h"

/**
 * print_array - asdsadas
 * @array: asdasdsa
 * @left: asdadas
 * @right: sadasdas
 */
void print_array(int *array, size_t left, size_t right)
{
    size_t i;

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");
}

/**
 * recursive_binary - sadadadsa
 * @array: adsasdadsa
 * @left: asdasdasdas
 * @right: sadasdadads
 * @value: asdasdasdas
 *
 * Return: Tsadas
 */
int recursive_binary(int *array, size_t left, size_t right, int value)
{
    size_t mid;

    if (left > right)
        return (-1);

    print_array(array, left, right);

    mid = left + (right - left) / 2;

    if (array[mid] == value)
    {
        if (mid == left || array[mid - 1] != value)
            return (mid);
        return (recursive_binary(array, left, mid, value));
    }
    else if (array[mid] < value)
        return (recursive_binary(array, mid + 1, right, value));
    else
        return (recursive_binary(array, left, mid - 1, value));
}

/**
 * advanced_binary - asdasdsa
 * @array: asdsadsa
 * @size: sadasdas
 * @value: asdasd
 *
 * Return: asdasdsa
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return (recursive_binary(array, 0, size - 1, value));
}
