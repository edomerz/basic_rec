#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************
*											 				 	 *
*					by Eyal Shahaf - RD14						 *
*																 *
*****************************************************************/

typedef struct stack_adt stack_t;

/* Initiates a stack with num_elements elements of element_size size in bytes */
stack_t *StackCreate(size_t element_size, size_t num_elements);
/* Frees allocated memory for the stack */
void StackDestroy(stack_t *stack);


/* Pushes a value to the top of the stack, the value has to conform to
								element_size that was declared at StackCreate */
int StackPush(stack_t *stack, void *value);
/* Pops the stack */
int StackPop(stack_t *stack);

/* Returns the address of the top value in the stack */
void *StackPeek(const stack_t *stack);
/* Returns the number of elements filled in the stack */
size_t StackSize(const stack_t *stack);

#endif /* __STACK_H__ */
