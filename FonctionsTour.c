#include <stdio.h>
#include <stdbool.h>
#include "TPile.c"
#include "types.c"
#include "SousFonctions.c"
#include "FonctionsPouvoirs.c"
#include "FonctionsEffets.c"

//************************************
//       Procédure Jouer Carte
//************************************
 // Prend en entrée la carte jouée. En fonction du type et du pouvoir,
 // la partie sera modifiée en conséquence.
 // Les joueurs peuvent à leur tour poser une carte Faux pas,
 // s’ils en ont une. Dans ce cas, la dernière carte jouée est 
 //La carte est supprimée de la main du joueur dont c’est le tour à la fin.

void JouerCarte(TPile joueursFauxPas,TPartie * p, TCarte c)
{
    int joueurActuel ;
    TPile joueursFauxPas;

    joueursFauxPas = PileVide();
    TPile * cartes = PileVide();
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
    
    FauxPas(* p, cartes, joueursFauxPas);

    while(!cartes.EstPileVide()){
        if(sommet(* cartes).type==10) // Si c'est un Faux Pas
        {
            * cartes = Depiler(* cartes);
            if(sommet(* cartes).type==10) //Si la carte en-dessous est un Faux Pas
            {
                PiocherCarte( * p, (* p).pioche, sommet(joueursFauxPas));
                PiocherCarte( * p, (* p).pioche, sommet(joueursFauxPas));
                joueursFauxPas = depiler(joueursFauxPas);
                if(c.type == 1) //Si la carte est de type Totem
                {
                    Empiler(c, p.joueurActuel.totem);
                    EffetTotem(c, * p);
                }
                else
                {
                    EffetPouvoir(c, * p);
                }
            }
            else
            {                
                partie.prochainJoueur = sommet(cartes); //on veut récupérer le possesseur de la carte
                ViderPile(cartes);
                //TODO : Variable prochain joueur ?
            }
        }
        else
        {
            if(c.type == 1) //Si la carte est de type Totem
            {
                (* p).Joueurs[(* p).joueurActuel].totem = Empiler(c, (* p).Joueurs[(* p).joueurActuel].totem);
                EffetTotem(c, * p);
            }
            else
                EffetPouvoir(c, * p);
        }
    }
}

void FauxPas( TPartie * partie, TPile * cartes, int joueurs[3])
{
    //TODO: TPile c'est pour les cartes. il faut trouver un autre moyen pour faire une pile d'entiers ou un tableau.
    //On demande a chaque joueurs si il veut jouer unfaux pas
    //On le demande tant qu'il y a des joueurs qui peuvent jouer, et qu'au moins une carte a été posée à la dernière boucle.
    // -> ajout carte a la pile
    // -> Appel de la meme methode
    bool r;
    for(int i =0; i<3; i++)
    {
        if(i != ( *p).joueurActuel)
        {
            if(TrouverFauxPas(partie, i) != NULL) //On verifie qu'il possède un faux Pas avant de lui demander si il veut en jouer un
            {
                printf("Voulez vous jouez une carte Faux Pas ?\n");
                r = SaisirReponse();
                if(r)
                {
                    joueursFauxPas = Empiler(i);
                    cartes = Empiler(TrouverFauxPas(partie, i));                
                    SupprimerCarteMain(p, Sommet(cartes), i);
                }
            }
        }
    }
}


void ExecuterLynx(TPartie * p)
{
    int pos;
    //Exécute l'effet Lynx, si le joueur est propice.
    if((* p).Joueurs[(* p).joueurActuel].estEffetlynx)
    {
        TListeCarte cartesPiochees;
        for(int i = 0; i < 3; i++)
        {
            AjouterCarteliste(Sommet((* p).pioche), cartesPiochees);
            AfficherCarte(Sommet((* p).pioche));
            (*p).pioche = Depiler((*p).pioche);
        }

        printf("Quelle carte souhaitez-vous conserver ?\n");
        pos = SaisirEntre(1,3);

        for(int i = 1; i < 4; i++)
        {
            if(i != pos)
                SupprimerAPosition(cartesPiochees, i);
        }
        AjouterCarteMain(p, cartesPiochees.debut.carte, (* p).joueurActuel);
        SupprimerAPosition(cartesPiochees, 1); //TODO: Position 0 ou 1 ?
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
TCarte TrouverFauxPas(TPartie * p, int joueur)
{
    //On parcourt les cartes de la main
    // Si il y a des cartes de type Faux pas
    // On retourne lE FAUXpAS
    TCell * aux;
    TCarte AFauxpas;
    aux = (* p).Joueurs[(* p).joueur].main.debut;
    while(aux != NULL || AFauxpas == NULL)
    {
        if(aux.type==10)
        {
            AFauxpas = aux;
        }
        aux = (*aux).suivant;
    }
    return AFauxpas;
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
    int ent;
    bool trouve = false;

     aux = (* p).Joueurs[(* p).joueurActuel].main.debut;
    prec = (* p).Joueurs[(* p).joueurActuel].main.debut;

        ent = 1;
        while (aux!= NULL)
        {
            printf("%d", ent);
            //TODO: Changer le printf(aux) en quelque chose qui affiche vraiment.
            AfficherCarte(* aux);
            aux = ((*aux)).suivant;
            ent++;
        } 
        num = SaisirEntre(1,ent);
        ent = 1;
        while (aux!= NULL && !trouve);
        {
            if(num==ent)
            {
            trouve = true;
            }
            aux = ((*aux)).suivant;
            ent++;
        }
        if(trouve)
            {
            //AppelJouerCarte(p, aux)
                return aux;            
            }  else{return 0;}        
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

    TPile CartesJ;
    CartesJ = PileVide()

    (* p).prochainJoueur = ((* p).joueurActuel + 1) % 3;

    //       DEBUT_cartes
    printf("Quelle action souhaitez vous faire ? \n\t1/Jouer une carte\n\t2/Piocher deux cartes\n\t3/Defausser une carte de votre main \n");
    choix = SaisirEntre(1,3);
    trouve = false;

    //TODO: Comment est-ce qu'on récupère le joueur qui joue actuellement ?
   

    switch(choix)
    {
        case 1:
            
            printf("Quelle carte voulez vous jouez ?");
            carte = ChoisirCarte(p);
            CartesJ.Empiler(carte);
            JouerCarte();
            //Après jouerCarte, on demande aux autres joueurs si ils veulent jouer une carte Faux Pas
            break;
        
        case 2:
        PiocherCarte( *p, (p*).pioche, joueurActuel);
        PiocherCarte( *p, (p*).pioche, joueurActuel);

        break;

        case 3: 
                carte = ChoisirCarte(*p)
                num = TrouverPositionCarte(&p, carte, joueurActuel);
                SupprimerCarteMain(p, num, joueurActuel );
        
                break;
        
        default: printf("Erreur saisie");
    }
}