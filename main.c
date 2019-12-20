#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "types.c"
#include "fonctions.c"
#include "TPile.c"
#include "creation.c"
#include "SousFonctions.c"
#include "FonctionsTour.c"
#include "FonctionsPouvoirs.c"
#include "FonctionsEffets.c"
#include "FonctionsTests.c"

//Fonctions


//Programme Principal
int main() {
	TListeCarte liste;
	liste.debut = NULL;
	creerListeCarte(&liste);
	TPartie Partie;
	creerPartie(&Partie, &liste);    

	while (EstPileVide(Partie.pioche) == false &&
        ComptePile(Partie.Joueurs[0].totem) != 6 &&
        ComptePile(Partie.Joueurs[1].totem) != 6 &&
        ComptePile(Partie.Joueurs[2].totem) != 6)
    {
		JouerTour(&Partie);
		Partie.joueurActuel = (Partie.joueurActuel + 1) % 3;        
	}
	FinPartie(&Partie);
    
    return 0;
}


//Définition des Fonctions
