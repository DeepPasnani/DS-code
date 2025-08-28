#include<stdio.h>
#include<stdlib.h>
struct ND
{
    int info;
    struct ND *next, *prev;
};
struct ND* first = NULL;

void insertbeg(int value)
{
    struct ND* newNode = (struct ND*)malloc(sizeof(struct ND));
    newNode->info = value;
    newNode->next = first;
    newNode->prev = NULL;
    if (first != NULL)
    {
        first->prev = newNode;
    }
    first = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

void insertend(int value)
{
    struct ND* newNode = (struct ND*)malloc(sizeof(struct ND));
    newNode->info = value;
    newNode->next = NULL;

    if (first == NULL) // empty list
    {
        newNode->prev = NULL;
        first = newNode;
        printf("Inserted %d at the end.\n", value);
        return;
    }

    struct ND* curr = first;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;

    printf("Inserted %d at the end.\n", value);
}

void removeend()
{
    struct ND* curr = first;
    if (first == NULL)
    {
        printf("List is empty. Cannot remove from end.\n");
        return;
    }
    if (first->next == NULL)
    {
        printf("Removed %d from the end.\n", first->info);
        free(first);
        first = NULL;
        return;
    }
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    printf("Removed %d from the end.\n", curr->info);
    curr->prev->next = NULL;
    free(curr);
}

void removebeforespecified(int key)
{
    struct ND* curr = first;
    if (first == NULL || first->info == key)
    {
        printf("No node exists before the specified key %d.\n", key);
        return;
    }
    while (curr != NULL && curr->info != key)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        printf("Key %d not found in the list.\n", key);
        return;
    }
    if (curr->prev == NULL)
    {
        printf("No node exists before the specified key %d.\n", key);
        return;
    }
    struct ND* toDelete = curr->prev;
    if (toDelete->prev != NULL)
    {
        toDelete->prev->next = curr;
        curr->prev = toDelete->prev;
    }
    else
    {
        first = curr;
        curr->prev = NULL;
    }
    printf("Removed %d which was before the specified key %d.\n", toDelete->info, key);
    free(toDelete);
}

void display()
{
    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct ND* temp = first;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() 
{
    int choice, info;
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete from the end\n");
        printf("4. Delete after specific\n");
        printf("5. Display\n");
        printf("6. Exit\n");
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
                printf("Enter how many to delete from end: ");
                scanf("%d", &info);
                for (int i = 0; i < info; i++) 
                {
                    removeend();
                }
                break;
            case 4:
                printf("Enter value of the node: ");
                scanf("%d", &info);
                removebeforespecified(info);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}