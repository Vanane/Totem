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

	while (EstPileVide(Partie.pioche) == false AND ComptePile((*Partie).Joueur[0].Totem) != 6 AND ComptePile((*Partie).Joueur[1].Totem) != 6 AND ComptePile((*Partie).Joueur[2].Totem) != 6)){

		JouerTour(&Partie);
		Partie.joueurActuel++;
		if (Partie.joueurActuel = 3) {
			Partie.joueurActuel = 0;
		}
		Partie.prochainJoueur++;
		if (Partie.prochainJoueur = 3) {
			Partie.prochainJoueur = 0;
		}
	}
	FinPartie(&Partie);
    
    return 0;
}


//Définition des Fonctions
