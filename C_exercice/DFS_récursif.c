#include <stdio.h>
#include <stdlib.h>

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

void DFS(Graph *graph, int vertex, int *visited)
{
    int v;
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node *tmp = graph->adLists[vertex];
    while(tmp)
    {
        v = tmp->vertex;
        if(!visited[v]) 
        {
            DFS(graph, v, visited);
        }
        tmp = tmp->next;
    }
}

int main()
{
    int v = 4, e, src, dest, i; 
    Graph *graph = createGraph(v);

    int visited[v];
    int start;

    printf("Entrez le nombre d'arêtes : ");
    scanf("%d", &e);
    
    for (i = 0; i < e; i++) {
    printf("Entrez l'arête %d (src dest) : ", i + 1);
    scanf("%d %d", &src, &dest);

    Node *newNode = createNode(dest);
    newNode->next = graph->adLists[src];
    graph->adLists[src] = newNode;

    // Si graphe non orienté, on ajoute l'inverse :
    newNode = createNode(src);
    newNode->next = graph->adLists[dest];
    graph->adLists[dest] = newNode;
}


    for(i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

    printf("\nSommet de départ pour DFS : ");
    scanf("%d", &start);

    printf("Parcours DFS : ");
    DFS(graph, start, visited);
    printf("\n");
}