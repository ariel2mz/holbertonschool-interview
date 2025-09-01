#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * is_number - check if a string is composed of digits only
 * @s: string to check
 * Return: 1 if number, 0 otherwise
 */
int is_number(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (!isdigit(s[i]))
			return (0);
	}
	return (1);
}

/**
 * print_error - print Error and exit with status 98
 */
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiply two positive numbers
 * @argc: argument count
 * @argv: sadsadasdsa
 * Return: sadasdsadas
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, i, j, *result, carry, n1, n2, sum, start;

	if (argc != 3)
    {
			printf("Error\n");
	        exit(98);
    }

	num1 = argv[1];
	num2 = argv[2];

	if (!is_number(num1) || !is_number(num2))
    {
			printf("Error\n");
	        exit(98);
    }

	len1 = strlen(num1);
	len2 = strlen(num2);

	result = calloc(len1 + len2, sizeof(int));
	if (result == NULL)
		exit(98);

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			result[i + j + 1] = sum % 10;
			carry = sum / 10;
		}
		result[i + j + 1] += carry;
	}

	start = 0;
	while (start < len1 + len2 && result[start] == 0)
		start++;

	if (start == len1 + len2)
		printf("0");
	else
		for (i = start; i < len1 + len2; i++)
			printf("%d", result[i]);
	printf("\n");

	free(result);
	return (0);
}
