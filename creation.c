#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// **************************
//  prototypes des fonctions
// **************************

void creerListeCarte (TListeCarte * liste);
void creerPartie(TPartie * Partie, TListeCarte * liste)
void afficherListeCarte(TListeCarte liste);
void libererListeCarte (TListeCarte * liste);
void creerPileCarte(TListeCarte * liste, TPile * pioche);
int nbalea (int min, int max);
void supprimerListeCarte (TListeCarte * liste , int i);
TCarte rechercheCarte(TListeCarte liste, int i);

//Procédure pour créer la partie
void creerPartie(TPartie * Partie, TListeCarte * liste)
{
	TPile * pointeurVersPile;

	creerPileCarte(liste, pointeurVersPile);
	(* Partie).pioche = (* pointeurVersPile);
	free(pointeurVersPile);

	(* Partie).joueurActuel = 0;
	(* Partie).prochainJoueur = 1;

	for(int i = 0; i < 3; i++)
	{
		printf ("Veuillez saisir le nom d'un joueur (max 16char)");
		scanf("(%s)\n", (* Partie).Joueurs[i].nom);
		for(int j = 0; j < 5; j++)
		{
			AjouterCarteMain( p, Sommet((*p).pioche), joueur);
		}
		(* Partie).Joueurs[i].score = 0;
		(* Partie).Joueurs[i].totem = PileVide();
		(* Partie).Joueurs[i].estProtegeVol = false;
		(* Partie).Joueurs[i].estProtegeDestr = false;
		(* Partie).Joueurs[i].estEffetLynx = false;
	}

}

// procédure pour créer la liste
void creerListeCarte (TListeCarte * liste)
{
	int nbcarte;
	nbcarte= 0;

	TCell * aux;
	TCell * prec;
	TCell * newCell; // pointeur vers la nouvelle cellule
	int i;
	aux = (*liste).debut;

	newCell = (TCell*) malloc(sizeof(TCell));
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
		newCell = (TCell*) malloc(sizeof(TCell));
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
		newCell = (TCell*) malloc(sizeof(TCell));
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
		newCell = (TCell*) malloc(sizeof(TCell));
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
		newCell = (TCell*) malloc(sizeof(TCell));
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
		newCell = (TCell*) malloc(sizeof(TCell));
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
		newCell = (TCell*) malloc(sizeof(TCell));
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
		newCell = (TCell*) malloc(sizeof(TCell));
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
		newCell = (TCell*) malloc(sizeof(TCell));
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
		newCell = (TCell*) malloc(sizeof(TCell));
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
		newCell = (TCell*) malloc(sizeof(TCell));
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
		newCell = (TCell*) malloc(sizeof(TCell));
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
		newCell = (TCell*) malloc(sizeof(TCell));
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
		newCell = (TCell*) malloc(sizeof(TCell));
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

// procédure pour afficher une liste carte
void afficherListeCarte(TListeCarte liste)
{
		TCell * aux;
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

// procédure pour libérer une liste carte
void libererListeCarte (TListeCarte * liste)
{
	TCell * aux;
  aux = (*liste).debut;

    while(aux != NULL){
        aux =(*aux).suivant;
        free((*liste).debut);
        (*liste).debut=aux;
    }
}

void creerPileCarte(TListeCarte * liste, TPile * pioche)
{
    int nb, min, max;
		TCarte carte;

    nb = 0;
    min = 1;
    max = 59;

    while ((*liste).debut != NULL){
        nb = nbalea(min,max);
				carte = rechercheCarte((*liste),nb);
        (*pioche) = Empiler(carte, (*pioche));
				supprimerListeCarte(liste,nb);
				max--;
    }

}

int nbalea (int min, int max)
{
    return (min + (rand () % (max-min+1)));
}

void supprimerListeCarte (TListeCarte * liste , int i)
{
		TCell * aux;
    TCell * prec;
    bool trouver;
    int nb;

    aux = (*liste).debut;
    prec = (*liste).debut;
    trouver = false;
    nb=1;

   while (!trouver && aux != NULL){
        if(nb==i && aux==prec){
            aux =(*aux).suivant;
            free((*liste).debut);
            (*liste).debut=aux;
            trouver=true;
        }else{
            if(nb==i){
                trouver = true;
                (*prec).suivant = (*aux).suivant;
                free(aux);
            }else{
               prec=aux;
               aux =(*aux).suivant;
                nb++;
            }
        }
    }
}

TCarte rechercheCarte(TListeCarte liste, int i)
{
		TCell * aux;
    bool trouver;
    TCarte carte;
		int nb;

    aux = liste.debut;
    trouver = false;
    nb=1;

    while(aux != NULL && !trouver){
         if(nb==i){
              trouver = true;
              strcpy(carte.nom, (*aux).carte.nom);
	          	strcpy(carte.desc, (*aux).carte.desc) ;
              carte.icone = (*aux).carte.icone;
              carte.pouvoir = (*aux).carte.pouvoir;
              carte.type = (*aux).carte.type;
         }else{
            aux =(*aux).suivant;
            nb++;
         }
    }
    return carte;
}
