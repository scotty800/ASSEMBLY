#include <stdio.h>
#include <stdlib.h>

typedef enum Etat
{
    A_FAIRE,
    EN_COURS,
    TERMINE
} Etat;

typedef struct Tache
{
    char nom[50];
    Etat etat;
    struct Tache *next;
} Tache;

void ajouter_tache(Tache **liste, char *nom, Etat etat)
{
    Tache *Nouveau;
    int i = 0;

    Nouveau = malloc(sizeof(Tache));
    if(Nouveau == NULL)
    {
        printf("Erreur d'allocation de memoire");
        return;
    }

    while(nom[i] != '\0' && i < 49)
    {
        Nouveau->nom[i] = nom[i];
        i++;
    }
    Nouveau->nom[i] = '\0';
    Nouveau->etat = etat;
    Nouveau->next = *liste;
    *liste = Nouveau;
}

void afficher_taches(Tache * liste)
{
    printf("Taches :");
    while(liste)
    {
        printf("- Nom : %s, Etat : ", liste->nom);
        switch(liste->etat) {
            
            case A_FAIRE: 
                printf("A_FAIRE"); 
            break;
            case EN_COURS: 
                printf("EN_COURS"); 
            break;
            case TERMINE: 
                printf("TERMINE"); 
            break;
        }
        printf("\n");
        liste = liste->next;
    }
}

void liberer_liste(Tache *liste)
{
    Tache *tmp;
    while(liste)
    {
        tmp = liste;
        liste = liste->next;
        free(tmp);
    }
}

int main()
{
    Tache *liste = NULL;
    ajouter_tache(&liste, "Test", TERMINE);
    ajouter_tache(&liste, "Relecture", A_FAIRE);
    ajouter_tache(&liste, "Code", EN_COURS);

    afficher_taches(liste);

    liberer_liste(liste);
}