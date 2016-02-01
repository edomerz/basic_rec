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
	if((!(*s1) || !(*s2)) || (*s1 != *s2))
	{
		return(*s1 - *s2);
	}
	
	return(RecStrcmp(s1 + 1, s2 + 1)); 
}

int RecStrncmp(const char *s1, const char *s2, size_t n)
{
	if(!(*s1) || !(*s2) || !n || (*s1 != *s2))
	{
		return(*s1 - *s2);
	}
	return(RecStrncmp(s1 + 1, s2 + 1, n - 1)): 
}

char *RecStrstr(const char *haystack, const char *needle)
{
	if(str == NULL)
	{
		return(NULL);
	}
	
	if(strncmp(haystack, needle, RecStrlen(needle)) == 0)
	{
		return(haystack);
	}
	else
	{
		return(RecStrstr(haystack + 1, needle));
	}
	
	
}

char *RecStrcpy(char *dest, const char *src);

char *RecStrcat(char *dest, const char *src);

/*
 * flips the order of nodes in a slingly linked list, so head would point to 
 * NULL, and the last node in the list would become its head.
 */
node_t *RecSListFlip(node_t *head);

/*void RecStackSort(stack_t *stack, int (*cmp)(const void *data1,const  void *data2))*/
