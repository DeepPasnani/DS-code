//Binary Search tree Using Recurisve Method
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* left, *right;
};
struct node* root = NULL;
struct node* insert(struct node* root, int info)
{
    if (root == NULL)
    {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->info = info;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (info < root->info)
        root->left = insert(root->left, info);
    else if (info > root->info)
        root->right = insert(root->right, info);
    return root;
}

void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void preorder(struct node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

int main()
{
    int n, info;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &info);
        root = insert(root, info);
    }
    printf("Inorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}
