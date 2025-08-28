#include<stdio.h>
#include<stdlib.h>
struct ND
{
    int info;
    struct ND* next;
};
struct ND* first=NULL;

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
    if (first == NULL) 
    {
        first = newNode;
        newNode->next = first;
    } 
    else 
    {
        struct ND* temp = first;
        while (temp->next != first)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = first;
    }
    printf("Inserted %d at the end.\n", value);
}

void insertbefore_specific(int value)
{
    int key;
    printf("Enter the value before which to insert: ");
    scanf("%d", &key);
    struct ND* newNode = (struct ND*)malloc(sizeof(struct ND));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->info = value;
    if (first == NULL)
    {
        printf("List is empty.\n");
        free(newNode);
        return;
    }
    if (first->info == key)
    {
        struct ND* temp = first;
        while (temp->next != first)
            temp = temp->next;
        newNode->next = first;
        temp->next = newNode;
        first = newNode;
        printf("Inserted %d before %d.\n", value, key);
        return;
    }
    struct ND* prev = first;
    struct ND* curr = first->next;
    while (curr != first)
    {
        if (curr->info == key)
        {
            newNode->next = curr;
            prev->next = newNode;
            printf("Inserted %d before %d.\n", value, key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Value %d not found in the list.\n", key);
    free(newNode);
}

void removebeg()
{
    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct ND* temp = first;
    if (first->next == first)
    {
        first = NULL;
    }
    else
    {
        struct ND* last = first;
        while (last->next != first)
            last = last->next;
        first = first->next;
        last->next = first;
    }
    free(temp);
    printf("Removed first element.\n");
}

void removespecific(int key)
{
    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct ND* curr = first;
    struct ND* prev = NULL;
    do
    {
        if (curr->info == key)
        {
            if (prev == NULL)
            {
                struct ND* last = first;
                while (last->next != first)
                    last = last->next;
                first = first->next;
                last->next = first;
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr);
            printf("Removed %d from the list.\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != first);
    printf("Value %d not found in the list.\n", key);
}

void display()
{
    if (first == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct ND* temp = first;
    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", temp->info);
        temp = temp->next;
    } while (temp != first);
    printf("(back to %d)\n", first->info);
}

int main() 
{
    int choice, info;
    while (1) {
        printf("\nCircular Singly Linked List Operations:\n");
        printf("1. Insert at the end\n");
        printf("2. Insert before specific\n");
        printf("3. Delete from the beginning\n");
        printf("4. Delete after specific\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter how many to insert at end: ");
                scanf("%d", &info);
                for (int i = 0; i < info; i++) {
                    int value;
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    insertend(value);
                }
                break;
            case 2:
                printf("Enter how many to insert before specific: ");
                scanf("%d", &info);
                for (int i = 0; i < info; i++) 
                {
                    int value;
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    insertbefore_specific(value);
                }
                break;
            case 3:
                printf("Enter how many to delete from beginning: ");
                scanf("%d", &info);
                for (int i = 0; i < info; i++) 
                {
                    removebeg();
                }
                break;
            case 4:
                printf("Enter value of the preceding node: ");
                scanf("%d", &info);
                removespecific(info);
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
