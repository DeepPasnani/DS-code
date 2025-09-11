//Queue using Linked List
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;

void enqueue(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if(rear == NULL)
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue()
{
    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }
    struct node *temp = front;
    front = front->next;
    if(front == NULL)
    {
        rear = NULL;
    }
    free(temp);
}

void display()
{
    struct node *temp = front;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Queue elements: ");
    display();
    dequeue();
    printf("Queue elements after dequeue: ");
    display();
    return 0;
}