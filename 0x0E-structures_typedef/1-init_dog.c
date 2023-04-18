#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dog {
	char name[20];
	float age;
	char owner[20];
};

void init_dog(struct dog *d, char *name, float age, char *owner) {
	strcpy(d->name, name);
	d->age = age;
	strcpy(d->owner, owner);
}

int main() {
	struct dog my_dog;
	init_dog(&my_dog, "Fido", 3.5, "John");

	printf("Name: %s\n", my_dog.name);
	printf("Age: %.1f\n", my_dog.age);
	printf("Owner: %s\n", my_dog.owner);

	return 0;
}

