#include <stdio.h>
#include <stdlib.h>

#define FILENAME "records.dat"
#define MAX_NAME 50

typedef struct 
{
    int id;
    char name[MAX_NAME];
    float marks;
} Student;

void createRecords(int n) 
{
    FILE *fp = fopen(FILENAME, "wb");
    if (!fp) 
    {
        printf("Error opening file.\n");
        return;
    }
    Student s;
    for (int i = 0; i < n; i++) 
    {
        printf("Enter ID, Name, Marks for student %d:\n", i + 1);
        scanf("%d", &s.id);
        getchar(); 
        fgets(s.name, MAX_NAME, stdin);
        s.name[strcspn(s.name, "\n")] = 0; 
        scanf("%f", &s.marks);
        fwrite(&s, sizeof(Student), 1, fp);
    }
    fclose(fp);
}

void displayRecords() 
{
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) 
    {
        printf("Error opening file.\n");
        return;
    }
    Student s;
    printf("\nRecords:\n");
    while (fread(&s, sizeof(Student), 1, fp)) 
    {
        printf("ID: %d, Name: %s, Marks: %.2f\n", s.id, s.name, s.marks);
    }
    fclose(fp);
}

int main() 
{
    int n;
    printf("Enter number of records to create: ");
    scanf("%d", &n);
    createRecords(n);
    displayRecords();
    return 0;
}