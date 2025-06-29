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
};

int isEmpty(Queue *q)
{
    return(q->size == 0);
};

int isFull(Queue *q)
{
    return(q->size == MAX);
};

int enqueue(Queue *q, int val)
{
    if(isFull(q))
    {
        printf("File pleine ! %d\n", val);
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
        printf("File vide !");
        return 0;
    }

    q->front = (q->front + 1) % MAX;
    *val = q->data[q->front];
    q->size--;
    return 1;
}

void displayQueue(Queue *q)
{
    int i, j;

    if(isEmpty(q))
    {
        printf("File vide !");
    }

    printf("contenue de la file : ");
    for(i = 0; i < q->size; i++)
    {
        j = (q->front + i) % MAX;
        printf("%d ", q->data[j]);
    }

    printf("\n");
}

int main()
{
    Queue q;
    int val;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);

    dequeue(&q, &val);
    printf("Element défiler: %d\n", val);
    displayQueue(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);
    displayQueue(&q);

    return 0;

}