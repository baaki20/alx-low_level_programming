#include <stdio.h>

/**
 * main - prints all possible different combinations of two digits
 * Return: Always 0 (Success)
 */
int main(void)
{
    char digit1, digit2;

    for (digit1 = '0'; digit1 <= '8'; digit1++)
    {
        for (digit2 = '1'; digit2 <= '9'; digit2++)
        {
            if (digit2 > digit1)
            {
                putchar(digit1);
                putchar(digit2);
                if (digit1 != '8' || digit2 != '9')
                {
                    putchar(',');
                    putchar(' ');
                }
            }
        }
    }
    putchar('\n');
    return (0);
}

