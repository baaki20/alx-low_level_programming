#include <stdio.h>
#include <string.h>

/**
 * check_password - Checks if the given password matches the correct password.
 * @password: The password to be checked.
 *
 * Return: 1 if the password is correct, 0 otherwise.
 */
int check_password(const char *password)
{
	const char *correct_password;

	correct_password = "Congratulations!";
	return (strcmp(password, correct_password) == 0);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, 1 on incorrect usage or invalid password.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <password>\n", argv[0]);
		return (1);
	}

	if (check_password(argv[1]))
	{
		printf("Congratulations!\n");
	}
	else
	{
		printf("Invalid password!\n");
	}

	return (0);
}

