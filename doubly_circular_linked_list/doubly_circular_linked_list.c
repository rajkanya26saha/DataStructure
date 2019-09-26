
/**************************************************************/
/*Author	: Rajkanya Saha*/
/*Date		: 26-sept-2019*/
/*Filename	: doubly_circular_linked_list.c*/
/*Description	: source code for doubly circular linked list*/
/*************************************************************/

/* Included header files*/
#include "singly_linked_list.h"

/*Global variable definitions */
struct Node *head=NULL,*end=NULL;
int count=0;

/*main function definition*/
int main()
{
	/*function to add entry to the list at the start,middle and end position*/
	add(); 
	/*function to remove entry to the list at the start,middle and end position*/
	delete(); 
	printf("Created list is\n");
	/*fuction to display the list(from head to tail)*/
	display(&head); 
	return 0;
}

void add()
{
	int ch;
	char str[10];
	while(1)
	{
		printf("1.add at start 2.add at mid 3.add at end 4.add not");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			/*function to add entry to the list from the start positon of the list*/
			case 1:add_start(&head);
			       break;
			       /*function to add entry to the list from any mid  positon of the list*/
			case 2:add_mid(&head);
			       break;
			       /*function to add entry to the list from the end positon of the list*/
			case 3:add_end(&head);
			       break;
			case 4:break;
		}
		getchar();
		printf("Do you want to add  : yes or no \n");
		gets(str);
		if((strcmp(str,"yes"))==0)
			continue;
		else
			break;
	}
}

void add_start(struct Node **head)
{ 	
	struct Node *new_node;
	/*Allocating memory for the new node dynamically*/
	new_node=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the new data: ");
	/*scaning data for the new node*/
	scanf("%d",&new_node->data);
	if(*head==NULL)
	{
		end=new_node;
		new_node->prev=(*head);
		new_node->next=(*head);
		(*head)=new_node;
		count++;
		return;
	}
	new_node->prev=end;
	new_node->next=(*head);
	(*head)->prev=new_node;
	end->next=new_node;
	(*head)=new_node;
	count++;
}

void add_mid(struct Node **head)
{
	int pos;
	/*tmp is used for traversing till previous node postion of the scanned position node*/
	struct Node *tmp;
	struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
	if(count<2)
	{
	printf("Invalid option..Try Again!!\n");
	return;
	}
	while(1)
	{
	printf("Enter the mid postion : ");
	scanf("%d",&pos);
	if(count>pos)
	{
	printf("Enter the new data : ");
	scanf("%d",&new_node->data);

	/*Traversing the position to add entry according to the scanned position*/
	pos=pos-2;
	/*Making tmp to point to the start of the node i.e.head*/
	tmp=*head;
	while(pos)
	{
		/*Traversing till the previous node of the current position node*/
		tmp=tmp->next;
		pos--;
	}
	/*Making next of new node as next of previous node to make connection from new node to other node in right side*/

	new_node->next=tmp->next;
	(tmp->next)->prev=new_node;
	/*Making tmp->next to point to the new node,so new node got connected with previous node in left side*/
	tmp->next=new_node;
	new_node->prev=tmp;
	count++;
	break;
	}
	else
	{
	printf("Invalid mid position..Try again!!\n");
	continue;
	}
	}
}

void add_end(struct Node **head)
{
	struct Node *last=*head;
	struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
	if(last==NULL)
	{
	printf("Invalid option... Try again!!\n");
	return;
	}
	printf("Enter the new data: ");
	scanf("%d",&new_node->data);

	if((*head)->next==(*head)->prev)
	{
		new_node->next=(*head);
		(*head)->prev=new_node;
		(*head)->next=new_node;
		new_node->prev=*head;
		count++;
		return;
	}

	/*Traversing till the last node in the list*/
	while(last->next!=(*head))
	{
		last=last->next;
	}
	new_node->next=last->next;
	/*Change the next of last node to new node*/
	last->next=new_node;
	new_node->prev=last;
	(*head)->prev=new_node;
	count++;
}

void delete()
{
	int ch;
	char str[10];
	while(1)
	{
		printf("1.delete at start 2.delete at mid 3.delete at end 4.delete not");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			/*function to delete start position entry from the list*/
			case 1:del_start(&head);
			       break;
			       /*function to delete any mid position entry from the list*/
			case 2:del_mid(&head);
			       break;
			       /*function to delete end position entry from the list*/
			case 3:del_end(&head);
			       break;
		}
		getchar();
		printf("Do you want to delete : yes or no \n");
		gets(str);
		if((strcmp(str,"yes"))==0)

			continue;
		else
			break;
	}
}

void del_start(struct Node **head)
{
	/*Making tmp to point to head*/
	struct Node *last,*tmp;
	last=tmp=*head;
	if(*head==NULL)
	{
	printf("No nodes in the list to delete\n");
	return;
	}
	if((*head)->prev==*head)
	{
		*head=NULL;
		free(tmp);
		count--;
		return;
	}
	while(last->next!=*head)
	{
		last=last->next;
	}
	(tmp->next)->prev=tmp->prev;
	last->next=tmp->next;
	/*Traversing start of the node i.e.head to the next node*/
	*head=(*head)->next;
	/*Unlink the previous start node from linked list*/
	free(tmp);
	count--;
}

void del_mid(struct Node **head)
{
	int pos;
	/*prev is used to indicate the previous node of the deleting node*/
	struct Node *tmp;
	tmp=*head;
	if(count>2)
	{
		while(1)
		{
	printf("Enter the mid postion which you want to delete : ");
	scanf("%d",&pos);
	if((count>pos)&&(pos>1))
	{
		/*Traversing position to delete entry according to the scanned position*/
		pos=pos-1;
		while(pos)
		{
			/*Traversing till the node to delete*/
			tmp=tmp->next;	
			pos--;
		}
		(tmp->prev)->next=tmp->next;
		(tmp->next)->prev=tmp->prev;
		/*Unlink the desired mid  node*/
		free(tmp);
		count--;
		break;
	}	
	else
	{
	printf("Invalid mid position.. Try Again!\n");
	continue;
	}
		}
	}
	else
	{
	printf("Invalid option..Try Again!\n");
	return;
	}
}

void del_end(struct Node **head)
{
	/*last is used to indicate last node of the list,tmp is used as previous node of the last node of the list*/
	struct Node *last;
	last=*head;
	if(count<2)
	{
	printf("Invalid option..Try Again!\n");
	return;
	}
	while(last->next!=*head)
	{
		/*Traversing the node till the last node of the list */
		last=last->next;
	}
	(last->prev)->next=*head;
	(*head)->prev=last->prev;
	/*Unlink the previous end node*/
	free(last);
	count--;
}

void display(struct Node **head)
{
	struct Node *node=*head;
	struct Node *start=node;
	if(node==NULL)
	{
		printf("No nodes in list\n");
		return;
	}
	printf("%d ",node->data);
	node=node->next;
	/*Traversing till it reaches to the last node in the list*/
	while(node!=start)
	{
		printf("%d ",node->data);
		node=node->next;
	}
	printf("\n");
}


