#ifndef __INSTITUTION__
#define __INSTITUTION__

#include "LinkedList.h"
#include "Stack.h"

typedef enum {Unknown, University,UniversityCollege,College} InstitutionType;

typedef struct Institution_t
{
	char * name;
	char * address;
	unsigned long posecode;
	unsigned long int telephone;
	InstitutionType type;
	int yearEstablished;
	struct Institution_t  *next;
}Institution;

int Institution_reverse(LinkedList *inputList,Stack *elementStack, LinkedList *outputList);
int isUniversityCollege(void *elem1,void *type);
int Institution_select(LinkedList *inputList,
						LinkedList *outputList,
						void *criterion,
						int(*compare)(void *,void *));
#endif