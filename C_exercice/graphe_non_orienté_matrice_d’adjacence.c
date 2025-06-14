#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int adj[MAX][MAX] = {0};
    int n = 4;
    int e, i, u, v, j;

    printf("Entrez le nombre d'arêtes :\n");
    scanf("%d", &e);

    for (i = 0; i < e; i++)
    {
       printf("Entrez l'arête %d (format : sommet1 sommet2) : ", i+1);
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n || u == v)
        {
            printf("Arête invalide. Réessayez.\n");
            i--;
            continue;
        }

         adj[u][v] = 1;
         adj[v][u] = 1;
    }


    printf("\nMatrice d'adjacence :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}