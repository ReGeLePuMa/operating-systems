<<<<<<< HEAD
/* SPDX-License-Identifier: BSD-3-Clause */

=======
>>>>>>> noul3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mcheck.h>

struct student {
	char name[128];
	unsigned int age;
	char favorite_os[16];
};

<<<<<<< HEAD
static void init_student(struct student *s, const char *name, unsigned int age, const char *os)
=======
void init_student(struct student *s, const char *name, unsigned int age, const char *os)
>>>>>>> noul3
{
	strcpy(s->name, name);
	s->age = age;
	strcpy(s->favorite_os, os);
}

<<<<<<< HEAD
static void print_student(struct student *s)
=======
void print_student(struct student *s)
>>>>>>> noul3
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
<<<<<<< HEAD

	s = malloc(sizeof(*s));
        init_student(s, "Ioana David", 23, "macOS");
	print_student(s);
=======
	printf("%ld\n",sizeof(struct student));
	free(s);
	s = malloc(sizeof(*s));
        init_student(s, "Ioana David", 23, "macOS");
	print_student(s);
	printf("%ld\n",sizeof(struct student));
>>>>>>> noul3

	free(s);

	return 0;
}
