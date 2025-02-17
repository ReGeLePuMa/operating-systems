<<<<<<< HEAD
/* SPDX-License-Identifier: BSD-3-Clause */

=======
>>>>>>> noul3
#include <stdio.h>
#include <stdlib.h>

#define ON_STACK 1
#define N 10

<<<<<<< HEAD
typedef struct AttackOnTitanCharacter {
	size_t id;
	char *name;
} AttackOnTitanCharacter;

static AttackOnTitanCharacter* createElem(size_t id, char *name)
{
	// allocation happens here
	AttackOnTitanCharacter *p = malloc(sizeof(AttackOnTitanCharacter));
	p->id = id;
	p->name = name;
	return p;
}

static void freeList(AttackOnTitanCharacter **list, size_t length)
{
	size_t i;

	for (i = 0; i < length; i++)
		free(list[i]);

#ifndef ON_STACK
	free(list);
#endif
}

static void printCharacterList(AttackOnTitanCharacter **list, size_t length)
{
	size_t i;

	for(i = 0; i < length; i++)
		printf("id = %ld, name = %s\n", list[i]->id, list[i]->name);
}

int main(void)
{
#ifdef ON_STACK
	// allocating the list on the stack
	AttackOnTitanCharacter *list[N];
#else
	AttackOnTitanCharacter **list;
	// dynamically allocating the list
	list = malloc(N, sizeof(AttackOnTitanCharacter*));
#endif

	list[0] = createElem(1, "Eren");
	list[1] = createElem(2, "Zeke");
	list[2] = createElem(3, "Kenny");
	list[3] = createElem(4, "Reiner");
	list[4] = createElem(5, "Armin");
	list[5] = createElem(6, "Hange");
	list[6] = createElem(7, "Levi");
	list[7] = createElem(8, "Mikasa");
	list[8] = createElem(9, "Sasha");
	list[9] = createElem(10, "Erwin");

	printCharacterList(list, N);

	// need to free otherwise nobody does it
	freeList(list, N);

	return 0;
=======
typedef struct AttackOnTitanCharacter
{
    size_t id;
    char *name;
} AttackOnTitanCharacter;

AttackOnTitanCharacter* createElem(size_t id, char *name)
{
    // allocation happens here
    AttackOnTitanCharacter *p = malloc(sizeof(AttackOnTitanCharacter));
    p->id = id;
    p->name = name;
    return p;
}

void freeList(AttackOnTitanCharacter **list, size_t length)
{
    for (int i=0; i<length; i++)
        free(list[i]);

#ifndef ON_STACK
    free(list);
#endif
}

void printCharacterList(AttackOnTitanCharacter **list, size_t length)
{
    for(int i=0; i < length; i++)
        printf("id = %ld, name = %s\n", list[i]->id, list[i]->name);
}

void main()
{

#ifdef ON_STACK
    // allocating the list on the stack
    AttackOnTitanCharacter *list[N];
#else
    AttackOnTitanCharacter **list;
    // dynamically allocating the list
    list = malloc(N, sizeof(AttackOnTitanCharacter*));
#endif

    list[0] = createElem(1, "Eren");
    list[1] = createElem(2, "Zeke");
    list[2] = createElem(3, "Kenny");
    list[3] = createElem(4, "Reiner");
    list[4] = createElem(5, "Armin");
    list[5] = createElem(6, "Hange");
    list[6] = createElem(7, "Levi");
    list[7] = createElem(8, "Mikasa");
    list[8] = createElem(9, "Sasha");
    list[9] = createElem(10, "Erwin");

    printCharacterList(list, N);

    // need to free otherwise nobody does it
    freeList(list, N);
>>>>>>> noul3
}
