#include <stdio.h>
#include <stdbool.h>

//************************************
//       Procédure Jouer Carte
//************************************
 // Prend en entrée la carte jouée. En fonction du type et du pouvoir,
 // la partie sera modifiée en conséquence.
 // Les joueurs peuvent à leur tour poser une carte Faux pas,
 // s’ils en ont une. Dans ce cas, la dernière carte jouée est 
 //La carte est supprimée de la main du joueur dont c’est le tour à la fin.

void JouerCarte(TPartie * p, TCarte c)
{
    int joueurActuel;
    int joueursFauxPas[3]; //Contient l'ordre des joueurs qui posent les cartes
    int pointeurVersCase = 0; //Permet de savoir quelle case regarder pour traiter chaque carte
    TPile cartes;

    joueursFauxPas[0] = (* p).joueurActuel;

    cartes = PileVide();
    cartes = Empiler(c, cartes);

    //Carte ajoutée à la pile des cartes jouées
    //On appelle FauxPas
    //On prend la pile de carte si son sommet est un faux pas -> annuler carte
    //Si sommet(Pile) == FauxPas
        //Depiler
        //Sauvegarder Joueur
        //Si sommet(Pile) == Faux pas
            // Joueur pioche 2 cartes
            //Depiler
        //Sinon la carte est remise dans la main du joueur
            //Changement du tour joueur
    
    FauxPas(p, &cartes, joueursFauxPas, pointeurVersCase);

    while(!EstPileVide(cartes))
    {
        if(Sommet(cartes).type==10) // Si c'est un Faux Pas
        {
            cartes = Depiler(cartes);
            if(Sommet(cartes).type==10) //Si la carte en-dessous est un Faux Pas
            {
                PiocherCarte(p, joueursFauxPas[pointeurVersCase]);
                PiocherCarte(p, joueursFauxPas[pointeurVersCase]);
                pointeurVersCase--;
                if(c.type == 1) //Si la carte est de type Totem
                {
                    (* p).Joueurs[(* p).joueurActuel].totem = Empiler(c, (* p).Joueurs[(* p).joueurActuel].totem);
                    EffetTotem(c, p);
                }
                else
                {
                    EffetPouvoir(c, p);
                }
            }
            else
            {                
                (* p).prochainJoueur = pointeurVersCase; //on veut récupérer le possesseur de la carte
                cartes = Depiler(cartes);
                //TODO : Variable prochain joueur ?
            }
        }
        else
        {
            if(c.type == 1) //Si la carte est de type Totem
            {
                (* p).Joueurs[(* p).joueurActuel].totem = Empiler(c, (* p).Joueurs[(* p).joueurActuel].totem);
                EffetTotem(c, p);
            }
            else
                EffetPouvoir(c, p);
        }
    }
    ViderPile(&cartes);
}

void FauxPas(TPartie * partie, TPile * cartes, int joueurs[3], int pntVersJ)
{
    //On demande a chaque joueurs si il veut jouer unfaux pas
    //On le demande tant qu'il y a des joueurs qui peuvent jouer, et qu'au moins une carte a été posée à la dernière boucle.
    // -> ajout carte a la pile
    // -> Appel de la meme methode
    bool r, ajoutFauxPas;
    do
    {
        ajoutFauxPas = false;
        for(int i =0; i<3; i++)
        {
            if(i != (* partie).joueurActuel)
            {
                if(PossedeFauxPas(* partie, i)) //On verifie qu'il possède un faux Pas avant de lui demander si il veut en jouer un
                {
                    r = SaisirReponse("Voulez vous jouez une carte Faux Pas ?\n");
                    if(r)
                    {
                        ajoutFauxPas = true;
                        joueurs[pntVersJ] = i;
                        //TODO: Empiler le Faux Pas du joueur i
                        int posFauxPas = TrouverPositionCarteParID(* partie, 10, i);
                        * cartes = Empiler(TrouverCarteMain(* partie, posFauxPas, i), * cartes);
                        SupprimerCarteMain(partie, posFauxPas, i);
                    }
                }
            }
        }
    }while(ajoutFauxPas);
}


void ExecuterLynx(TPartie * p)
{
    int pos;
    //Exécute l'effet Lynx, si le joueur est propice.
    if((* p).Joueurs[(* p).joueurActuel].estEffetLynx)
    {
        TCarte cartesPiochees[3];
        for(int i = 0; i < 3; i++)
        {
            cartesPiochees[i] = Sommet((* p).pioche);
            AfficherCarte(Sommet((* p).pioche));
            (*p).pioche = Depiler((*p).pioche);
        }

        printf("Quelle carte souhaitez-vous conserver ?\n");
        pos = SaisirEntre(0,2);

        AjouterCarteMain(p, cartesPiochees[pos], (* p).joueurActuel);
    }
}


//************************************
//      Procédure Piocher Carte
//************************************
//Ajoute au deck d'un joueur 2 cartes prises sur le dessus de la pioche

