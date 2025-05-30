#include <stdio.h>
#include <stdlib.h>

int longueur_chaine(char *s)
{
    int count;
    while (*s != '\0')
    {
        s++;
        count++;
    }

    return count;
}

int comparer_chaines(char *a, char *b)
{
    int i;

    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
        {
            return 0;
        }
        i++;
    }

    if (a[i] != '\0' || b[i] != '\0')
    {
        return 0;
    }
    else
        return 1;
}

int compter_occurrences(char *tableau[], int taille, char *mot)
{
    int i;
    int count = 0;
    for (i = 0; i < taille; i++)
    {
        if(comparer_chaines(tableau[i], mot))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char *mots[5] = {"pomme", "banane", "pomme", "orange", "pomme"};
    int nb;
    char mot[100];

    printf("Entrez un mot à rechercher :\n");
    scanf("%s", mot);

    nb = compter_occurrences(mots, 5, mot);

    printf("le mot '%s' apparait %d fois.\n", mot, nb);
    return 0;
}