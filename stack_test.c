#include "stack.h"
	
int main(int argc, char* argv[], char** envp)
{
	size_t element_size = 0;
	size_t num_elements = 0;
	stack_t* s = NULL;
	void* ptr= NULL;
	int int_var = 11;
	int i = 0;

	if(argc != 3)
	{
		printf("Usage:./stack (uint64)element_size 	(uint64)num_elements\n");
		return(-1);
	}
	
	element_size = atol(argv[1]);
	num_elements = atol(argv[2]);
	printf("element_size:%lu		num_elements:%lu\n", element_size, num_elements);

	s = StackCreate(element_size, num_elements);

	ptr = StackPeep(s);
	printf("StackPeep:%p\n", ptr);

	printf("pop:%d\n", StackPop(s));

	for(; i < int_var; ++i)
	{
		StackPush(s, &i);
	}
	printf("push:%d\n", StackPush(s, &int_var));

	ptr = StackPeep(s);
	printf("StackPeep:%p\n", ptr);

	printf("pop:%d\n", StackPop(s));

	ptr = StackPeep(s);
	printf("StackPeep:%p\n", ptr);

	StackDestroy(s);
	
	return(0);
}
/* Makes a stadk adt stack_t and return a pointer to it 
stack_t* StackCreate(size_t element_size, size_t num_elements);

destroy a stack adt 
void StackDestroy(stack_t* stack);

removes the top element in the stack 
int StackPop(stack_t* s);

adds a new_element to the top of the stack 
int StackPush(stack_t* stack, void* new_element);


 returns the address of the top element 
void* StackPeep(const stack_t* stack);

 return the number of elements in the stack 
size_t StackSize(const stack_t* stack);*/
