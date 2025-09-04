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

void search(struct node* root, int key)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return;
    }
    if (root->info == key)
    {
        printf("Element %d found\n", key);
        return;
    }
    if (key < root->info)
        search(root->left, key);
    else
        search(root->right, key);
}

int main()
{
    int choice, info, key, n;
    while(1)
    {
        printf("\n1. Insert 2. Inorder 3. Preorder 4. Postorder 5. Search 6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                    printf("Enter number of elements to insert: ");
                    scanf("%d", &n);
                    for(int i = 0; i < n; i++)
                    {
                        printf("Enter element %d: ", i + 1);
                        scanf("%d", &info);
                        root = insert(root, info);
                    }
                    break;
            case 2:
                    printf("Inorder : ");
                    inorder(root);
                    printf("\n");
                    break;
            case 3:
                    printf("Preorder: ");
                    preorder(root);
                    printf("\n");
                    break;
            case 4:
                    printf("Postorder: ");
                    postorder(root);    
                    printf("\n");
                    break;
            case 5:
                    printf("Enter element to search: ");
                    scanf("%d", &key);
                    search(root, key);
                    break;
            case 6:
                    return 0;
            default:
                    printf("Invalid choice.\n");
                    break;
        }
    }
    return 0;
}