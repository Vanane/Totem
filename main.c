#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "creation.c"
#include "TPile.c"
#include "SousFonctions.c"
#include "FonctionsPouvoirs.c"
#include "FonctionsEffets.c"
#include "FonctionsTour.c"

//Permet de définir le type contenu dans la pile, pour ce programme. A voir si c'est utile de le garder ou non
#undef TYPEPILE
#define TYPEPILE TCarte


//Fonctions


//Programme Principal
int main(){

    TListeCarte liste;
    liste.debut = NULL;
    creerListeCarte(&liste);
    afficherListeCarte(liste);
    libererListeCarte(&liste);
    printf("Si rien après ok");

	// CONTINUER LE PROGRAMME PRINCIPAL - FAIRE UN MENU
    scanf("%d");
    return 0;
}


//Définition des Fonctions

