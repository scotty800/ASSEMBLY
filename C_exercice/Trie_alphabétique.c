#include <stdio.h>
#include <stdlib.h>

 int comparer(const char *a, const char *b)
 {
  int i = 0;
  while (a[i] && b[i])
  {
    if(a[i] != b[i])
    {
      return a[i] - b[i];
    }
    i++;
  }
  return a[i] - b[i];
 }

 void echange(char *a, char *b)
 {
  char tmp[100];
  int i = 0;

  while ((tmp[i] = a[i])) i++;
  i = 0;
  while ((a[i] = b[i])) i++;
  i = 0;
  while ((b[i] = tmp[i])) i++;
 }

void trier(char mots[][100], int n)
{
  int i, j;

  for(i = 0; i < n - 1; i++) {
    for(j = 0; j < n - 1 - i; j++) {
      if (comparer(mots[j], mots[j + 1]) > 0) {
        echange(mots[j], mots[j + 1]);
      }
    }
  }
}

int main() {
  char mots[5][100];
  int i;
  for (i = 0; i < 5; i++) {
    printf("Mot %d : ", i + 1);
    scanf("%99s", mots[i]);
  }

  trier(mots, 5);
  
  printf("\nMots triés :\n");
  for (i = 0; i < 5; i++) {
    printf("%s\n", mots[i]);
  }
  return 0;
}