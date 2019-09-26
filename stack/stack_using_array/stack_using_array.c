
/******************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 26-sept-2019		*/
/*Filename	: stack_using_array.c	*/
/*Description	: source file for stack using array*/
/******************************************************/

/* Included header files */
#include "stack_using_array.h"

/* Global variable definitions */
struct stack_node s;

/*main function definition*/
int main()
{
	int ch;
	s.top=-1;
	while(1)
	{
		//init();
		printf("1.push 2.pop 3.display 4.exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : push();
				 break;
			case 2 : pop();
				 break;
			case 3 : display();
				 break;
			case 4 : exit(0);
		}
	}
	return 0;
}
void push()
{
	if(s.top >= MAX-1)
	{
		printf("Stack is full\n");
		return;
	}
	else
	{
		s.top++;
	printf("Push data into the stack : ");
	scanf("%d",&s.data[s.top]);
	}
}

void pop()
{
		if(s.top==-1)
		{
		printf("Stack is empty\n");
		return;
		}
		s.top--;
}

void display()
{
int top1=s.top;
	if(s.top==-1)
	{
		printf("Nothing is there to display\n");
		return;
	}
	while(top1>=0)
	{
		printf("%d ",s.data[top1]);
		top1--;
	}
	printf("\n");
}


