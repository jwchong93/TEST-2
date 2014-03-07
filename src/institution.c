#include "institution.h"
#include <stdio.h>

int Institution_reverse(LinkedList *inputList,Stack *elementStack, LinkedList *outputList)
{
	Institution * tempElement;
	
	if(inputList->head==NULL)
	{
		return 0;
	}
	tempElement = List_removeHead(inputList);
	while(tempElement !=NULL)
	{
		Stack_push(elementStack,tempElement);
		tempElement = List_removeHead(inputList);
	}

	tempElement = Stack_pop(elementStack);	
	do
	{
		List_addTail(outputList,tempElement);
		tempElement = Stack_pop(elementStack);
	}while(tempElement!=NULL);

	
	return 1;
	
}

int Institution_select(LinkedList *inputList,LinkedList *outputList,void *criterion,int(*compare)(void *,void *))
{
	int i =0;
	Institution * tempElement;
	int status;
	if(inputList->head==NULL)
	{
		return 0;
	}
	tempElement = List_removeHead(inputList);
	while(tempElement != NULL)
	{
		if(compare(tempElement,criterion))
		{
			List_addTail(outputList,tempElement);
		}
		tempElement = List_removeHead(inputList);
	}
	
	
}


int isUniversityCollege(void *elem1,void *type)
{
	InstitutionType *tempType = (InstitutionType*)type;
	Institution *tempInstitution = (Institution*) elem1;
	if(tempInstitution->type == (*tempType))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int wasEstablishedBefore(void *elem1,void *year)
{
	Institution *element1=(Institution*)elem1;
	int *referenceYear = (int*)year; 
	if(element1->yearEstablished==*referenceYear)
	{
		return 1;
	}
	return 0;
}