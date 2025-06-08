#include <stdio.h>
#include <stdlib.h>

typedef struct Chanson
{
    char titre[100];
    int duree;
    struct Chanson *prev;
    struct Chanson *next;
} Chanson;

char *my_strcpy(char *s, char *s2)
{
    int i = 0;

    while(s2[i] != '\0')
    {
        s[i] = s2[i];
        i++;
    }
    s[i] = '\0';

    return s;
}

char my_strcmp(char *s, char *s2)
{
    int i = 0;

    while(s[i] != '\0' && s2[i] != '\0')
    {
        if(s[i] != s2[i])
        {
            return (unsigned char)s[i] - (unsigned char)s2[i];
        }
        i++;
    }
    return (unsigned char)s[i] - (unsigned char)s2[i];
}

Chanson *createNode(char *titre, int duree)
{
    Chanson *Nouveau;
    Nouveau = malloc(sizeof(Chanson));
    if(!Nouveau)
    {
        printf("Erreur d'Allocation !");
        exit(1);
    }
    my_strcpy(Nouveau->titre, titre);
    Nouveau->duree = duree;
    Nouveau->prev = NULL;
    Nouveau->next = NULL;

    return Nouveau;
}

void pushFront(Chanson **head, char *titre, int duree)
{
    Chanson *Nouveau = createNode(titre, duree);

    Nouveau->next = *head;

    if(*head != NULL)
    {
        (*head)->prev = Nouveau;
        return;
    }
    *head = Nouveau;
}

void pushBack(Chanson **head, char *titre, int duree)
{
    Chanson *Nouveau = createNode(titre, duree);
    
    if(*head == NULL)
    {
        *head = Nouveau;
        return;
    }

    Chanson *tmp = *head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = Nouveau;
    Nouveau->prev = tmp;
}

void deleteByTitle(Chanson **head, char *titre)
{
    if (*head == NULL) {
        printf("Playlist vide !\n");
        return;
    }

    Chanson *tmp = *head;

    while (tmp) {
        if (my_strcmp(tmp->titre, titre) == 0) {
            if (tmp->prev)
                tmp->prev->next = tmp->next;
            else
                *head = tmp->next;
            if (tmp->next)
                tmp->next->prev = tmp->prev;
            free(tmp);
            printf("Chanson supprimée !\n");
            return;
        }
        tmp = tmp->next;
    }

    printf("Titre introuvable !\n");
}


void printForward(Chanson *head)
{
    if(head == NULL)
    {
        printf("Playlist vide !");
        return;
    }

    while(head)
    {
        printf("%s : %d", head->titre, head->duree);

        if(head->next)
        {
            printf(" <-> ");
        }
        head = head->next;
    }
    printf("\n");
}

void printBackward(Chanson *head)
{
    if(head == NULL)
    {
        printf("Playlist vide !");
        return;
    }
    
    while(head->next)
    {
        head = head->next;
    }

    while(head)
    {
        printf("%s : %d", head->titre, head->duree);
        if(head->prev)
        {
            printf(" <-> ");
        }
        head = head->prev;
    }
    printf("\n");
}

int searchTitle(Chanson *head, char *titre)
{
    if(head == NULL)
    {
        printf("Playlist vide !");
        exit(1);
    }

    while(head)
    {
        if(my_strcmp(head->titre, titre))
        {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main()
{
    Chanson *Playlist = NULL;
    char titre[100];
    int duree;
    int choix;

    while(1)
    {
        printf("=== MENU PLAYLIST ===\n");
        printf("1. Ajouter au début\n");
        printf("2. Ajouter à la fin\n");
        printf("3. Supprimer une chanson par titre\n");
        printf("4. Afficher (ordre normal)\n");
        printf("5. Afficher (ordre inverse)\n");
        printf("6. Rechercher une chanson\n");
        printf("0. Quitter\n");
        scanf("%d", &choix);
        switch(choix)
        {
            case 1:
            printf("Titre : ");
            scanf("%s", titre);
            printf("Durée (en sec) : ");
            scanf("%d", &duree);
            pushFront(&Playlist, titre, duree);
            break;
        case 2:
            printf("Titre : ");
            scanf("%s", titre);
            printf("Durée (en sec) : ");
            scanf("%d", &duree);
            pushBack(&Playlist, titre, duree);
            break;
        case 3: 
            printf("Titre : ");
            scanf("%s", titre);
            deleteByTitle(&Playlist, titre);
            break;
        case 4:
            printForward(Playlist);
            break;
        case 5:
            printBackward(Playlist);
            break;
        case 6:
            printf("Search-Titre : ");
            scanf("%s", titre);
            if(searchTitle(Playlist, titre))
                printf("Chanson trouvée !\n");
            else
                printf("Chanson introuvable.\n");
            break;
        case 0:
            printf("Au revoir !\n");
            return 0;
        }
        
    }
}