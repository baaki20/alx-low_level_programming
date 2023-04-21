#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_all - prints anything
 * @format: a list of types of arguments passed to the function
 * c: char
 * i: integer
 * f: float
 * s: char * (if the string is NULL, print (nil) instead)
 * any other char should be ignored
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	const char *p = format;
	char *s;
	int i;
	float f;

	va_start(ap, format);

	while (p && *p)
	{
		switch (*p++)
		{
			case 'c':
				printf("%c", va_arg(ap, int));
				break;
			case 'i':
				printf("%d", va_arg(ap, int));
				break;
			case 'f':
				printf("%f", va_arg(ap, double));
				break;
			case 's':
				s = va_arg(ap, char *);
				if (s)
					printf("%s", s);
				else
					printf("(nil)");
				break;
			default:
				continue;
		}

		if (*p)
			printf(", ");
	}

	printf("\n");

	va_end(ap);
}

