
/**********************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 26-sept-2019		*/
/*Filename	: queue_linked_list.c	*/
/*Description	: source file for queue using linked list*/
/**********************************************************/

/* Included header files */
#include "queue_linked_list.h"

/* Global variable definitions */
struct queue_node *front=NULL;
struct queue_node *rear=NULL;

/* main function definitions */
int main()
{
	int ch;
	while(1)
	{
		printf("1.enQueue 2.deQueue 3.display 4.exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	enQueue();
				break;
			case 2:	deQueue();
				break;
			case 3:	display();
				break;
			case 4:	exit(0);
		}
	}
	return 0;
}
void enQueue()
{
	struct queue_node *new_node=(struct queue_node*)malloc(sizeof(struct queue_node));
	printf("Enter data for the queue : ");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	if(rear==NULL)
	{
		front=rear=new_node;
	}
	else
	{
		rear->next=new_node;
		rear=new_node;
	}
}

void deQueue()
{
	struct queue_node *tmp;
	if(front==NULL)
	{
		printf("Queue is empty!!\n");
	}
	else
	{
		tmp=front;
		front=front->next;
		free(tmp);
	}
}

void display()
{
	struct queue_node *tmp;
	if(front==NULL)
	{
		printf("Queue is empty!!\n");
	}
	else
	{
		tmp=front;
		while(tmp!=NULL)
		{
			printf("%d ",tmp->data);
			tmp=tmp->next;
		}
		printf("\n");
	}
}


