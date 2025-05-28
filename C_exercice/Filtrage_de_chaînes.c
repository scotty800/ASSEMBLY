#include <stdio.h>
#include <stdlib.h>

typedef enum CategorieMot
{
    MAJUSCULE,
    MINUSCULE,
    AUTRE

} CategorieMot;

typedef struct Mot
{
    char texte[100];
    enum CategorieMot categorie;
} Mot;

CategorieMot dectecter_categorie(char *mot)
{
    if (mot[0] >= 'A' && mot[0] <= 'Z')
    {
        return MAJUSCULE;
    }
    else if (mot[0] >= 'a' && mot[0] <= 'z')
    {
        return MINUSCULE;
    }
    else
    {
        return AUTRE;
    }
};

void afficher_majuscules(Mot *mots, int n)
{
    int i;

    printf("\nMots commençant par une majuscule :\n");
    for (i = 0; i < n; i++)
    {
        if (mots[i].categorie == MAJUSCULE)
        {
            printf("%s\n", mots[i].texte);
        };
    }
}

int main()
{
    Mot mots[5];
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("Mot %d : ", i + 1);
        scanf("%s", mots[i].texte);
        mots[i].categorie = dectecter_categorie(mots[i].texte);
    }

    afficher_majuscules(mots, 5);
};