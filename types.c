typedef struct _TCarte
{
	char nom[25];
	char desc[150];
    int icone;
    int pouvoir;
    int type;
} TCarte;

typedef struct _TCell
{
	TCarte carte; // un etudiant -- liste TRIEE
	struct _TCell * suivant;
} TCell;

typedef struct _TListeCarte
{
	TCell * debut;  // liste TRIEE sur le nom et prénom des étudiants
} TListeCarte;

typedef struct _TElem{
  TCarte elem;
  struct _TElem * suivant;
}TElem;

typedef struct _TPile{
  TElem * debut; //Init à PileVide()
}TPile;

typedef struct __TJoueur{
		char nom[16]; //Init à vide
		TListeCarte main; // Init à vide
		int score; //init à 0
		TPile totem; //init à vide
		bool estProtegeVol; //Init à faux
		bool estProtegeDestr; //Init à faux
		bool estEffetLynx; //Init à faux

}TJoueur;

typedef struct _TPartie
{
	TJoueur Joueurs[3];
	TPile pioche;
	int joueurActuel; //Init à 0
	int prochainJoueur; //init à 1
}TPartie;

