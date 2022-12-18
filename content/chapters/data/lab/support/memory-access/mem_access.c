<<<<<<< HEAD
/* SPDX-License-Identifier: BSD-3-Clause */

=======
>>>>>>> noul3
#include <stdio.h>

int main(void )
{
	int a;
	const int ca = 2;

	char *p = "LeString";
	char *const cp = "ConstLeString";
	const char *const cp2 = "LeConstString";

	int arr[20];
	char c_arr[20];

<<<<<<< HEAD
	printf("sizeof(a) = %ld\n", sizeof(a));
	printf("sizeof(ca) = %ld\n", sizeof(ca));
	printf("sizeof(p) = %ld\n", sizeof(p));
	printf("sizeof(cp) = %ld\n", sizeof(cp));
	printf("sizeof(cp2) = %ld\n", sizeof(cp2));
	printf("sizeof(arr) = %ld\n", sizeof(arr));
	printf("sizeof(c_arr) = %ld\n", sizeof(c_arr));
=======
	printf("sizeof(a) = %ld\n bss r/w", sizeof(a));
	printf("sizeof(ca) = %ld\n rodata r", sizeof(ca));
	printf("sizeof(p) = %ld\n data r/w", sizeof(p));
	printf("sizeof(cp) = %ld\n rodata r", sizeof(cp));
	printf("sizeof(cp2) = %ld\n rodata r", sizeof(cp2));
	printf("sizeof(arr) = %ld\n bss r", sizeof(arr));
	printf("sizeof(c_arr) = %ld\n bss r", sizeof(c_arr));
>>>>>>> noul3

	return 0;
}
