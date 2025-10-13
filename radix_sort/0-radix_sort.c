#include "sort.h"
#include <stdlib.h>

/**
 * gm - sadsadsa
 * @array: sadasdasdsa
 * @size: dasdasdas
 * Return: sadasdsadsa
 */
int gm(int *array, size_t size)
{
size_t i;
int max = array[0];

for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
return (max);
}

/**
 * csr - sadasdas
 * @array: sadasdas
 * @size: sadasda
 * @exp: sadsdasd
 */
void csr(int *array, size_t size, int exp)
{
int *output, count[10] = {0};
size_t i;

output = malloc(sizeof(int) * size);
if (!output)
return;

for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;

for (i = 1; i < 10; i++)
count[i] += count[i - 1];

for (i = size; i > 0; i--)
{
output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
count[(array[i - 1] / exp) % 10]--;
}

for (i = 0; i < size; i++)
array[i] = output[i];

free(output);
}

/**
 * radix_sort - asdasdsa
 * asdasdsadas
 * @array: sad
 * @size: sadas
 */
void radix_sort(int *array, size_t size)
{
int max, exp;

if (!array || size < 2)
return;

max = gm(array, size);

for (exp = 1; max / exp > 0; exp *= 10)
{
csr(array, size, exp);
print_array(array, size);
}
}
