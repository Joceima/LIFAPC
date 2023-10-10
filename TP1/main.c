
#include "element.h"
#include "liste.h"
#include <stdio.h>

int main()
{
  Liste l1;
  printf("l1\n");
  initialiseListeDefaut(&l1);
  affichageListe(l1);
  printf("\n");
  ajoutEnTeteListe(1, &l1);
  affichageListe(l1);
  printf("\n");
  ajoutEnTeteListe(2, &l1);
  affichageListe(l1);
  printf("\n");

  Liste lili;
  int i;
  initialiseListeDefaut(&lili);
  printf("Lili\n");
  affichageListe(lili);
  for(i=1;i<5;i++)
    ajoutEnTeteListe(i,&lili);
  printf("Lili\n");
  affichageListe(lili);
  for(i=10;i<15;i++)
    ajoutEnQueueListe(i,&lili);
  printf("Lili\n");
  affichageListe(lili);
  
  Liste lolo;
  initialiseListeCopie(&lolo,lili);
  printf("Lolo\n");
  affichageListe(lolo);
  videListe(&lili);

  ajoutEnQueueListe(100,&lili);
  printf("Lili\n");
  affichageListe(lili);
  printf("Lolo\n");
  affichageListe(lolo);
  affectationListe(&lolo,lili);
  printf("Lolo\n");
  affichageListe(lolo);
  testamentListe(&lili);
  testamentListe(&lolo); 
  return 0;
}
