#include <stdio.h>
#include <stdlib.h>

typedef struct Nombre
{
    int valeur;
} Nombre;

void trier_structs(Nombre *tab, int taille)
{
    int i;
    int j, min;
    Nombre tmp;

    for (i = 0; i < taille - 1; i++) {
        min = i;
        for (j = i + 1; j < taille; j++)
        {
            if (tab[j].valeur < tab[i].valeur)
            {
                min = j;
            }
        }

        if(min != i)
        {
            tmp = tab[i];
            tab[i] = tab[min];
            tab[min] = tmp;
        }
    }
}

int main()
{
    Nombre tab[5];
    int i;

    printf("Entrez 5 entiers : \n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &tab[i].valeur);
    }

    trier_structs(tab, 5);

    printf("Valeurs triées :\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", tab[i].valeur);
    }
    printf("\n");

    return 0;
}