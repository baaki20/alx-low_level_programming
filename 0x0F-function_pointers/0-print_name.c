/**
 * print_name - Calls a function that prints a name
 * @name: Name to print
 * @f: Pointer to function that prints a name
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}

