#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Queue
{
    int data[MAX];
    int rear;
    int front;
    int size;
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue *q)
{
    return q->size == 0;
}

int isFull(Queue *q)
{
    return q->size == MAX;
}

int enqueue(Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Is full ! : %d\n ", val);
        return 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = val;
    q->size++;

    return 1;
}

int dequeue(Queue *q, int *val)
{
    if(isEmpty(q))
    {
        printf("is empty !");
        return 0;
    }
    *val = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;

    return 1;
}

int peek(Queue *q, int *val)
{
    if(isEmpty(q))
    {
        printf("File vide !\n");
        return 0;
    }
    *val = q->data[q->front];
    return 1;
}

void displayQueue(Queue *q)
{
    int i, j;

    if(isEmpty(q))
    {
        printf("File vide !");
        return;
    }

    printf("contenue de la file : ");

    for(i = 0; i < q->size; i++)
    {
        j = (q->front + i) % MAX;
        printf("%d ", q->data[j]);
    }

    printf("\n");
}

void clearQueue(Queue *q)
{
    if (q->size == 0)
    {
        printf("File vide !\n");
        return;
    }

    q->front = 0;
    q->rear = -1;
    q->size = 0;

    printf("File vidée avec succès.\n");
}

int main()
{
    int choix;
    Queue q;
    int val;
    initQueue(&q);

    while(1)
    {
        printf("=== MENU FILE ===\n");
        printf("\n1. Enfiler un élément\n");
        printf("\n2. Défiler un élément\n");
        printf("\n3. Afficher la file\n");
        printf("\n4. Voir l'élément en tête (peek)\n");
        printf("\n5. Vérifier si la file est vide\n");
        printf("\n6. Vérifier si la file est pleine\n");
        printf("\n0. Quitter\n");
        printf("\nChoix :\n");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                printf("Valeur à enfiler : ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                if (dequeue(&q, &val))
                printf("Valeur défilée : %d\n", val);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                if (peek(&q, &val))
                printf("Élément en tête : %d\n", val);
                break;
            case 5:
                printf(isEmpty(&q) ? "La file est vide.\n" : "La file n'est pas vide.\n");
                break;
            case 6:
                printf(isFull(&q) ? "La file est pleine.\n" : "La file n'est pas pleine.\n");
                break;
            case 0:
               printf("Au revoir !\n");
               return 0;
               break;
            default:
                printf("Choix invalide !\n");

        };
    };

};
