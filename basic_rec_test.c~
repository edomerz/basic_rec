#include <stdio.h>
#include <assert.h>

#include "basic_rec.h"

int Compere(const void *data1, const void *data2);	

int main(int argc, char* argv[], char** envp)
{

	int i = 0;
	int count = 20;
	char *s1 = "abcdefg";
	char *s2 = "g";
	size_t len1 = 0;
	size_t n = 3;
	char dest[20];

	node_t *node1 = NULL;
	node_t *node2 = NULL;
	node_t *node3 = NULL;
	node_t *node4 = NULL;
	node_t *node5 = NULL;
	
	char *t = NULL;	
	
	stack_t *stack = NULL;
	size_t n1 = 1;
	size_t n2 = 2;
	size_t n3 = 3;
	size_t n4 = 4;
	size_t n5 = 5;
	
	/*__________  RecFibonacci  __________*/
	printf("\n[%s %s %d]RecFibonacci\n", __FILE__, __func__, __LINE__);
	
	for (i = 0; i < count; ++i)
	{
		printf("RecFibonacci(%i):%i\n", i , RecFibonacci(i));
	}
	
	/*__________  RecStrlen  __________*/
	printf("\n[%s %s %d]RecStrlen\n", __FILE__, __func__, __LINE__);
	
	len1 = RecStrlen(s1);
	printf("len1:%lu\n", len1);
	
	/*__________  RecStrcmp  __________*/
	printf("\n[%s %s %d]RecStrcmp\n", __FILE__, __func__, __LINE__);
	
	printf("RecStrcmp(s1, s2): %i\n", RecStrcmp(s1, s2));
	
	
	/*__________  RecStrncmp  __________*/
	printf("\n[%s %s %d]RecStrncmp\n", __FILE__, __func__, __LINE__);
	
	printf("RecStrncmp(s1, s2, n): %i\n", RecStrncmp(s1, s2, n));


	/*__________  RecStrstr  __________*/
	printf("\n[%s %s %d]RecStrstr\n", __FILE__, __func__, __LINE__);
	
	printf("RecStrstr(s1, s2):%s\n", RecStrstr(s1, s2));
	
	/*__________  RecStrcpy  __________*/
	printf("\n[%s %s %d]RecStrcpy\n", __FILE__, __func__, __LINE__);
	t = RecStrcpy(dest, s1);
	printf("RecStrcpy(dest, s1):%s		expected result:%s\n", t, dest);
	
	
	/*__________  RecStrcat  __________*/
	printf("\n[%s %s %d]RecStrcat\n", __FILE__, __func__, __LINE__);
	
	printf("RecStrcat(dest, s1):%s		expected result:%s\n", 
			RecStrcat(dest, s1), 						"abcgefgabcdefg");
	
	/*__________  RecSlistFlip  __________*/
	printf("\n[%s %s %d]RecSListFlip\n", __FILE__, __func__, __LINE__);
	
	node5 = SListCreateNode((void*)5, NULL);
	node4 = SListCreateNode((void*)4, node5);
	node3 = SListCreateNode((void*)3, node4);
	node2 = SListCreateNode((void*)2, node3);
	node1 = SListCreateNode((void*)1, node2);
	
	printf("SListCount(node1):%lu\n", SListCount(node1));
	
	RecSListFlip(node1);
	
	printf("SListCount(node1):%lu\n", SListCount(node5));
	
	SListFreeAll(node5);
	
	/*__________  Compere  __________*/
	printf("\n[%s %s %d]Compere\n", __FILE__, __func__, __LINE__);
	
	printf("Compere(&n1, &n2):%i		expected result:1\n", Compere(&n1, &n2));
	
	printf("Compere(&n1, &n1):%i		expected result:1\n", Compere(&n1, &n2));
	
	printf("Compere(&n2, &n1):%i		expected result:0\n", Compere(&n2, &n1));
	/*_________________________  END Compere _______________________*/
	
	
	/*________________________________________________________________*/
	printf("\n[%s %s %d]RecStackSort\n", __FILE__, __func__, __LINE__);
	/*_________________________  RecStackSort  _______________________*/
	
	stack = StackCreate(sizeof(size_t), 5);
	assert(stack);
	
	StackPush(stack, &n3);
	StackPush(stack, &n2);
	StackPush(stack, &n5);
	StackPush(stack, &n4);
	StackPush(stack, &n1);

	RecStackSort(stack, &Compere, sizeof(size_t));
	
	for( ; StackSize(stack); StackPop(stack))
	{
		printf("StackPeek(stack):%lu\n", *(size_t*)StackPeek(stack));
	}
	
	StackDestroy(stack);	
	
	
	return(0);
}

int Compere(const void *data1, const void *data2)
{
	printf("\n[%s %s %d]\n", __FILE__, __func__, __LINE__); /* DEBUG !!! */
	return(*(size_t*)data1 <= *(size_t*)data2 ? 1 : 0);
}

