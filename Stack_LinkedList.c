#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
	
};struct node *head;

void push();
void pop();
void display();
void main()
{
	printf("\n****** Operations ******\n");
	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
	int choice=0;
	while(choice!=4)
	{
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();break;
			case 2:pop();break;
			case 3:display();break;
			case 4:exit(0);
			default:printf("You entered wrong key");
		}
	}
}
void push()
{
	struct node *ptr;
	int item;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	printf("Overflow");
	else
	{
		printf("\nEnter the item:");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			ptr->next=NULL;
			head=ptr;
			printf("\nItem pushed");
		}
		else
		{
			ptr->next=head;
			head=ptr;
			printf("\nItem pushed");
		}
	}
}
void pop()
{
	struct node *temp;
	if(head==NULL)
	printf("\nStack is empty");
	else
	{
		temp=head;
		head=temp->next;
		free(temp);
		printf("\nItem popped");
	}
	
}
void display()
{
	struct node *temp;
	if(head==NULL)
	printf("\nStack is empty");
	else
	{
		printf("\nStack of linked list follows as:\n");
		temp=head;
		while(temp!=NULL)
		{
			printf("-->%d",temp->data);
			temp=temp->next;
		}
	}
}
