#include <stdio.h>
#include <stdlib.h>

int compter_lettre(const char *str, char lettre)
{
  int i = 0, count = 0;
  while(str[i] != '\0')
  {
    if (str[i] == lettre)
    {
      count++;
    }
    i++;
  }

  return count;
}

void lire_chaine(char *buffer, int taille)
{
  int c, i = 0;

  while ((c = getchar()) != '\n' && i < taille - 1)
  {
    buffer[i++] = c;
  }

  buffer[i] = '\0';

}

int main() {
  char *chaine[3];
  char rechercher;
  int i, nb;

  for (i = 0; i < 3; i++)
  {
    chaine[i] = malloc(sizeof(char) * 100);
    if (chaine[i] == NULL)
    {
      return -1;
    }
    printf("Chaine %d : ", i + 1);
    lire_chaine(chaine[i], 100);
  }

  printf("Lettre à rechercher : ");
  rechercher = getchar();
  getchar();

  for (i = 0; i < 3; i++)
  {
    nb = compter_lettre(chaine[i], rechercher);
    printf("La lettre '%c' apparait %d fois dans la chaine %d\n ", rechercher, nb, i + 1);
    free(chaine[i]);
  }
  return 0;
}