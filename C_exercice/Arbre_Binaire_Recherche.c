#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int valeur;
    struct Node *gauche;
    struct Node *droite;
} Node;

Node *createNoeud(Node *racine, int val)
{
    Node *Nouveau;

    Nouveau = malloc(sizeof(Node));
    if (Nouveau == NULL)
    {
        printf("Erreur allocation mémoire\n");
        exit(1);
    }
    Nouveau->valeur = val;
    Nouveau->gauche = NULL;
    Nouveau->droite = NULL;

    return Node;
}

Node *insert(Node *racine, int val)
{
    if (racine == NULL)
    {
        return createNoeud(val);
    }

    if (val < racine->valeur)
    {
        racine->gauche = insert(racine->gauche, val);
    }
    else if (val > racine->valeur)
    {
        racine->droite = insert(racine->droite, val);
    }

    return racine;
}

void parcoursInfixe(Node *racine)
{
    if(!racine)
        return;

    parcoursInfixe(racine->gauche);
    printf("%d", racine->valeur);
    parcoursInfixe(racine->droite);
}

int rechercher(Node *racine, int val)
{
    if (racine == NULL)
    {
        return 0;
    }

    if(racine->valeur == val)
    {
        return 1;
    }

    if(val < racine->valeur)
    {
        return rechercher(racine->gauche, val);
    }
    else
    {
        return rechercher(racine->droite, val);
    }
}

// Trouve le minimum dans un arbre (utile pour la suppression)
Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->gauche != NULL)
        current = current->gauche;
    return current;
}

// Supprimer un nœud, retourne la nouvelle racine
Node *supprimerNoeud(Node *racine, int val)
{
    if (!racine)
        return racine;

    if (val < racine->valeur)
        racine->gauche = supprimerNoeud(racine->gauche, val);
    else if (val > racine->valeur)
        racine->droite = supprimerNoeud(racine->droite, val);
    else
    {
        // cas 1: pas d'enfant ou 1 enfant
        if (racine->gauche == NULL)
        {
            Node *temp = racine->droite;
            free(racine);
            return temp;
        }
        else if (racine->droite == NULL)
        {
            Node *temp = racine->gauche;
            free(racine);
            return temp;
        }

        // cas 2: 2 enfants
        Node *temp = minValueNode(racine->droite);
        racine->valeur = temp->valeur;
        racine->droite = supprimerNoeud(racine->droite, temp->valeur);
    }
    return racine;

}

int hauteur(Node *racine)
{
    int gauche;
    int droite;

    if (racine == NULL)
    {
        return 0;
    }
    
    gauche = hauteur(racine->gauche);
    droite = hauteur(racine->droite);
    return (gauche > droite ? gauche : droite) + 1;
}

void parcoursNiveaux(Node *racine)
{
    if(!racine)
        return;
}

void libererArbre(Node *racine)
{
    if(racine)
    {
        libererArbre(racine->gauche);
        libererArbre(racine->droite);
        free(racine);
    }
}

int main()
{
    Node *nb = NULL;
    int value;
    int choix;

    while (1)
    {
        printf("\n=== MENU ABR ===\n");
        printf("1. Insérer un nombre\n");
        printf("2. Parcours infixe (trié)\n");
        printf("3. Parcours préfixe\n");
        printf("4. Parcours postfixe\n");
        printf("5. Rechercher un nombre\n");
        printf("6. Supprimer un nombre\n");
        printf("7. Hauteur de l'arbre\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            printf("Insérer un nombre : ");
            scanf("%d", &value);
            nb = insert(nb, value);
            break;
        case 2:
            printf("Parcours infixe : ");
            parcoursInfixe(nb);
            printf("\n");
            break;
        case 3:
            printf("Parcours préfixe : ");
            parcoursPrefixe(nb);
            printf("\n");
            break;
        case 4:
            printf("Parcours postfixe : ");
            parcoursPostfixe(nb);
            printf("\n");
            break;
        case 5:
            printf("Nombre à rechercher : ");
            scanf("%d", &value);
            if (rechercher(nb, value))
                printf("Nombre trouvé !\n");
            else
                printf("Nombre non trouvé !\n");
            break;
        case 6:
            printf("Nombre à supprimer : ");
            scanf("%d", &value);
            nb = supprimerNoeud(nb, value);
            break;
        case 7:
            printf("Hauteur de l'arbre : %d\n", hauteur(nb));
            break;
        case 0:
            libererArbre(nb);
            printf("Au revoir !\n");
            return 0;
        default:
            printf("Choix invalide.\n");
            break;
        }
    }
}