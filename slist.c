#include <assert.h>
#include <string.h>

#include "slist.h"

#define SWAPINT(x, y) { (*((size_t*)(&(x)))) += *(size_t*)&(y);\
 *(size_t*)&(y) = *(size_t*)&(x) - *(size_t*)&(y); *(size_t*)&(x) -= *(size_t*)&(y); } 
 
#define DIFF(x, y) (((x) >= (y)) ? ((x) - (y)) : ((y) - (x)))

/*prints the data field in list*/
void slistPrint(const node_t *head);
/* swaps the data fields between nodeA and nodeB */
void slAddData(void **data, void **param);

/*typedef int (*is_match_func)(const void *data, const void *seek);*/
/*typedef void (*action_func)(void *data, void *param);*/

/*creates a new node, and returns it's address. next -> NULL*/
node_t *SListCreateNode(void *data, node_t *next)
{
	node_t *node = NULL;
	if( !(node = (node_t*)malloc(sizeof(node_t))) )
	{
		return(NULL);
	}
	node->next = next;
	node->data = data;
	
	return(node);
}

/*free all nodes from "start_node" to end of list (noted by NULL)*/
void SListFreeAll(node_t *start_node)
{
	node_t* ptr = start_node;
	node_t* tmp = ptr;
	
	while(ptr)
	{
		ptr = ptr->next;
		free(tmp);
		tmp = ptr;
	}
}

/*inserts new_node before head. returns address of new_node*/
/*this invalidates the pointer to where*/
node_t* SListInsert(node_t *where, node_t *new_node)
{
	void *tmp = NULL;
	assert(where);
	
	/* cant change the pointer to WHERE, instded copied new_node data
	to WHERE*/
	tmp = where->data;
	where->data = new_node->data;
	new_node->data = tmp;
	
	new_node->next = where->next;
	where->next = new_node;
	
	return(where);
}

/*inserts new_node after where. returns address of new_node*/
node_t *SListInsertAfter(node_t *where, node_t *new_node)
{
	new_node->next = where->next;
	where->next = new_node;
	
	return(new_node);
}

/*removes current node. returns address of the removed node*/
/*can't remove last node, 
this invalidates any pointer to node*/
node_t *SListRemove(node_t *node)
{
	node_t *ret = NULL;
	
	assert(node);
	assert(node->next);
	
	if((ret = node->next))
	{
		SWAPINT(node->data, node->next->data); /* swap data fields */
		node->next = node->next->next;
	}
	
	return(ret);
}	


/*removes node AFTER current node. returns address of the removed node*/
/*if last node removed, return NULL*/
node_t *SListRemoveAfter(node_t *node)
{
	node_t *ret = node->next;
	assert(ret);
	
	node->next = node->next->next;	
	
	return(ret);	
}
/*count all nodes from "start_node" to end of list (noted by NULL)*/
size_t SListCount(const node_t *head)
{
	size_t count = 0;
	
	while(head)
	{
		printf("ptr address:%p	", (void*)head);    /* debug!!!!!!!!!!!!!!!!*/
		printf("node data:%i\n", *(int*)&head->data);
		++count;
		printf("count:%lu\n", count);				/* debug!!!!!!!!!!!!!!!!*/
		head = head->next;
	}
	
	return(count);
}

/*finds if data exists in list from HEAD to end, according to compare_func*/
/*at failure returns NULL*/
node_t *SListFind(node_t *head, is_match_func fp, const void *data)
{
	node_t *ptr = head;
	
	if (!ptr)									/* DEBUG!!!!!!!!!!!!!!!!!!! */
	{
		printf("file:%s		func:%s		line:%d\n", __FILE__, __func__, __LINE__); /* DEBUG!!!*/
		return(NULL);
	}
	
	while( (ptr) && (!(fp(ptr->data, data))) )
	{
		ptr = ptr->next;
	}	
	if(!ptr)
	{
		return(NULL);
	}
	
	return(ptr);
}

