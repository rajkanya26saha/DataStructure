
/**********************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 26-sept-2019		*/
/*Filename	: queue_linked_list.h	*/
/*Description	: header files for queue using linked list*/
/**********************************************************/

#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H


/* Included header files */

#include<stdio.h>
#include<stdlib.h>

/* Macro Definitions */


/* user defined datatype definition */

struct queue_node
{
	int data;
	struct queue_node *next;
};

/* function prototypes */
	
void enQueue(void);
void deQueue(void);
void display(void);

#endif /*QUEUE_LINKED_LIST_H*/


