<<<<<<< HEAD
/* SPDX-License-Identifier: BSD-3-Clause */
=======
#include "utils.h"
>>>>>>> noul3

#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
#include "utils/utils.h"

=======
>>>>>>> noul3
#define NUM_STEPS	10
#define ALLOC_SIZE_KB	256
#define ALLOC_SIZE	(ALLOC_SIZE_KB * 1024)

static void wait_for_input(const char *msg)
{
<<<<<<< HEAD
	char buffer[128];

	printf("%s ...", msg);
	fgets(buffer, 128, stdin);
=======
        char buffer[128];

        printf("%s ...", msg);
        fgets(buffer, 128, stdin);
>>>>>>> noul3
}

int main(void)
{
	size_t i;
	void *p;

	wait_for_input("Press key to allocate");

	for (i = 0; i < NUM_STEPS; i++) {
		p = malloc(ALLOC_SIZE);
		DIE(p == NULL, "malloc");
		printf("New allocation at %p\n", p);
<<<<<<< HEAD
=======
		free(p);
>>>>>>> noul3
	}

	wait_for_input("Press key to deallocate");

<<<<<<< HEAD
	free(p);
=======
>>>>>>> noul3

	wait_for_input("Press key to close the program");

	return 0;
}
