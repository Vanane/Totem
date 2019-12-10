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

typedef struct __TJoueur{
		char nom[16];
		TListeCarte main;
		int score;
		TPile totem;
}TJoueur;

typedef struct _TPartie
{
	TJoueur Joueurs[3];
	TPile pioche;
	int joueurActuel;
}TPartie;

typedef struct _TElem{
  TCarte elem;
  struct _TElem * suivant;
}TElem;

typedef struct _TPile{
  TElem * debut;
}TPile;
