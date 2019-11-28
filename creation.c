#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ************************************
// definition des types : liste chainee
// ************************************


typedef struct __TJoueur{
		int num;
		int nom;
		TListeCarte main;
		int score;
		Tpile totem;
}TJoueur;

typedef struct _TPartie
{
	TJoueur joueur1;
	TJoueur joueur2;
	TJoueur joueur3;
	Tpile pioche;
	int choixJoueur;
}TPartie;

typedef struct _TCarte
{
	char nom[25];
	char desc[150];
  int icone;
  int pouvoir;
  int type;
} TCarte;

typedef struct _Tcell
{
	TCarte carte; // un etudiant -- liste TRIEE
	struct _Tcell * suivant;
} Tcell;

typedef struct _TListeCarte
{
	Tcell * debut;  // liste TRIEE sur le nom et prénom des étudiants
} TListeCarte;

// **************************
//  prototypes des fonctions
// **************************
void creerListeCarte (TListeCarte * liste);
//void creerPartie(TPartie * Partie)
void afficherListeCarte(TListeCarte liste);
void libererListeCarte (TListeCarte * liste);


// **********************
//  programme principal
// **********************
int main ()
{

    TListeCarte liste;
		liste.debut = NULL;
		creerListeCarte(&liste);
		//afficherListeCarte(liste);
		libererListeCarte(&liste);
		printf("Si rien après ok");
		afficherListeCarte(liste);

	// CONTINUER LE PROGRAMME PRINCIPAL - FAIRE UN MENU

	return 0;
}


