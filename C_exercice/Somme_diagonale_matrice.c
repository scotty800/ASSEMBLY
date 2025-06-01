#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i, j;
    int **matrice;
    int diag1 = 0, diag2 = 0;

    printf("Taille de la matrice :");
    scanf("%d", &n);

    matrice = malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
    {
        matrice[i] = malloc(sizeof(int) * n);   
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrice[i][j]); 
        }
    }
    
    for(i = 0; i < n; i++)
    {
        diag1 += matrice[i][i];
        diag2 += matrice[i][n - i - 1];
    }

    printf("Somme diagonale principale = %d\n", diag1);
    printf("Somme diagonale secondaire = %d\n", diag2);

    for (i = 0; i < n; i++) {
        free(matrice[i]);
    }
    free(matrice);

}