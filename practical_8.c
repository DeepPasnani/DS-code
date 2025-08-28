#include <stdio.h>
#include <stdlib.h>

struct ND 
{
    int info;
    struct ND* next;
};

struct ND* first = NULL;

void insertbeg(int value) 
{
    struct ND* newNode = (struct ND*)malloc(sizeof(struct ND));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->info = value;
    newNode->next = NULL;
    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        newNode->next = first;  
        first = newNode;
    }
    printf("Inserted %d at the beginning.\n", value);
}

void insertend(int value) 
{
    struct ND* newNode = (struct ND*)malloc(sizeof(struct ND));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->info = value;
    newNode->next = NULL;
    if (first == NULL) {
        first = newNode;
        printf("Inserted %d at the end.\n", value);
        return;
    }
    struct ND* current = first;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    current->next = newNode;
    printf("Inserted %d at the end.\n", value);
}

void insertas(int value) 
{
    struct ND* newNode = (struct ND*)malloc(sizeof(struct ND));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->info = value;
    newNode->next = NULL;

    if (first == NULL || first->info >= value) 
    {
        newNode->next = first;
        first = newNode;
        printf("Inserted %d in ascending order.\n", value);
        return;
    }

    struct ND* current = first;
    while (current->next != NULL && current->next->info < value) 
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    printf("Inserted %d in ascending order.\n", newNode->info);
}

void deletebeg() 
{
    if (first == NULL) {
        printf("List is empty. Cannot delete from beginning.\n");
        return;
    }
    struct ND* temp = first;
    first = first->next;
    printf("Deleted node with info %d from the beginning.\n", temp->info);
    free(temp);
}

void deletegiven(int value) 
{
    if (first == NULL) 
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct ND* temp = first;
    struct ND* prev = NULL;
    if (temp != NULL && temp->info == value) 
    {
        first = temp->next;
        printf("Deleted node with info %d.\n", temp->info);
        free(temp);
        return;
    }
    while (temp != NULL && temp->info != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with info %d not found.\n", value);
        return;
    }
    prev->next = temp->next;
    printf("Deleted node with info %d.\n", temp->info);
    free(temp);
}

void deletenextgiven(int value) 
{
    if (first == NULL) 
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct ND* temp = first;
    while (temp != NULL && temp->info != value) 
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Node with info %d not found or it is the last node.\n", value);
        return;
    }
    struct ND* toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted node with info %d, which was after node %d.\n", toDelete->info, value);
    free(toDelete);
}

void displayList() 
{
    if (first == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    struct ND* node = first;
    while (node != NULL) {
        printf("%d -> ", node->info);
        node = node->next;
    }
    printf("NULL\n");
}

int main() 
{
    int choice, info;

    while (1) {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert in ascending order\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete a given node\n");
        printf("6. Delete node after a given node\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter how many to insert at start: ");
                scanf("%d", &info);
                for (int i = 0; i < info; i++) {
                    int value;
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    insertbeg(value);
                }
                break;
            case 2:
                printf("Enter how many to insert at end: ");
                scanf("%d", &info);
                for (int i = 0; i < info; i++) 
                {
                    int value;
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    insertend(value);
                }
                break;
            case 3:
                printf("Enter info to insert: ");
                scanf("%d", &info);
                insertas(info);
                break;
            case 4:
                printf("Enter how many to delete from beginning: ");
                scanf("%d", &info);
                for (int i = 0; i < info; i++) 
                {
                    deletebeg();
                }
                break;
            case 5:
                printf("Enter value of node to delete: ");
                scanf("%d", &info);
                deletegiven(info);
                break;
            case 6:
                printf("Enter value of the preceding node: ");
                scanf("%d", &info);
                deletenextgiven(info);
                break;
            case 7:
                displayList();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
