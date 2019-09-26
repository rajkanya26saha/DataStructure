
/*********************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 26-sept-2019		*/
/*Filename	: stack_linked_list.c	*/
/*Description	: source file for stack using linked list*/
/**********************************************************/

/* Included header files*/
#include "stack_linked_list.h"


/* Global variable definitions*/
struct stack_node *root=NULL;

/*main function definitions */
int main()
{
	int ch;
	while(1)
	{
		printf("1.push 2.pop 3.display 4.exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : push(&root);
				 break;
			case 2 : pop(&root);
				 break;
			case 3 : display(&root);
				 break;
			case 4 : exit(0);
		}
	}
	return 0;
}

void push(struct stack_node **root)
{
	struct stack_node *new_node;
	new_node=(struct stack_node*)malloc(sizeof(struct stack_node));
	printf("Push data for the new node : ");
	scanf("%d",&new_node->data);

		if((*root)==NULL)
		{
			new_node->next=NULL;
			*root=new_node;
			return;
		}
		new_node->next=*root;
		*root=new_node;
}

void pop(struct stack_node **root)
{
	struct stack_node *tmp;
	if(*root==NULL)
	{
		printf("Nothing is there to delete\n");
		return;
	}
	tmp=*root;
	*root=(*root)->next;
	if(*root==NULL)
	{
		free(tmp);
		printf("Stack is empty\n");
		return;
	}
	free(tmp);
}

void display(struct stack_node **root)
{
	struct stack_node *node=*root;
	if(node==NULL)
	{
		printf("Nothing is there to display\n");
		return;
	}
	while(node!=NULL)
	{
		printf("%d ",node->data);
		node=node->next;
	}
	printf("\n");
}