// procédure pour créer la liste
void creerListeCarte (TListeCarte * liste)
{
	int nbcarte;
	nbcarte= 0;

	Tcell * aux;
	Tcell * prec;
	Tcell * newCell; // pointeur vers la nouvelle cellule
	int i;
	aux = (*liste).debut;

	newCell = (Tcell*) malloc(sizeof(Tcell));
	strcpy((*newCell).carte.nom,"Tête de coyote");
	strcpy((*newCell).carte.desc,"Lorsque la carte arrive en jeu, vous pouvez voler le totem d'un joueur et lui donner le vôtre.");
	(*newCell).carte.icone = 2;
	(*newCell).carte.pouvoir = 1;
	(*newCell).carte.type =1;
	(*newCell).suivant = NULL;

  aux = newCell;
	prec = aux;
	(*liste).debut = aux;
	aux = (*aux).suivant;

	i =0;
	nbcarte =4;

	//Création des cartes totem
	while (i<nbcarte){
		newCell = (Tcell*) malloc(sizeof(Tcell));
		strcpy((*newCell).carte.nom,"Tête de coyote");
		strcpy((*newCell).carte.desc,"Lorsque la carte arrive en jeu, vous pouvez voler le totem d'un joueur et lui donner le vôtre.");
		(*newCell).carte.icone = 2;
		(*newCell).carte.pouvoir = 1;
		(*newCell).carte.type =1;
		(*newCell).suivant = NULL;

		i = i+1;
		aux= newCell;
		(*prec).suivant = aux;
		prec = aux;
		aux = (*aux).suivant;
	}

	i = 0;
	nbcarte =5;
	while (i<nbcarte){
		newCell = (Tcell*) malloc(sizeof(Tcell));
		strcpy((*newCell).carte.nom,"Tête d'aigle");
		strcpy((*newCell).carte.desc,"Aucun joueur ne peut vous voler votre totem ou des étages de votre totem.");
		(*newCell).carte.icone = 4;
		(*newCell).carte.pouvoir = 2;
		(*newCell).carte.type =1;
		(*newCell).suivant = NULL;

		i = i+1;
		aux= newCell;
		(*prec).suivant = aux;
		prec = aux;
		aux = (*aux).suivant;
	}

	i = 0;

	while (i<nbcarte){
		newCell = (Tcell*) malloc(sizeof(Tcell));
		strcpy((*newCell).carte.nom ,"Tête de loup");
		strcpy((*newCell).carte.desc, "Lorque la carte arrive en jeu, vous pouvez voler 2 cartes au hasard dans la main d'un joueur adverse.");
		(*newCell).carte.icone = 0;
		(*newCell).carte.pouvoir = 3;
		(*newCell).carte.type =1;
		(*newCell).suivant = NULL;

		i = i+1;
		aux= newCell;
		(*prec).suivant = aux;
		prec = aux;
		aux = (*aux).suivant;
	}

	i = 0;

	while (i<nbcarte){
		newCell = (Tcell*) malloc(sizeof(Tcell));
		strcpy((*newCell).carte.nom ,"Tête de corbeau");
		strcpy((*newCell).carte.desc ,"Lorque la carte arrive en jeu, vous pouvez échanger votre main avec celle d'un autre joueur.");
		(*newCell).carte.icone = 0;
		(*newCell).carte.pouvoir = 4;
		(*newCell).carte.type =1;
		(*newCell).suivant = NULL;

		i = i+1;
		aux= newCell;
		(*prec).suivant = aux;
		prec = aux;
		aux = (*aux).suivant;
	}

	i = 0;
nbcarte =5;
	while (i<nbcarte){
		newCell = (Tcell*) malloc(sizeof(Tcell));
		strcpy((*newCell).carte.nom ,"Tête de lynx");
		strcpy((*newCell).carte.desc ,"A la fin de chacun de vos tours, vous pouvez piocher 3 cartes, en choisir une puis défausser les 2 autres.");
		(*newCell).carte.icone =0;
		(*newCell).carte.pouvoir = 5;
		(*newCell).carte.type =1;
		(*newCell).suivant = NULL;

		i = i+1;
		aux= newCell;
		(*prec).suivant = aux;
		prec = aux;
		aux = (*aux).suivant;
	}

	i = 0;

	while (i<nbcarte){
		newCell = (Tcell*) malloc(sizeof(Tcell));
		strcpy((*newCell).carte.nom ,"Tête de tortue");
		strcpy((*newCell).carte.desc ,"Aucun joueur ne peut détruire votre totem ou des étages de votre totem.");
		(*newCell).carte.icone = 3;
		(*newCell).carte.pouvoir = 6;
		(*newCell).carte.type =1;
		(*newCell).suivant = NULL;

		i = i+1;
		aux= newCell;
		(*prec).suivant = aux;
		prec = aux;
		aux = (*aux).suivant;
	}

	i = 0;

	while (i<nbcarte){
		newCell = (Tcell*) malloc(sizeof(Tcell));
		strcpy((*newCell).carte.nom ,"Tête d'ours'");
		strcpy((*newCell).carte.desc ,"Lorque la carte arrive en jeu, vous pouvez détruire le dernier étage du totem d'un joueur.");
		(*newCell).carte.icone = 1;
		(*newCell).carte.pouvoir = 7;
		(*newCell).carte.type =1;
		(*newCell).suivant = NULL;

		i = i+1;
		aux= newCell;
		(*prec).suivant = aux;
		prec = aux;
		aux = (*aux).suivant;
	}

	i = 0;
	nbcarte =3;

	while (i<nbcarte){
		newCell = (Tcell*) malloc(sizeof(Tcell));
		strcpy((*newCell).carte.nom , "Esprit farceur !");
		strcpy((*newCell).carte.desc ,"Chaque joueur doit donner son totem au joueur se trouvant à sa gauche.");
		(*newCell).carte.icone = 0;
		(*newCell).carte.pouvoir = 8;
		(*newCell).carte.type =2;
		(*newCell).suivant = NULL;

		i = i+1;
		aux= newCell;
		(*prec).suivant = aux;
		prec = aux;
		aux = (*aux).suivant;
	}

	i = 0;
	nbcarte =3;

	while (i<nbcarte){
		newCell = (Tcell*) malloc(sizeof(Tcell));
		strcpy((*newCell).carte.nom , "Bison dingo !");
		strcpy((*newCell).carte.desc ,"Détruisez les 2 derniers étages d'un totem.");
		(*newCell).carte.icone = 1;
		(*newCell).carte.pouvoir = 9;
		(*newCell).carte.type =2;
		(*newCell).suivant = NULL;

		i = i+1;
		aux= newCell;
		(*prec).suivant = aux;
		prec = aux;
		aux = (*aux).suivant;
	}

	i = 0;
	nbcarte =5;
	while (i<nbcarte){
		newCell = (Tcell*) malloc(sizeof(Tcell));
		strcpy((*newCell).carte.nom,"Faux pas !");
		strcpy((*newCell).carte.desc,"Annulez l'action d'un joueur, si vous annulez un autre ' Faux pas !', piochez 2 cartes, sinon rejouez immédiatement.");
		(*newCell).carte.icone = 0;
		(*newCell).carte.pouvoir = 10;
		(*newCell).carte.type =2;
		(*newCell).suivant = NULL;

		i = i+1;
		aux= newCell;
		(*prec).suivant = aux;
		prec = aux;
		aux = (*aux).suivant;
	}

	i = 0;
	nbcarte =5;
	while (i<nbcarte){
		newCell = (Tcell*) malloc(sizeof(Tcell));
		strcpy((*newCell).carte.nom , "Pillage !");
		strcpy((*newCell).carte.desc, "Volez et mettez dans votre main le dernier étage du totem d'un joeur. Si vous avez moins de 4 totems, rejouez immédiatement.");
		(*newCell).carte.icone = 2;
		(*newCell).carte.pouvoir = 11;
		(*newCell).carte.type =2;
		(*newCell).suivant = NULL;

		i = i+1;
		aux= newCell;
		(*prec).suivant = aux;
		prec = aux;
		aux = (*aux).suivant;
	}

	i = 0;
	nbcarte =4;
	while (i<nbcarte){
		newCell = (Tcell*) malloc(sizeof(Tcell));
		strcpy((*newCell).carte.nom , "Cadeau !");
		strcpy((*newCell).carte.desc, "Volez une tête au sommet d'un totem pour le placez au sommet d'un totem adverse, puis piochez 1 carte");
		(*newCell).carte.icone = 1;
		(*newCell).carte.pouvoir = 12;
		(*newCell).carte.type =2;
		(*newCell).suivant = NULL;

		i = i+1;
		aux= newCell;
		(*prec).suivant = aux;
		prec = aux;
		aux = (*aux).suivant;
	}

	i = 0;
	nbcarte =4;
	while (i<nbcarte){
		newCell = (Tcell*) malloc(sizeof(Tcell));
		strcpy((*newCell).carte.nom, "Eau de feu !");
		strcpy((*newCell).carte.desc, "Piochez 2 cartes puis rejouez immédiatement.");
		(*newCell).carte.icone = 0;
		(*newCell).carte.pouvoir = 13;
		(*newCell).carte.type =2;
		(*newCell).suivant = NULL;
		i = i+1;
		aux= newCell;
		(*prec).suivant = aux;
		prec = aux;
		aux = (*aux).suivant;
	}


}

// procédure pour afficher une liste d'Etudiants
void afficherListeCarte(TListeCarte liste)
{
		Tcell * aux;
    aux = liste.debut;
    while(aux != NULL){
        printf("Information de la carte :");
        printf("%s\n",(*aux).carte.nom);
        printf("%s\n",(*aux).carte.desc);
        printf("%d\n",(*aux).carte.icone);
        printf("%d\n",(*aux).carte.pouvoir);
        printf("%d\n\n",(*aux).carte.type);
        aux = (*aux).suivant;
    }

}

// procédure pour libérer une liste d'Etudiants
void libererListeCarte (TListeCarte * liste)
{
	Tcell * aux;
  aux = (*liste).debut;

    while(aux != NULL){
        aux =(*aux).suivant;
        free((*liste).debut);
        (*liste).debut=aux;
    }
}
