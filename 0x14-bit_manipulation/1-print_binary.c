#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print in binary form
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int bits = sizeof(unsigned long int) * 8;
	int i, flag = 0;

	for (i = bits - 1; i >= 0; i--)
	{
		if ((n >> i) & mask)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag)
		{
			_putchar('0');
		}
	}

	if (!flag)
		_putchar('0');
}

