#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *tab;
    int i;
    float somme = 0;
    
    tab = malloc(sizeof(int) * n);
    if (tab == NULL)
    {
        return 1;
    }

    printf("Combien de nombres ? ");
    scanf("%d", &n);

    printf("Entrez les nombres :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &tab[i]);
        somme += tab[i];
    }

    printf("Moyenne = %f\n", somme / n);

    free(tab);

    return 0;
}