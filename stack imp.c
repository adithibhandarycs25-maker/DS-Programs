#include <stdio.h>
#include <stdlib.h>

struct node{
   int data;
   struct node *next;
   };

struct node*front=NULL;
struct node*rear=NULL;

void enqueue(int value)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("memory allocation failed");
        return;
    }
    newnode->data=value;
    newnode->next=NULL;

    if(front==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    printf("%d is pushed",value);
}
void dequeue()
{
    struct node*temp;
    temp=front;

    if(front==NULL)
    {
        printf("ll is empty");
        return;
    }
    if(front==NULL)
    {
        rear=NULL;
    }
    printf("%d is dequeued",front->data);
    front=front->next;
    free(temp);
}
void display()
{
    struct node*temp=front;

    if(front==NULL)
    {
        printf("ll is empty");
        return;
    }
    printf("the elements of ll are:");
    while(temp!=NULL)
    {printf("%d  ",temp->data);
    temp=temp->next;
    }
}

int main()
{
    int choice,value;
    while(1)
    {
        printf("1.enqueue");
        printf("2.dequeue");
        printf("3.display");
        printf("4.exit");
        printf("enter choice\n");
        scanf("%d",&choice);


        switch(choice)
        {
        case 1:printf("enter value\n");
               scanf("%d",&value);
               enqueue(value);
               break;

        case 2:dequeue();
               break;

        case 3:display();
               break;

        default:printf("exit");


        }
    }
    return 0;
}
