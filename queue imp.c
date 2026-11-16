#include <stdio.h>
#include <stdlib.h>

struct node{
   int data;
   struct node *next;
   };

struct node*top=NULL;

void push(int value)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("memory allocation failed");
        return;
    }
    newnode->data=value;
    newnode->next=top;
    top=newnode;


    printf("%d is pushed",value);
}
void pop()
{
    struct node*temp;
    temp=top;

    if(top==NULL)
    {
        printf("ll is empty");
        return;

    }


    printf("%d is popped",temp->data);
    top=top->next;
    free(temp);

}
void display()
{
    struct node*temp=top;

    if(top==NULL)
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
        printf("1.push");
        printf("2.pop");
        printf("3.display");
        printf("4.exit");
        printf("enter choice\n");
        scanf("%d",&choice);


        switch(choice)
        {
        case 1:printf("enter value\n");
               scanf("%d",&value);
               push(value);
               break;

        case 2:pop();
               break;

        case 3:display();
               break;

        default:printf("exit");


        }
    }
    return 0;
}

