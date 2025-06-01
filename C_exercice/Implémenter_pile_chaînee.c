#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud
{
    int valeur;
    struct Noeud *next;
} Noeud;

void push(Noeud **pile, int val)
{
    Noeud *Nouveau;
    Nouveau = malloc(sizeof(Noeud));
    if(Nouveau == NULL)
    {
        printf("Erreur allocation !");
        return;
    }
    Nouveau->valeur = val;
    Nouveau->next = *pile;
    *pile = Nouveau;
}

int pop(Noeud **pile)
{
    Noeud *tmp = *pile;
    int val;
    if(pile == NULL)
    {
        printf("Pile vide !");
        return 0;
    }
    val = tmp->valeur;
    *pile = tmp->next;
    free(tmp);
    return val;
}

void afficher(Noeud *pile)
{
    if(pile == NULL)
    {
        printf("Pile vide !");
        return;
    }

    while(pile)
    {
        printf("%d", pile->valeur);
        if(pile->next)
        {
            printf(" -> ");
        }
        pile = pile->next;
    }
    printf("\n");
}

int main()
{
    Noeud *pile = NULL;
    int v;

    printf("Empile 3 éléments :\n");
    push(&pile, 30);
    push(&pile, 20);
    push(&pile, 10);
    printf("Pile : ");
    afficher(pile);

    v = pop(&pile);
    afficher(pile);

    return 0;
}