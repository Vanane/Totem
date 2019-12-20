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
int main(){

    TListeCarte liste;
    liste.debut = NULL;
    creerListeCarte(&liste);
    TPartie Partie;
    creerPartie(&Partie,&liste);

    
    return 0;
}


//Définition des Fonctions
