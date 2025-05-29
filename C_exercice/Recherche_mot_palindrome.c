#include <stdio.h>
#include <stdlib.h>

int longueur_chaine(char *s)
{
    while(*s != '\0')
    {
        s++;
    }
    return *s;
}

int est_palindrome(char *s)
{
    int i;
    int j = longueur_chaine(s) -1;

    while (i < j)
    {
        if (s[i] != s[j])
        {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

int main()
{
    char mot[100];

    printf("Entrez un mot :");
    scanf("%s", mot);

    if (est_palindrome(mot))
    {
        printf("C'est un palindrome\n");
    }

    return 0;
}