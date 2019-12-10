/* TPile */
TPile PileVide(); //Renvoie une pile vierge
TPile Empiler(TCarte E, TPile P); //Renvoie une pile dont le dernier élément est E
TPile Depiler(TPile P); //Renvoie une pile dont le dernier élément posé a été enlevé
TCarte Sommet(TPile P); //Renvoie le dernier élément posé d'une pile
bool EstPileVide(TPile P); //Regarde si la pile est vide ou non
void AfficherPile(TPile P); //Affiche une pile sur l'écran
void DesallouerPile(TPile * P); //Désalloue une pile de la mémoire

/* Creation */
void creerListeCarte(TListeCarte * liste);
//void creerPartie(TPartie * Partie)
void afficherListeCarte(TListeCarte liste);
void libererListeCarte (TListeCarte * liste);

/* FonctionsPouvoirs */
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


