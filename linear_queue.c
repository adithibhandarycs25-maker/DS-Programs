
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int x;

    if(rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter element: ");
        scanf("%d", &x);

        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = x;
    }
}

void delete()
{
    if(front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
    {
        printf("Deleted element = %d\n", queue[front]);
        front++;

        if(front > rear)
            front = rear = -1;
    }
}

void display()
{
    int i;

    if(front == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue elements: ");
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);

        printf("\n");
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("Exit\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(ch != 4);

    return 0;
}

