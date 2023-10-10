#include <stdio.h>
#include <cstdlib>
#include "element.h" /* offrant le type Reel */

/* On rajoute : */
#include "liste.h" 

void initialiseListeDefaut(Liste *pl) 
{
	pl->ad = NULL;
	pl->nb_elem = 0;
}

void initialiseListeCopie(Liste *pl1, Liste l2)
{
    // Initialise la liste pl1 comme une liste vide
    initialiseListeDefaut(pl1);

    // Crée une copie profonde de l2 en parcourant ses éléments
    Cellule *current = l2.ad;
    while (current != NULL)
    {
        Elem element = current->info;
        ajoutEnQueueListe(element, pl1);
        current = current->psuivant;
    }
}

void affectationListe(Liste *pl1, Liste l2)
{
    initialiseListeDefaut(pl1);
    Cellule *current = l2.ad;
    while (current != NULL)
    {
        Elem element = current->info;
        ajoutEnQueueListe(element, pl1);
        current = current->psuivant;
    }
}


int testListeVide(Liste l) 
{
	return l.nb_elem == 0 ;
}

Elem premierElementListe(Liste l)
{
	if( testListeVide(l) ==  0)
	{
		return l.ad->info;
	}
	else{
		return 0;
	}
}

Cellule * premiereCelluleListe(Liste l)
{
	if (testListeVide(l) == 0)
	{
		return l.ad;
	}
	else {
		return 0;
	}
}

Cellule * celluleSuivanteListe(const Cellule *pc, Liste l)
{
	return l.ad->psuivant;
}

Elem elementCelluleListe(const Cellule * pc)
{
	return pc->info;
}

void affichageListe(Liste l)
{
	Cellule *temp = l.ad;
	while(temp != NULL)
	{
		afficheElement(temp->info);
		temp = temp->psuivant;
	}
}

void ajoutEnTeteListe(Elem e, Liste *pl)
{
	Cellule *temp = (Cellule *)malloc(sizeof(Cellule));
	temp->info = e;
    temp->psuivant = pl->ad;
    pl->ad = temp;
    pl->nb_elem = pl->nb_elem + 1;

}

void suppressionEnTeteListe(Liste *pl)
{
    if (testListeVide(*pl))
    {
        return;
    }
    // on garde la première cellule pour la libération de mémoire
    Cellule *premiereCellule = pl->ad;
    // maj cellule suivant
    pl->ad = pl->ad->psuivant;
    free(premiereCellule);
    pl->nb_elem--;
}


void ajoutEnQueueListe(Elem e, Liste *pl)
{
    Cellule *nouvelleCellule = (Cellule *)malloc(sizeof(Cellule));
    nouvelleCellule->info = e;
    nouvelleCellule->psuivant = NULL;
    if (testListeVide(*pl))
    {
        ajoutEnTeteListe(e, pl);
    }
    else
    {
        // Trouver la dernière cellule de la liste
        Cellule *derniereCellule = pl->ad;
        while (derniereCellule->psuivant != NULL)
        {
            derniereCellule = derniereCellule->psuivant;
        }
        // Ajouter la nouvelle cellule à la fin
        derniereCellule->psuivant = nouvelleCellule;
        pl->nb_elem = pl->nb_elem + 1;
    }
}

void testamentListe(Liste *pl)
{
    while (!testListeVide(*pl))
    {
        suppressionEnTeteListe(pl);
    }
    initialiseListeDefaut(pl);
}



void videListe(Liste *pl)
{
    while (!testListeVide(*pl))
    {
        suppressionEnTeteListe(pl);
    }
}
