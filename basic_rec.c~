#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

#include "basic_rec.h"
	
int RecFibonacci(int n)
{
	if(n == 0 || n == 1)
	{
		return(1);
	}
	
	return(RecFibonacci(n - 1) + RecFibonacci(n - 2));
}


size_t RecStrlen(const char *s)
{
	if(!(*s))
	{
		return(0);
	}
	
	return(1 + RecStrlen(s + 1));
}

int RecStrcmp(const char *s1, const char *s2)
{
	if((*s1 != *s2) || !(*s1))
	{
		return(*s1 - *s2);
	}
	
	return(RecStrcmp(s1 + 1, s2 + 1)); 
}

int RecStrncmp(const char *s1, const char *s2, size_t n)
{
	if(!(*s1) || !(*s2) || (n <= 1) || (*s1 != *s2))
	{
		return(*s1 - *s2);
	}
	return(RecStrncmp(s1 + 1, s2 + 1, n - 1)); 
}

char *RecStrstr(const char *haystack, const char *needle)
{
	if(haystack == NULL)
	{
		return(NULL);
	}
	
	if(!(*haystack))
	{
		return(NULL);
	}
	
	if(RecStrncmp(haystack, needle, RecStrlen(needle)) == 0)
	{
		return((char*)haystack);
	}
	else
	{
		return(RecStrstr(haystack + 1, needle));
	}
	
	
}

char *RecStrcpy(char *dest, const char *src)
{
	if(!dest || !src)
	{
		return(NULL);
	}
	
	if(!*src)
	{
		*dest = *src;
		
		return(dest);
	}
	
	*dest = *src;
	
	return(RecStrcpy(dest + 1, src + 1) - 1);
	
/*	return(dest);*/
	
}

char *RecStrcat(char *dest, const char *src)
{
	size_t dest_len = RecStrlen(dest);
	
	assert(dest);
	assert(src);
	
	if(!*src)
	{
		*(dest + dest_len) = *src;
		
		return(dest);
	}
	
	*(dest + dest_len) = *src;
	
	return(RecStrcat(dest + 1, src + 1) - 1);
	
}

/*
 * flips the order of nodes in a slingly linked list, so head would point to 
 * NULL, and the last node in the list would become its head.
 */
node_t *RecSListFlip(node_t *head)
{
	node_t *first = NULL;
	node_t *rest = NULL;
	
/*	empty list*/
	if(!head)
	{
		return(NULL);
	}
	
	first = head;
	rest = head->next;
	
/*	only 1 node	*/
	if(!rest)
	{
		return(NULL);
	}
	
	RecSListFlip(rest); /* update rest */
	
	first->next->next = first; /* switch direction between last 2 nodes */ 
	first->next = NULL;		   /* */
	
	return(rest);
}

static void RecSort(stack_t *stack, 
				    int (*cmp)(const void *data1,const  void *data2),
				    size_t elem_size,
				    void *tmp)
{
	void *tmp2 = malloc(elem_size);
	assert(tmp2);
	
	printf("\n[%s %s %d]\n", __FILE__, __func__, __LINE__); /* DEBUG !!! */
	
	printf("tmp:%lu\tn", *(size_t*)tmp);
	
	printf("StackPeek(stack):%lu\n", *(size_t*)StackPeek(stack));
	
	
  	if((!(StackSize(stack))) || (cmp(tmp, StackPeek(stack))) ) /* tmp is larger then head of stack, do nothing */
  	{
		StackPush(stack, tmp);
		
  		return;
  	}

	memmove(tmp2, (void*)StackPeek(stack), elem_size);
	
	StackPop(stack);
		
	RecSort(stack, cmp, elem_size, tmp);
		
/*	StackPush(stack, tmp);*/
	StackPush(stack, tmp2);
	
		
		
	free(tmp2);
	
	return;
}

/* sorts the stack recursively*/
void RecStackSort(stack_t *stack, 
			      int (*cmp)(const void *data1,const  void *data2), 
			      size_t elem_size)
{
	void *tmp = malloc(elem_size);
	assert(tmp);
	assert(cmp);
	
	printf("StackSize(stack):%lu\n", StackSize(stack));
	
	if(StackSize(stack) == 1)
	{
/*		RecSort(stack, elem_size);*/
/*		printf("one element left\n");*/
		
/*		printf("tmp:%lu\n", *(size_t*)tmp);*/
		
		return;
	}
	
	
	memmove(tmp, (void*)StackPeek(stack), elem_size);
	
	StackPop(stack);
	
	RecStackSort(stack, cmp, elem_size);
	
	RecSort(stack, cmp, elem_size, tmp);
	
	
	free(tmp);
	
	return;
}
