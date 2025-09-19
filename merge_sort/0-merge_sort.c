#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - asdsadas
 * @array: sadsadas
 * @temp: asdsadsa
 * @left: asddsa
 * @mid:    sadsa
 * @right: asdasds
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
size_t i = left, j = mid, k = left;

printf("Merging...\n");
printf("[left]: ");
print_array(array + left, mid - left);
printf("[right]: ");
print_array(array + mid, right - mid);

while (i < mid && j < right)
{
if (array[i] <= array[j])
temp[k++] = array[i++];
else
temp[k++] = array[j++];
}
while (i < mid)
temp[k++] = array[i++];
while (j < right)
temp[k++] = array[j++];

for (i = left; i < right; i++)
array[i] = temp[i];

printf("[Done]: ");
print_array(array + left, right - left);
}

/**
 * aux - asdsad
 * @array: asdasda
 * @temp: sadasdsa
 * @l:   asdasda
 * @r: asdsad
 */
void aux(int *array, int *temp, size_t l, size_t r)
{
size_t m;

if (r - l < 2)
return;

m = (l + r) / 2;
aux(array, temp, l, m);
aux(array, temp, m, r);
merge(array, temp, l, m, r);
}

/**
 * merge_sort - dasdasds
 * @array: sadasdas
 * @size: ass
 */
void merge_sort(int *array, size_t size)
{
int *temp;

if (!array || size < 2)
return;

temp = malloc(sizeof(int) * size);
if (!temp)
return;

aux(array, temp, 0, size);
free(temp);
}
