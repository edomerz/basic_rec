#ifndef __SLIST_H__
#define __SLIST_H__

#include <stdio.h>
#include <stdlib.h>


typedef struct slist_node 
{
	void *data;
	struct slist_node *next;
}node_t;

/* function pointer declartions */
typedef int (*is_match_func)(const void *data, const void *seek);
typedef void (*action_func)(void *dataA, void *dataB);


/*creates a new node, and returns it's address. next -> NULL*/
node_t *SListCreateNode(void *data, node_t *next);

/*free all nodes from "start_node" to end of list (noted by NULL)*/
void SListFreeAll(node_t *start_node);

/*inserts new_node before head. returns address of new_node*/
/*this invalidates the pointer to where*/
node_t *SListInsert(node_t *where, node_t *new_node);

/*inserts new_node after head. returns address of new_node*/
node_t *SListInsertAfter(node_t *where, node_t *new_node);

/*removes current node. returns address of the current node*/
/*can't remove last node, this invalidates the pointer to node*/
node_t *SListRemove(node_t *node);

/*removes node AFTER current node. returns address of the current node*/
/*if last node removed, return NULL*/
node_t *SListRemoveAfter(node_t *node);

/*count all nodes from "start_node" to end of list (noted by NULL)*/
size_t SListCount(const node_t *head);

/*finds id data exits in list from "start_node" to end, according to compare_func*/
/*at failure returns NULL*/
node_t *SListFind(node_t *head, is_match_func fp, const void *data);

/*permorms an operation on each of nodes from "start_node", according to operation_func*/
void SListForEach(node_t *head, action_func fp, void *param);

/* reverse the order of the nodes, return the new head */
node_t *SListFlip(node_t *head);

/* return 0 for no loop, 1 for has loop */
int SListHasLoop(const node_t *head);

/* 	gets 2 lists and searches for shared node , 
	returns the shared node, or NULL */
node_t *SListFindIntersection(const node_t *head1, const node_t *head2);

#endif /* ifndef __SLIST_H__*/
