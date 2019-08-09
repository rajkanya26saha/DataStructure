//Singly linked list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int data;
	struct Node *next;
};
struct Node *head=NULL;

void display(struct Node **node)
{
	if(*node==NULL)
	{
		printf("No nodes in list\n");
		return;
	}
	while(*node!=NULL)
	{
		printf("%d ",(*node)->data);
		*node=(*node)->next;
	}
	printf("\n");
}

void add_end(struct Node **head)
{
	struct Node *last=*head;
	struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the new data: ");
	scanf("%d",&new_node->data);
	/*Assigning NULL as the new node is going to be the last node*/
	new_node->next=NULL;

	/*Traversing till the last node in the list*/
	while(last->next!=NULL)
	{
		last=last->next;
	}
	/*Change the next of last node to new node*/
	last->next=new_node;
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
		(*head)=new_node;
		new_node->next=NULL;
		return;
	}
	/*making next of new node as head*/
	new_node->next=(*head);
	/*moving the head to point to the new node*/
	(*head)=new_node;
}

void add_mid(struct Node **head)
{
	int pos;
	/*tmp is used for traversing till previous node postion of the scanned position node*/
	struct Node *tmp;
	struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter the mid postion : ");
	scanf("%d",&pos);
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
	/*Making tmp->next to point to the new node,so new node got connected with previous node in left side*/
	tmp->next=new_node;
}

void del_start(struct Node **head)
{
	/*Making tmp to point to head*/
	struct Node *tmp=*head;
	/*Traversing start of the node i.e.head to the next node*/
	*head=(*head)->next;
	/*Unlink the previous start node from linked list*/
	free(tmp);
}

void del_mid(struct Node **head)
{
	int pos;
	/*prev is used to indicate the previous node of the deleting node*/
	struct Node *tmp,*prev;
	tmp=prev=*head;
	printf("Enter the mid postion which you want to delete : ");
	scanf("%d",&pos);
	if(pos>1)
	{
		/*Traversing position to delete entry according to the scanned position*/
		pos=pos-1;
		while(pos)
		{
			prev=tmp;
			/*Traversing till the node to delete*/
			tmp=tmp->next;
			pos--;
		}
		/*changing prev node of next to desired delete node of next*/
		prev->next=tmp->next;
		/*Unlink the desired mid  node*/
		free(tmp);
	}
}

void del_end(struct Node **head)
{
	/*last is used to indicate last node of the list,tmp is used as previous node of the last node of the list*/
	struct Node *tmp,*last;
	tmp=last=*head;
	while(last->next!=NULL)
	{
		/*Traversing the node till the last node of the list */
		tmp=last;
		last=last->next;
	}
	/*As tmp is now going to be last node,so placing NULL */
	tmp->next=NULL;
	/*Unlink the previous end node*/
	free(last);
}



void add()
{
	int ch;
	char str[10];
	while(1)
	{
		printf("1.add_start 2.add_mid 3.add_end 4.exit");
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
		printf("Do you want to add again : yes or no \n");
		gets(str);
		if((strcmp(str,"yes"))==0)
			continue;
		else
			break;
	}
}

void delete()
{
	int ch;
	char str[10];
	while(1)
	{
		printf("1.del_start 2.del_mid 3.del_end 4.exit");
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
		printf("Do you want to delete again : yes or no \n");
		gets(str);
		if((strcmp(str,"yes"))==0)

			continue;
		else
			break;
	}
}

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
