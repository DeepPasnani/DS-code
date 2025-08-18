#include<stdio.h>
#include<ctype.h>
#include<string.h>

char stack[100];
int top = -1;

void push(char c) 
{
    if (top < 99) 
    {
        stack[++top] = c;
    } 
    else 
    {
        printf("Stack overflow\n");
    }
}

char pop() 
{
    if (top > -1) 
    {
        return stack[top--];
    } 
    else 
    {
        printf("Stack underflow\n");
        return '\0';
    }
}

char priorities(char c) 
{
    if (c == '(')
        return 1;
    else if (c == '*' || c == '/') 
        return 2;
    else if (c == '+' || c == '-') 
        return 3;
    else
        return 0;
}

int main()
{
    char exp[100], result[100];
    int i, j = 0, len;
    printf("Enter an expression: ");
    scanf("%s", exp);

    printf("Postfix expression: ");
    len = strlen(exp);
    for (i = 0; i < len; i++) 
    {
        if (isalnum(exp[i])) 
        {
            result[j++] = exp[i];
        } 
        else if (exp[i] == '(') 
        {
            push(exp[i]);
        } 
        else if (exp[i] == ')') 
        {
            while (top != -1 && stack[top] != '(') 
            {
                result[j++] = pop();
            }
        } 
        else 
        {
            while (top != -1 && priorities(stack[top]) <= priorities(exp[i])) 
            {
                result[j++] = pop();
            }
            push(exp[i]);
        }
    }
    while (top != -1) 
    {
        result[j++] = pop();
    }
    result[j] = '\0';
    printf("%s\n", result);
    return 0;
}
