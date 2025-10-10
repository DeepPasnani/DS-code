#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int adjMatrix[MAX_VERTICES][MAX_VERTICES];

struct ListNode 
{
 int vertex;
 struct ListNode* next;
};

struct ListNode* adjList[MAX_VERTICES];
 
void initializeGraph(int vertices) 
{
 for (int i = 0; i < vertices; i++) 
 {
    for (int j = 0; j < vertices; j++) 
 {
    adjMatrix[i][j] = 0;
 }
   adjList[i] = NULL;
 }
}
 
void addEdgeMatrix(int src, int dest) 
 {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1; // For undirected graph
 }
 
void addEdgeList(int src, int dest) 
{
 struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
 newNode->vertex = dest;
 newNode->next = adjList[src];
 adjList[src] = newNode;
 newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
 newNode->vertex = src;
 newNode->next = adjList[dest];
 adjList[dest] = newNode;
 }

void displayMatrix(int vertices) 
{
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) 
    {
        for (int j = 0; j < vertices; j++) 
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void displayList(int vertices) 
{
    printf("\nAdjacency List:\n");
    for (int i = 0; i < vertices; i++) 
    {
        printf("Vertex %d: ", i);
        struct ListNode* temp = adjList[i];
        while (temp != NULL) 
        {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() 
{
    int vertices = 5;
    initializeGraph(vertices);
    addEdgeMatrix(0, 1);
    addEdgeMatrix(0, 4);
    addEdgeMatrix(1, 2);
    addEdgeMatrix(1, 3);
    addEdgeMatrix(1, 4);
    addEdgeMatrix(2, 3);
    addEdgeMatrix(2, 4);
    addEdgeMatrix(3, 4);
    addEdgeList(0, 1);
    addEdgeList(0, 4);
    addEdgeList(1, 2);
    addEdgeMatrix(0, 4);
    addEdgeMatrix(1, 2);
    addEdgeMatrix(1, 3);
    addEdgeMatrix(1, 4);
    addEdgeMatrix(2, 3);
    addEdgeMatrix(3, 4);
    addEdgeList(0, 1);
    addEdgeList(0, 4);
    addEdgeList(1, 2);
    addEdgeList(1, 3);
    addEdgeList(1, 4);
    addEdgeList(2, 3);
    addEdgeList(3, 4);
    displayMatrix(vertices);
    displayList(vertices);
    return 0;
}