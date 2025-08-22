#include<stdio.h>
#define SIZE 5

double queue[];
int front=-1, rear=-1;

void enqueue(double value)
{
    if(rear==SIZE-1)
    {
        printf("Overflow.\n");
        return;
    }
    else
    {
        queue[rear+1] = value;
        rear++;
    }
}

void dequeue()
{
    if(front==rear)
    {
        printf("Underflow.\n");
        return;
    }
    else
    {
        front++;
    }
}

void display()
{
    if(front==rear)
    {
        printf("Queue is empty.\n");
        return;
    }
    else
    {
        for(int i=front+1; i<=rear; i++)
        {
            printf("%lf ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    double value;
    printf("Enter the number of values you want to enqueue: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%lf", &value);
        enqueue(value);
    }
    printf("Enter the operation you want to perform (1: Display, 2: Dequeue): ");
    int choice;
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            display();
            break;

        case 2:
            printf("Enter number of times you want to dequeue: ");
            scanf("%d", &n);
            for(int i = 0; i < n; i++)
            {
                dequeue();
            }
            display();
            break;
 
        default:
            printf("Enter proper choice.\n");
    }
    return 0;
}