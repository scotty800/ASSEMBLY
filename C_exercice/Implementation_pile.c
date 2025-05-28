#include <stdio.h>
#include <stdlib.h>

typedef enum TypeOperation
{
  PUSH,
  POP,
  PEEK
} TypeOperation;

typedef struct Element
{
  int valeur;
  enum TypeOperation type;
  struct Element *next;
} Element;

void empiler(Element **pile, int val)
{
  Element *Nouveau;
  Nouveau = malloc(sizeof(Element));
  Nouveau->type = PUSH;
  Nouveau->valeur = val;
  Nouveau->next = *pile;
  *pile = Nouveau;
}

int depiler(Element **pile)
{
  Element *tmp = *pile; 
  int val;

  if (*pile == NULL)
  {
    return -1;
  }

  val = tmp->valeur;
  tmp->type = POP;
  *pile = tmp->next;

  free(tmp);
  return val;
}

void afficher_pile(Element *pile)
{
  Element *actuel = pile;
  const char *typeStr;
  while(actuel)
  {
    typeStr = (actuel->type == PUSH) ? "PUSH" :
              (actuel->type == POP) ? "POP" : "PEEK";
    printf("[Valeur: %d, type: %s]\n", actuel->valeur, typeStr);
    actuel = actuel->next;
  }
}

int main() {
  Element *pile = NULL;
  int val;

  empiler(&pile, 10);
  empiler(&pile, 20);
  empiler(&pile, 30);

  printf("Empilage de 3 valeurs...\n");
  afficher_pile(pile);

  val = depiler(&pile);
  printf("\nDépilage d'une valeur : %d\n", val);
  
  printf("\nPile après dépilage :\n");
  afficher_pile(pile);

  return 0;
}