#include "unity.h"
#include "institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"
#include <malloc.h>

void setUp(){}
void tearDown(){}

void test_Insitution_reverse_will_reverse_the_order_of_the_input_Linkedlist()
{

	int determinder;
	LinkedList * testList1 = malloc(sizeof(LinkedList));
	LinkedList * testList2 = malloc(sizeof(LinkedList));
	testList1->head=testList1->tail= NULL;
	
	Institution *element1 = malloc(sizeof(Institution));
	Institution *element2 = malloc(sizeof(Institution));
	Institution *element3 = malloc(sizeof(Institution));
	Institution *element4 = malloc(sizeof(Institution));
	
	Stack *testStack;
	
	//Since the input list is empty, this function will return a 0.
	determinder=Institution_reverse(testList1,testStack,testList1);
	TEST_ASSERT_EQUAL(0,determinder);
	
	//Add element 1 & 2 into the list and try to reverse it.
	testList1->head = element1;
	element1->next = element2;
	element2->next=NULL;
	testList1->tail = element2;
	

	//Function mocking
	List_removeHead_ExpectAndReturn(testList1,element1);
	Stack_push_Expect(testStack,element1);
	List_removeHead_ExpectAndReturn(testList1,element2);
	Stack_push_Expect(testStack,element2);
	List_removeHead_ExpectAndReturn(testList1,NULL);

	testStack->topOfStack=element2;
	element2->next=element1;
	element1->next=NULL;
	
	Stack_pop_ExpectAndReturn(testStack,element2);
	List_addTail_Expect(testList2,element2);
	Stack_pop_ExpectAndReturn(testStack,element1);
	List_addTail_Expect(testList2,element1);
	Stack_pop_ExpectAndReturn(testStack,NULL);
	
	determinder=Institution_reverse(testList1,testStack,testList2);
	TEST_ASSERT_EQUAL(1,determinder);
	
	
	//Add element 1 ,2&3 into the list and try to reverse it.
	testList1->head = element1;
	element1->next = element2;
	element2->next=element3;
	element3->next=NULL;
	

	//Function mocking
	List_removeHead_ExpectAndReturn(testList1,element1);
	Stack_push_Expect(testStack,element1);
	List_removeHead_ExpectAndReturn(testList1,element2);
	Stack_push_Expect(testStack,element2);
	List_removeHead_ExpectAndReturn(testList1,element3);
	Stack_push_Expect(testStack,element3);
	List_removeHead_ExpectAndReturn(testList1,NULL);

	testStack->topOfStack=element3;
	element3->next=element2;
	element2->next=element1;
	element1->next=NULL;
	
	Stack_pop_ExpectAndReturn(testStack,element3);
	List_addTail_Expect(testList2,element3);
	Stack_pop_ExpectAndReturn(testStack,element2);
	List_addTail_Expect(testList2,element2);
	Stack_pop_ExpectAndReturn(testStack,element1);
	List_addTail_Expect(testList2,element1);
	Stack_pop_ExpectAndReturn(testStack,NULL);
	
	determinder=Institution_reverse(testList1,testStack,testList2);
	TEST_ASSERT_EQUAL(1,determinder);
	
	
	//Add element 1,2,3&4 into the list and try to reverse it.
	testList1->head = element1;
	element1->next = element2;
	element2->next=element3;
	element3->next=element4;
	element4->next=NULL;
	

	//Function mocking
	List_removeHead_ExpectAndReturn(testList1,element1);
	Stack_push_Expect(testStack,element1);
	List_removeHead_ExpectAndReturn(testList1,element2);
	Stack_push_Expect(testStack,element2);
	List_removeHead_ExpectAndReturn(testList1,element3);
	Stack_push_Expect(testStack,element3);
	List_removeHead_ExpectAndReturn(testList1,element4);
	Stack_push_Expect(testStack,element4);
	List_removeHead_ExpectAndReturn(testList1,NULL);

	testStack->topOfStack=element3;
	element3->next=element2;
	element2->next=element1;
	element1->next=NULL;
	
	
	Stack_pop_ExpectAndReturn(testStack,element4);
	List_addTail_Expect(testList2,element4);
	Stack_pop_ExpectAndReturn(testStack,element3);
	List_addTail_Expect(testList2,element3);
	Stack_pop_ExpectAndReturn(testStack,element2);
	List_addTail_Expect(testList2,element2);
	Stack_pop_ExpectAndReturn(testStack,element1);
	List_addTail_Expect(testList2,element1);
	Stack_pop_ExpectAndReturn(testStack,NULL);
	
	determinder=Institution_reverse(testList1,testStack,testList2);
	TEST_ASSERT_EQUAL(1,determinder);
	free(element1);
	free(element2);
	free(element3);
	free(element4);
	free(testList1);
	free(testList2);
}

void test_Institution_select_will_filter_out_specific_type()
{
	LinkedList * testList1 = malloc(sizeof(LinkedList));
	LinkedList * testList2 = malloc(sizeof(LinkedList));
	testList1->head=testList1->tail= NULL;
	
	Institution *element1 = malloc(sizeof(Institution));
	Institution *element2 = malloc(sizeof(Institution));
	Institution *element3 = malloc(sizeof(Institution));
	Institution *element4 = malloc(sizeof(Institution));
	
	element1->type=UniversityCollege;
	element2->type=College;
	element3->type=University;
	element4->type=College;
	
	//Try work with two elements.
	testList1->head = element1;
	element1->next = element2;
	element2->next =NULL;
	
	InstitutionType type =College;
	
	List_removeHead_ExpectAndReturn(testList1,element1);
	List_removeHead_ExpectAndReturn(testList1,element2);
	List_addTail_Expect(testList2,element2);
	List_removeHead_ExpectAndReturn(testList1,NULL);

	
	Institution_select(testList1,testList2,&type,isUniversityCollege);
	
	
	//Increase the element to three.
	
	testList1->head = element1;
	element1->next = element2;
	element2->next = element3;
	element3->next = NULL;
	
	
	List_removeHead_ExpectAndReturn(testList1,element1);
	List_removeHead_ExpectAndReturn(testList1,element2);
	List_addTail_Expect(testList2,element2);
	List_removeHead_ExpectAndReturn(testList1,element3);
	List_removeHead_ExpectAndReturn(testList1,NULL);

	
	Institution_select(testList1,testList2,&type,isUniversityCollege);
	
	
	//Increase to four.
	
		//Increase the element to three.
	
	testList1->head = element1;
	element1->next = element2;
	element2->next = element3;
	element3->next = element4;
	element4->next=NULL;
	
	
	List_removeHead_ExpectAndReturn(testList1,element1);
	List_removeHead_ExpectAndReturn(testList1,element2);
	List_addTail_Expect(testList2,element2);
	List_removeHead_ExpectAndReturn(testList1,element3);
	List_removeHead_ExpectAndReturn(testList1,element4);
	List_addTail_Expect(testList2,element4);
	List_removeHead_ExpectAndReturn(testList1,NULL);

	
	Institution_select(testList1,testList2,&type,isUniversityCollege);
	free(element1);
	free(element2);
	free(element3);
	free(element4);
	free(testList1);
	free(testList2);
}


void test_isUniversityCollege_will_return_according_to_the_input_parameters()
{
	Institution *element1 = malloc(sizeof(Institution));
	InstitutionType tempType = University;
	element1->type=College;
	int status;
	status = isUniversityCollege(element1,&tempType);
	TEST_ASSERT_EQUAL(0,status);
	
	
	tempType = College;
	status = isUniversityCollege(element1,&tempType);
	TEST_ASSERT_EQUAL(1,status);
	free(element1);
	
	
}