void PiocherCarte(TPartie * p, int joueur)
{
    AjouterCarteMain( p, Sommet((*p).pioche), joueur);
    (*p).pioche = Depiler((*p).pioche);
}



//*********
// Trouver Carte Faux pas
//********
bool PossedeFauxPas(TPartie p, int joueur)
{
    TCell * aux;
    bool ret;
    
    aux = p.Joueurs[p.joueurActuel].main.debut;
    ret = false;

    while(aux != NULL && !ret)
    {
        if((* aux).carte.pouvoir == 10)
            ret = true;
        else
            aux = (* aux).suivant;
    }

    return ret;
}

//************************************
//        Procédure Fin partie
//************************************
// Regarde si la partie est dans un état où le jeu est censé se terminer
// (Aucune carte dans la pioche et au moins un joueur a sa main vide,
// ou bien un joueur possède un totem de 6 têtes).


void FinPartie(TPartie p)
{
    bool EtatFin;
    int J =0;
    int cartes;
    int tailleM;
    int t;
    int gagnant;
    EtatFin = false;

    //On verifie que l'etat est bien fini
    //Si pile vide
    if(EstPileVide(p.pioche))
    {  //parcourir les joueurs
        while(!EtatFin)
       {
            cartes = CompteCartesMain(p, J);
            if(cartes == 0)
            {
                EtatFin = true;
            }
            J++;
        }
    }else{
        while(!EtatFin)
        {
            if(ComptePile(p.Joueurs[J].totem))
            {
                EtatFin = true;
            }
            J++;
        }
    }
    //Vide mémoire
    if(EtatFin)
    {
        //DEFINIR GAGNANT
        for(int i =0; i<3; i++)
        {
            t = ComptePile(p.Joueurs[i].totem);
            if(tailleM < t)
            {
                tailleM = t;
                gagnant = i;
            }
        }        
        printf("Félicitation Joueur %d !! Vous êtes le grand gagnant !", gagnant);

        //SUPPRESSION CARTES, TOTEM et PIOCHE
        for(int y = 0; y <3; y++)
        {
            cartes = CompteCartesMain(p, y);
            while(cartes > 0)
            {
                SupprimerCarteMain(p, cartes, y);
                cartes --;
            }
            while(ComptePile(p.Joueurs[y].totem)>0)
            {
                depiler(p.Joueurs[y].totem);
            }
            desallouer((*)p.Joueurs[y].totem);
            //Pointeur vers la pile attendu
        }
        //PIOCHE
        while(!(p.pioche).est_pile_vide())
        {
            pioche = depiler(p.pioche);
        }
        desallouer((*)p.pioche);
    }
}


//************************************
//             AFFICHAGE
//************************************
//Afficher une carte

void AfficherCarte(TCarte c)
{
    printf("\n\n**********\n Carte %s**********", c.nom);
    printf("\n DESCRIPTION :\n %s \n\n", c.desc);
    printf("Type Carte : %d \n", c.type);

}

//******************
// Choisir Cartes
//******************

TCarte ChoisirCarte(TPartie * p)
{
    TCell * aux;
    TCell * prec;
    int nbCartesMain, count;
    bool trouve = false;

    aux = (* p).Joueurs[(* p).joueurActuel].main.debut;

    nbCartesMain = CompteCartesMain(* p, (* p).joueurActuel);
    count = 1;
    while (aux!= NULL)
    {
        printf("carte %d : ", count);
        AfficherCarte((* aux).carte);
        aux = ((*aux)).suivant;
        count++;
    } 

    count = SaisirEntre(1,nbCartesMain);

    aux = (* p).Joueurs[(* p).joueurActuel].main.debut;

    for(int i = 1; i < count; i++)
    {
        aux = ((*aux)).suivant;
    }
    return (* aux).carte;
}



//************************************
//        Procédure Jouer Tour
//************************************


void JouerTour(TPartie * p)
{
    //    LEXIQUE LOCAL
    int choix;
    int num;
    TCarte carte;

    (* p).prochainJoueur = ((* p).joueurActuel + 1) % 3;

    //       DEBUT_cartes
    printf("Quelle action souhaitez vous faire ? \n\t1/Jouer une carte\n\t2/Piocher deux cartes\n\t3/Defausser une carte de votre main \n");
    choix = SaisirEntre(1,3);

    //TODO: Comment est-ce qu'on récupère le joueur qui joue actuellement ?

    switch(choix)
    {
        case 1:
            
            printf("Quelle carte voulez vous jouez ?");
            carte = ChoisirCarte(p);
            JouerCarte(p, carte);
            //Après jouerCarte, on demande aux autres joueurs si ils veulent jouer une carte Faux Pas
            break;
        
        case 2:
            PiocherCarte(p, (* p).joueurActuel);
            PiocherCarte(p, (* p).joueurActuel);
        break;

        case 3: //Défausser
            carte = ChoisirCarte(p);
            num = TrouverPositionCarte(* p, carte, (* p).joueurActuel);
            SupprimerCarteMain(p, num, (* p).joueurActuel);        
            break;
        default: printf("Erreur saisie");
    }
}