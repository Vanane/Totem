#include <stdio.h>
#include <stdbool.h>
#include "TPile.c"
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

void JouerCarte(TPartie * p, TCarte c)
{
    if(c.type == 1) //Si la carte est de type Totem
    {
        Empiler(c, (* p).Joueurs[(* p).joueurActuel].totem);
        EffetTotem(c, p);
    }
    else{
        EffetPouvoir(c, p);
    }

}

//************************************
//      Procédure Piocher Carte
//************************************
//Ajoute au deck d'un joueur 2 cartes prises sur le dessus de la pioche

void PiocherCarte(TPartie * p, int joueur)
{
    //TODO: Remplacer pi par la pile du joueur actuel
    AjouterCarteMain( p, Sommet((*p).pioche), joueur);
    Depiler(pi);
    AjouterCarteMain( p, Sommet((*p).pioche), joueur);
    Depiler(pi);
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
            depiler(p.pioche);
        }
        desallouer((*)p.pioche);
    }
}


//************************************
//             AFFICHAGE
//************************************
//Afficher une carte

void Affichage(TCarte * c)
{
    printf("\n\n**********\n Carte %s**********", c.nom);
    printf("\n DESCRIPTION :\n %s \n\n", c.desc);
    printf("Type Carte : %d \n", c.type);

}

//************************************
//        Procédure Jouer Tour
//************************************


void JouerTour(TPartie * p)
{
    //    LEXIQUE LOCAL
    int choix;
    int num;
    int ent;
    bool trouve;
    TCell * aux;
    TCell * prec;

    //       DEBUT_cartes
    printf("Quelle action souhaitez vous faire ? \n 1/Jouer une carte 2/Piocher deux cartes 3/Defausser une carte de votre main \n");
    choix = SaisirEntre(1,3);
    trouve = false;

    //TODO: Comment est-ce qu'on récupère le joueur qui joue actuellement ?
    aux = (* p).Joueurs[(* p).joueurActuel].main.debut;
    prec = (* p).Joueurs[(* p).joueurActuel].main.debut;

    switch(choix)
    {
        case 1:
        printf("Quelle carte voulez vous jouez ?");
        ent = 1;
        while (aux!= NULL)
        {
            printf("%d", ent);
            //TODO: Changer le printf(aux) en quelque chose qui affiche vraiment.
            Affichage(aux);
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

            //Après jouerCarte, on demande aux autres joueurs si ils veulent jouer une carte Faux Pas

            }  ;
        case 2:
        PiocherCarte( *p, (p*).pioche, joueurActuel);

        case 3:
        printf("Quelle carte souhaitez vous défausser ?");
        ent = 1;
        while (aux!= NULL);
        {
            printf("%d", ent);
         ComptePile(p.Joueurs[i].totem) en quelque chose qui affiche vraiment.
         ComptePile(p.Joueurs[i].totem)
         ComptePile(p.Joueurs[i].totem)
         ComptePile(p.Joueurs[i].totem)
        }ComptePile(p.Joueurs[i].totem)
        nComptePile(p.Joueurs[i].totem)
        eComptePile(p.Joueurs[i].totem)
        wComptePile(p.Joueurs[i].totem)
        {ComptePile(p.Joueurs[i].totem)
            if(num==ent)
            {
                 trouve = true;
            }
            prec = aux;
            aux = (*aux).suivant;
            ent++;
        }
        if(trouve)
        {
            (*prec).suivant = (*aux).suivant;
            free(aux);
            aux = (*prec).suivant;
        }; 
        default: printf("Erreur saisie");
    }
}