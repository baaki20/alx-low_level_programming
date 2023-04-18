#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Defines a dog's attributes
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Name of the dog's owner
 *
 * Description: This struct defines the attributes of a dog, including
 * its name, age, and owner.
 */

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void print_dog(struct dog *d);
void init_dog(struct dog *d, char *name, float age, char *owner);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
