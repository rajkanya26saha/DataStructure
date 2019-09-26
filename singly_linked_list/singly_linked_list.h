
/******************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 26-sept-2019		*/
/*Filename	: singly_linked_list.h	*/
/*Description	: header files for singly linked list*/
/******************************************************/

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


/* Included header files */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Macro Definitions */

/* user defined datatype definition */

	struct Node
	{
	int data;
	struct Node *next;
	};

/* function prototypes */
	
	void add(void);
	void add_start(struct Node **head);
	void add_mid(struct Node **head);
	void add_end(struct Node **head);
	void delete(void);
	void del_start(struct Node **head);
	void del_mid(struct Node **head);
	void del_end(struct Node **head);
	void display(struct Node **node);


#endif /*SINGLY_LINKED_LIST_H*/


