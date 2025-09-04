#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int queue[SIZE];
int front=-1, rear=-1;

void enqueue(int value)
{
    if(rear == SIZE - 1 && front == 0 || front == rear + 1)
    {
        printf("Overflow.\n");   
        return;
    }
    else if(front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear ++;
    }
    queue[rear] = value;
}

void dequeue()
{
    if(front == -1)
    {
        printf("Underflow.\n");
        return;
    }
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if(front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Current Queue: ");
    int i = front;
    while(i != rear)
    {
        printf("%d ", queue[i]);
        i++;
    }
    printf("%d", queue[i]);
    printf("\n");
}

int main()
{
    int choice;
    int value;
    int n;

    while(1)
    {
        printf("\nCircular Queue Operations: 1. Enqueue, 2. Dequeue, 3. Display, 4. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("How many times you want to enqueue: ");
                scanf("%d", &n);
                for(int i = 0; i < n; i++) {
                    printf("Enter value to enqueue: ");
                    scanf("%lf", &value);
                    enqueue(value);
                }
                break;

            case 2:
                printf("Enter number times to dequeue: ");
                scanf("%d", &n);
                for(int i=0; i<n; i++)
                {
                    dequeue();
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
