#include<stdio.h>
#define SIZE 50
int top = -1;
int stack[SIZE];

int push(int stack[SIZE], int value)
{
    if (top == SIZE - 1) 
    {
        printf("Stack overflow.\n");
        return stack[top];
    }
    top++;
    stack[top] = value;
}

int pop(int stack[SIZE], int value)
{
    if (top == -1) 
    {
        printf("Stack underflow.\n");
        return -1;
    }
    value = stack[top];
    top--;
    printf("Popped value: %d\n", value);
}

int peek(int stack[SIZE])
{
    if (top == -1) 
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack[top];
}

int display(int stack[SIZE])
{
    if (top == -1) 
    {
        printf("Stack is empty.\n");
        return -1;
    }
    printf("Stack elements from top to bottom:\n");
    for (int i = top; i >= 0; i--) 
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
    return 0;
}
int main()
{
    int value, top = -1, num;
    int stack[SIZE];
    char op;
    printf("Enter (a,b,c,d) for (push,pop,peek,display): ");
    scanf("%c", &op);
    switch(op)
    {
        case 'a':
            printf("Enter the number of values you want to push : ");
            scanf("%d", &num);
            for(int i = 0; i < num; i++)
            {
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
            }
            break;
            
        case 'b':
            printf("Enter the number of times you want to pop : ");
            scanf("%d", &num);
            for(int i = 0; i < num; i++)
            {
                printf("Enter value to pop: ");
                scanf("%d", &value); 
                pop(stack, value);
            }
            printf("No. of Popped = %d.\n", num);
            break;
            
        case 'c':
            value = peek(stack);
            if (value != -1)
            {
                printf("Top value: %d\n", value);
            }
            else
            {
                printf("Stack is empty, no top value.\n");
            }
            break;
            
        case 'd':
            display(stack);
            break;
    }
    printf("Do you want to see the whole stack? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        display(stack);
    }
    else
    {
        printf("Exiting without displaying the stack.\n");
    }
return 0;
}