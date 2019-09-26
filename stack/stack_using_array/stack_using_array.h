
/******************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 26-sept-2019		*/
/*Filename	: stack_using_array.h	*/
/*Description	: header files for stack using array*/
/******************************************************/

#ifndef STACK_USING_ARRAY_H
#define STACK_USING_ARRAY_H


/* Included header files */

#include<stdio.h>
#include<stdlib.h>

/* Macro Definitions */

#define MIN 0
#define MAX 5

/* user defined datatype definition */

struct stack_node
{
	int data[MAX];
	int top;
};

/* function prototypes */
	
	void push(void);
	void pop(void);
	void display(void);


#endif /*STACK_USING_ARRAY_H*/


