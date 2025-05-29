#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    int valeur;
    struct Element *next;
}  Element;

void empiler(Element **pile, int val)
{
    Element *Nouveau;
    Nouveau = malloc(sizeof(Element));

    Nouveau->valeur = val;
    Nouveau->next = *pile;
    *pile = Nouveau;
}

void afficher_pile(Element *pile)
{
    if(pile == NULL)
    {
        printf("La pile est vide");
    }

    printf("Contenue de la pile :\n");

    while(pile)
    {
        printf("%d\n", pile->valeur);
        pile = pile->next;
    }
}

int main()
{
    Element *pile = NULL;
    int i;
    int val;
    Element *temp = pile;

    printf("Entreé 5 entiers :\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &val);
        empiler(&pile, val);
    }

    afficher_pile(pile);

    while(pile)
    {
        pile = pile->next;
        free(temp);
    }

    return 0;
}