/*permorms an operation on each of nodes from "start_node", according to operation_func*/
void SListForEach(node_t *head, action_func fp, void *param)
{
	node_t *ptr = head;
	assert(ptr);/* DEBUG!!!!!!!!!!!!!!!!!!! */
	
	while(ptr)
	{
		fp(&ptr->data, &param);
		ptr = ptr->next;
	}
	
	return;
}

/* reverse the order of the nodes, return the new head OR NULL for no flip */
node_t *SListFlip(node_t *head)
{
/*	node_t *current = NULL;*/
/*	node_t *next = NULL;*/
	size_t len = 0;
/*	size_t len_in = 0;*/
	
	if((!head) || (!head->next))
	{
		return(NULL);
	} 
	
	len = SListCount(head);
	
	while(--len)
	{
		node_t* prev = NULL;
		node_t* current = head;
		node_t* next = NULL;
		
		assert(head);
		
		while(current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		
		return(prev);
		
/*		len_in = len;*/
/*		current = head;*/
/*		next = head->next;*/
/*		*/
/*		while(len_in--)*/
/*		{*/
/*			SWAPINT(current->data, next->data);*/
/*			current = next;*/
/*			next = current->next;*/
/*			*/
/*		}*/
/*	}*/
/*	return(head);*/
	}
	return(head);
}

/* return 0 for no loop, 1 for has loop */
int SListHasLoop(const node_t *head)
{
	node_t *slow, *fast1, *fast2 = (node_t*)head;
	fast1 = fast2;
	slow = fast1;

	while( (slow) && (fast1 = fast2->next) && (fast2 = fast1->next) )
	{
		if((slow == fast1) || (slow == fast2))
		{
			return(1);
		}
		slow = slow->next;
	} 
	
	return(0);
}

/* 	gets 2 lists and searches for shared node , 
	returns the shared node, or NULL */
node_t *SListFindIntersection(const node_t *head1, const node_t *head2)
{
	node_t *h1 = (node_t*)head1;
	node_t *h2 = (node_t*)head2;
	
	size_t len1 = SListCount(head1);
	size_t len2 = SListCount(head2);
	size_t diff = DIFF(len1, len2);
	size_t i = 0;

	if(len1 > len2)
	{
		for( ; i < diff; ++i) 
		{
			if(!h1)
			{
				return(NULL); 
			}
			h1 = h1->next;
		}	
	}
	else if(len2 > len1)
	{
		for( ; i < diff; ++i)
		{
			if(!h2)
			{
				return(NULL);
			}
			h2 = h2->next;
		}
	}
	
	while(h1 && h2)
	{
		if(h1 == h2)
		{
			return(h1);
		}
		h1 = h1->next;
		h2 = h2->next;
	}	
	
	return(NULL);
}




/* prints the data field in node as size_t) */
void slistPrint(const node_t *head)/* DEBUG!!!!!!!!!!!!!!!!!!! */
{
	node_t *ptr = (node_t*)head;
	size_t count = 0;
	
	if(! ptr)
	{
		return;
	}
	
	while(ptr)
	{
		printf("\nnode%lu:	data:%lu  address:%p\n", count, (size_t)ptr->data, (void*)ptr);
		ptr = ptr->next;
		++count;
	}
	
}
/*adds the data fields and put it in dataA */
void slAddData(void **dataA, void **dataB)/* DEBUG!!!!!!!!!!!!!!!!!!! */
{
	if(dataA && dataB)
	{	
		*(*(size_t**)&dataA) = *(*(size_t**)&dataA) + *(*(size_t**)&dataB);
		printf("sum is:%lu\n", (size_t)(*dataA));
/*		*(*(size_t**)&dataB) = *(*(size_t**)&dataA) - *(*(size_t**)&dataB);*/
/*		*(*(size_t**)&dataA) = *(*(size_t**)&dataA) - *(*(size_t**)&dataB);*/
/*		void* tmp = dataA;*/
/*		dataA = dataB;*/
/*		dataB = tmp;*/
	}
}

