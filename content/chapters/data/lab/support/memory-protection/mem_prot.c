<<<<<<< HEAD
/* SPDX-License-Identifier: BSD-3-Clause */

=======
>>>>>>> noul3
#include <stdio.h>

static int data[] = {10, 20, 30, 40};	/* stored in .data section (rw-) */

<<<<<<< HEAD
=======
const float pi=3.14;

>>>>>>> noul3
static void exec_do_nothing(void)	/* stored in .text section (r-x) */
{
}

static void do_write(const char *msg, void *address, int value)
{
	puts(msg);
	* (int *) address = value;
}

static void do_read(const char *msg, void *address)
{
	int p;

	puts(msg);
	p = * (int *) address;
	(void) p;
}

static void do_exec(const char *msg, void *address)
{
	void (*f)(void) = (void (*)(void)) address;

	puts(msg);
	f();
}

int main(void)
{
	do_read("reading from .data section", &data[0]);
	do_write("writing to .data section", &data[0], 77);

	do_read("reading from .text section", exec_do_nothing);
	do_exec("executing .text section", exec_do_nothing);

<<<<<<< HEAD
=======
	do_read("reading",(void*)&pi);
	do_write("writing",(void*)&pi,3.2);
	do_exec("executing",(void*)&pi);
>>>>>>> noul3
	/* These won't work due to permission issues. */
	//do_exec("executing .data section", &data[0]);
	//do_write("writing to .text section", exec_do_nothing, 77);
	//do_read("reading from NULL", NULL);

	return 0;
}
