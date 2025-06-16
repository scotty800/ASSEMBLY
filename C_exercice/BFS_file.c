#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int queue[SIZE];
int front = -1, rear = -1;

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int newVertices;
    Node **adLists;
} Graph;

Node *createNode(int v)
{
    Node *newNode;
    newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *graph;
    int i;

    graph = malloc(sizeof(Graph));
    graph->newVertices = vertices;
    graph->adLists = malloc(sizeof(Node*) * vertices);

    for(i = 0; i < vertices; i++)
    {
        graph->adLists[i] = NULL;
    }
    return graph;
}

void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    queue[++rear] = value;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        return -1;
    }

    return queue[front++];
}

int isEmpty()
{
    return front == -1 || front > rear;
}

void BFS(Graph *graph, int startVertex)
{
    int visited[graph->newVertices];
    int distance[graph->newVertices];
    int i, current, v;
    Node *tmp;

    for (i = 0; i < graph->newVertices; i++) {
        visited[i] = 0;
        distance[i] = -1;
    }

    enqueue(startVertex);
    visited[startVertex] = 1;
    distance[startVertex] = 0;

    while(!isEmpty()) {
        current = dequeue();
        printf("Visite %d, distance : %d\n", current, distance[current]);

        tmp = graph->adLists[current];  // C'EST ICI QUE TU DOIS LE METTRE
        while(tmp) {
            v = tmp->vertex;
            if (!visited[v]) {
                enqueue(v);
                visited[v] = 1;
                distance[v] = distance[current] + 1;
            }
            tmp = tmp->next;
        }
    }
}


int main()
{
    int v = 4, e, src, dest, i; 
    Graph *graph = createGraph(v);

    int start;
    printf("\nSommet de départ pour BFS : ");
    scanf("%d", &start);
    BFS(graph, start);
}