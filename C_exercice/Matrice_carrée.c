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

void transposer_matrice(int **matrice)
{
    int i, j;
    int tmp;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = i + 1; j < TAILLE; j++)
        {
            tmp = matrice[i][j];
            matrice[i][j] = matrice[j][i];
            matrice[j][i] = tmp;
        }
    }
}

void afficher_matrice(int ** matrice)
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
    int **matrice;
    int i;
    matrice = allouer_matrice();

    remplir_matrice(matrice);

    printf("\nMatrice originale :\n");
    afficher_matrice(matrice);

    transposer_matrice(matrice);

    printf("\nMatrice transposée :\n");
    afficher_matrice(matrice);

    for (i = 0; i < TAILLE; i++)
    {
        free(matrice[i]);
    }
    free(matrice);

    return 0;

}