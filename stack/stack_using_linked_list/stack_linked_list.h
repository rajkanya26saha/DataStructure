
/*********************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 26-sept-2019		*/
/*Filename	: stack_linked_list.h	*/
/*Description	: header files for stack using linked list*/
/**********************************************************/

#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H


/* Included header files */

#include<stdio.h>
#include<stdlib.h>

/* Macro Definitions */


/* user defined datatype definition */

struct stack_node
{
	int data;
	struct stack_node *next;
};

/* function prototypes */
	
void push(struct stack_node **root)
void pop(struct stack_node **root)
void display(struct stack_node **root)


#endif /*STACK_LINKED_LIST_H*/


