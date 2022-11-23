#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mcheck.h>

struct student {
	char name[128];
	unsigned int age;
	char favorite_os[16];
};

void init_student(struct student *s, const char *name, unsigned int age, const char *os)
{
	strcpy(s->name, name);
	s->age = age;
	strcpy(s->favorite_os, os);
}

void print_student(struct student *s)
{
	printf("%s is %u years old and likes %s\n",
			s->name, s->age, s->favorite_os);
}

int main(void)
{
	struct student *s;

	mtrace();

	s = malloc(sizeof(*s));
	init_student(s, "Andrei Popescu", 22, "Linux");
	print_student(s);
	printf("%ld\n",sizeof(struct student));
	free(s);
	s = malloc(sizeof(*s));
        init_student(s, "Ioana David", 23, "macOS");
	print_student(s);
	printf("%ld\n",sizeof(struct student));

	free(s);

	return 0;
}
