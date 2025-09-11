//Binary Search Tree using Non Recursive Method
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node 
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) 
{
    struct Node* newNode = createNode(data);
    if (root == NULL) return newNode;

    struct Node* parent = NULL;
    struct Node* current = root;

    while (current != NULL) 
    {
        parent = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else 
        {
            free(newNode);
            return root;
        }
    }
    if (data < parent->data) parent->left = newNode;
    else parent->right = newNode;

    return root;
}

void inorder(struct Node* root) 
{
    struct Node* stack[MAX];
    int top = -1;
    struct Node* curr = root;

    while (curr != NULL || top >= 0) 
    {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void preorder(struct Node* root) 
{
    if (root == NULL) return;
    struct Node* stack[MAX];
    int top = -1;

    stack[++top] = root;
    while (top >= 0) 
    {
        struct Node* curr = stack[top--];
        printf("%d ", curr->data);

        if (curr->right) stack[++top] = curr->right;
        if (curr->left)  stack[++top] = curr->left;
    }
}

void postorder(struct Node* root) 
{
    if (root == NULL) return;
    struct Node* stack1[MAX], *stack2[MAX];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;
    while (top1 >= 0) 
    {
        struct Node* curr = stack1[top1--];
        stack2[++top2] = curr;

        if (curr->left)  stack1[++top1] = curr->left;
        if (curr->right) stack1[++top1] = curr->right;
    }
    while (top2 >= 0)
        printf("%d ", stack2[top2--]->data);
}

int main() 
{
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder   : "); inorder(root);
    printf("\nPreorder  : "); preorder(root);
    printf("\nPostorder : "); postorder(root);
    printf("\n");

    return 0;
}
