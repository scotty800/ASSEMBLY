#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud
{
    int valeur;
    struct Noeud *next;
} Noeud;

typedef struct File
{
    Noeud *debut;
    Noeud *fin;
} File;

void enqueue(File *file, int val)
{
    Noeud *Nouveau;
    Nouveau = malloc(sizeof(Noeud));
    if(!Nouveau)
    {
        printf("Erreur Allocation !");
        return;
    }
    Nouveau->valeur = val;
    Nouveau->next = NULL;

    if(file->debut == NULL)
    {
        file->debut = file->fin = Nouveau;
    }
    else
    {
        file->fin->next = Nouveau;
        file->fin = Nouveau;
    }
}

int dequeue(File *file)
{
    if(!file->debut)
    {
        printf("file vide !");
        return 0;
    }
    Noeud *tmp = file->debut;
    int val;

    file->debut = tmp->next;
    if(file->debut == NULL) file->fin = NULL;
    val = tmp->valeur;
    free(tmp);
    return val;
}

void afficher(File *file)
{
    Noeud *courant = file->debut;
    if(courant == NULL)
    {
        printf("file vide");
        return;
    }

    while(courant)
    {
        printf("%d", courant->valeur);
        if(courant->next)
        {
            printf(" -> ");
        }
        courant = courant->next;
    }
}

int main()
{
    File file = {NULL, NULL};

    enqueue(&file, 5);
    enqueue(&file, 10);
    enqueue(&file, 15);
    printf("Contenu de la file : ");
    afficher(&file);
    printf("Retrait : %d\n", dequeue(&file));
    printf("Contenu de la file : ");
    afficher(&file);
}