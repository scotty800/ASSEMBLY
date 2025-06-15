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

void addEge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adLists[src];
    graph->adLists[src] = newNode;
}

void printGraph(Graph *graph)
{
    int v;

    for(v = 0; v < graph->newVertices; v++)
    {
        Node *tmp = graph->adLists[v];
        printf("Sommet %d :", v);

        while(tmp)
        {
            printf(" -> %d", tmp->vertex);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

int main()
{
    int v = 4, e, src, dest, i; 
    Graph *graph = createGraph(v);

    printf("Entrez le nombre d'aêtes :");
    scanf("%d", &e);

    for (i = 0; i < e; i++)
    {
        printf("Entrez arête %d (src dest) : ", i+1);
        scanf("%d %d", &src, &dest);
        addEge(graph, src, dest);
    }
    printf("\nReprésentation du graphe (listes d'adjacence) :\n");
    printGraph(graph);
}