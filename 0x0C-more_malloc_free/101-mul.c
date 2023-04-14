#include <stdio.h>
#include <stdlib.h>

int _strlen(char *s);
void _puts(char *s);
int _isdigit(int c);
void _print_error(void);

/**
 * main - multiplies two positive numbers
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	int i, j, n, m, res, carry;
	int *result;
	char *num1, *num2;

	if (argc != 3)
		_print_error();

	num1 = argv[1];
	num2 = argv[2];

	for (i = 0; num1[i]; i++)
	{
		if (!_isdigit(num1[i]))
		_print_error();
	}

	for (j = 0; num2[j]; j++)
	{
		if (!_isdigit(num2[j]))
		_print_error();
	}

	n = _strlen(num1);
	m = _strlen(num2);

	result = calloc(n + m, sizeof(int));

	if (!result)
		return (1);

	for (i = n - 1; i >= 0; i--)
	{
		carry = 0;

		for (j = m - 1; j >= 0; j--)
		{
			res = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1] + carry;
			result[i + j + 1] = res % 10;
			carry = res / 10;
		}

		result[i + j + 1] += carry;
	}

	i = 0;

	while (i < n + m && result[i] == 0)
		i++;

	if (i == n + m)
		putchar('0');

	for (; i < n + m; i++)
		putchar(result[i] + '0');

	putchar('\n');

	free(result);

	return (0);
}

/**
 * _strlen - computes the length of a string
 *
 * @s: string to compute the length of
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;

	return (i);
}

/**
 * _puts - prints a string
 *
 * @s: string to print
 */
void _puts(char *s)
{
	while (*s)
		putchar(*s++);
}

/**
 * _isdigit - checks if a character is a digit
 *
 * @c: character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _print_error - prints an error message and exits with status 98
 */
void _print_error(void)
{
	_puts("Error");
	putchar('\n');
	exit(98);
}

