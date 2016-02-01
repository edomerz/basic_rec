#include "stack.h"

/*****************************************************************
*																 *
*					by Eyal Shahaf - RD14						 *
*																 *
*****************************************************************/
struct stack_adt			
{
	void *top;					/* pointer to top of Stack */
	void *end;					/* pointer to end of data block */
	size_t elem_size;			/* element size in bytes */
	
	size_t head[1];				/* pointer to start of data block */
};

/* Initiates a stack with num_elements elements of element_size size in bytes */
stack_t *StackCreate(size_t element_size, size_t num_elements)
{
	stack_t *newStruct = NULL;
	if(!(newStruct = malloc(sizeof(stack_t) + 
							(element_size * num_elements) - sizeof(size_t))))
	{
		fprintf(stderr, "Malloc of Struct in StackCreate failed!\n");
		return (NULL);
	}
	
	(newStruct->elem_size) = element_size;
	(newStruct->top) = &(newStruct->head);
	(newStruct->end) = (char *)(newStruct->top) + (num_elements * element_size);
		 
	return (newStruct);
}

/* Frees allocated memory for the stack */
void StackDestroy(stack_t *stack)
{
	free(stack);
	return;
}

/* Pushes a value to the top of the stack, the value has to conform to
								element_size that was declared at StackCreate */
int StackPush(stack_t *stack, void *value)
{
	/* Don't push if stack is full */
	if((char *)(stack->top) < (char *)(stack->end))
	{
		memmove((char *)(stack->top), value, (stack->elem_size));
		(stack->top) = ((char *)(stack->top) + (stack->elem_size));
		return (1);
	}
	return (0);
}

/* Pops the stack */
int StackPop(stack_t *stack)
{
	/* Don't pop if stack is empty */
	if((char *)(stack->top) > (char *)(stack->head))
	{
		(stack->top) = ((char *)(stack->top) - (stack->elem_size));
		return (1);
	}
	return (0);
}	

/* Returns the address of the top value in the stack */
void *StackPeek(const stack_t *stack)
{
	return ((char *)(stack->top) - (stack->elem_size));
}	

/* Returns the number of elements filled in the stack */
size_t StackSize(const stack_t *stack)
{
	return
		 (((char *)(stack->top) - (char *)&(stack->head)) / (stack->elem_size));
}




