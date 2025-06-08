#include <stdio.h>
#include <stdlib.h>

#define TAILLE 3

int **allouer_matrice()
{
    int i;
    int **matrice;

    matrice = malloc(sizeof(int*) * TAILLE);
    for (i = 0; i < TAILLE; i++)
    {
        matrice[i] = malloc(sizeof(int) * TAILLE);
    }
    return matrice;
}

void remplir_matrice(int **matrice)
{
    int i, j;

    printf("Entrez les 9 valeurs :\n");
    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            scanf("%d", &matrice[i][j]);
        }
    }
}

int est_symetrique(int **matrice)
{
    int i, j;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            if (matrice[i][j] != matrice[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}

void afficher_matrice(int **matrice)
{
    int i, j;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **matrice = allouer_matrice();
    int i;

    remplir_matrice(matrice);

    printf("Matrice :\n");
    afficher_matrice(matrice);

    if (est_symetrique)
    {
        printf("\nLa matrice est symétrique.\n");
    }
    else
    {
        printf("\nLa matrice n'est pas symétrique.\n");
    }

    for (i = 0; i < TAILLE; i++)
    {
        free(matrice[i]);
    }
    free(matrice);

    return 0;

}