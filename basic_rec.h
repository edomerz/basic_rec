/*
	basic_rec
*/
	
#ifndef __BASIC_REC_H__
#define __BASIC_REC_H__

#include <stdio.h>

#include "slist.h"
#include "stack.h"

int RecFibonacci(int n);

size_t RecStrlen(const char *s);

int RecStrcmp(const char *s1, const char *s2);

int RecStrncmp(const char *s1, const char *s2, size_t n);

char *RecStrstr(const char *haystack, const char *needle);

char *RecStrcpy(char *dest, const char *src);


char *RecStrcat(char *dest, const char *src);

/*
 * flips the order of nodes in a slingly linked list, so head would point to 
 * NULL, and the last node in the list would become its head.
   singly linked list
 */
node_t *RecSListFlip(node_t *head);

void RecStackSort(stack_t *stack, 
				  int (*cmp)(const void *data1, const  void *data2), 
				  size_t elem_size);

	
#endif /* ifndef __BASIC_REC_H__*/
