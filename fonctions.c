/* TPile */
TPile PileVide(); //Renvoie une pile vierge
TPile Empiler(TCarte E, TPile P); //Renvoie une pile dont le dernier élément est E
TPile Depiler(TPile P); //Renvoie une pile dont le dernier élément posé a été enlevé
TCarte Sommet(TPile P); //Renvoie le dernier élément posé d'une pile
bool EstPileVide(TPile P); //Regarde si la pile est vide ou non
void AfficherPile(TPile P); //Affiche une pile sur l'écran
void DesallouerPile(TPile * P); //Désalloue une pile de la mémoire

/* Creation */
void creerListeCarte (TListeCarte * liste);
//void creerPartie(TPartie * Partie);
void afficherListeCarte(TListeCarte liste);
void libererListeCarte (TListeCarte * liste);
void creerPileCarte(TListeCarte * liste, TPile * pioche);
int nbalea (int min, int max);
void supprimerListeCarte (TListeCarte * liste , int i);
TCarte rechercheCarte(TListeCarte liste, int i);

/* FonctionsTour */
void JouerCarte(TPartie * p, TCarte c); 
void FauxPas(TPartie * partie, TPile * cartes, int joueurs[3], int pntVersJ);
void ExecuterLynx(TPartie * p);
void PiocherCarte(TPartie * p, int joueur);
bool PossedeFauxPas(TPartie p, int joueur);
bool FinPartie(TPartie * p);
void AfficherCarte(TCarte c);
void AfficherMain(TPartie p, int joueur);
TCarte ChoisirCarte(TPartie * p);
void JouerTour(TPartie * p);


/* FonctionsPouvoirs */
void EffetPouvoir(TCarte Carte, TPartie * Partie);
void IntervertirTotems(TPartie * Partie);
void CartePillage(TPartie * Partie, int joueurPille);
void CadeauTotem(TPartie * Partie, int vitime, int gagnant);

/* FonctionsEffets */
void EffetTotem(TCarte Carte, TPartie * Partie);
void VolerTotem(TPartie * Partie, int JoueurVictime);
void ImmuniteVol(TPartie * Partie);
void ImmuniteDestr(TPartie * Partie);
void VolerCarteNum(TPartie * Partie, int numCarte, int numJoueur);
void DetruireEtage(TPartie * Partie, int numJoueur);
void EchangerMain(TPartie * Partie, int numJoueur);//Echange la main du joueur courant avec le joueur passé en params


