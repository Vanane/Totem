#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <creation.c>





//*********************************************
//         Prototypes des fonctions
//*********************************************


//************************************
//        Fonction Saisir_entre
//************************************

int saisir_entre(int min, int max)
{
    int saisi;
 printf("Veuillez saisir un entier compris entre %d et %d :\n",min,max);
 scanf("%d",&saisi);

 while (saisi<min || saisi>max)
 {
  printf("Vous n'avez pas saisi un entier compris entre %d et %d, nouvelle saisie :\n",min,max);
  scanf("%d",&saisi);
 }
 return saisi;
}

//************************************
//       Procédure Jouer Carte
//************************************

void JouerCarte(TPartie p, TCarte c)
{

}

//************************************
//      Procédure Piocher Carte
//************************************

void PiocherCarte(TPartie p)
{

}

//************************************
//     Procédure Pouvoir Carte
//************************************

void PouvoirCarte(TPartie p, TCarte c)
{}


//************************************
//        Procédure Jouer Tour
//************************************


int JouerTour(TPartie p)
{

//**********************
//    LEXIQUE LOCAL
//**********************

int choix;
int num;
int ent;
bool trouve;
TCell * aux;
TCell * prec;

//**********************
//       DEBUT_cartes
//**********************


printf("Quelle action souhaitez vous faire ? \n 1/Jouer une carte 2/Piocher deux cartes 3/Defausser une carte de votre main \n");
choix = saisir_entre(1,3);
trouve = false;
aux = p.joueurs.main.carte;
prec = p.joueurs.main.carte;

    switch choix
    {
        case 1: printf("Quelle carte souhaitez vous jouez ?")
                ent = 1
                while (aux!= NULL)
                {
                    printf(ent)
                    printf(aux)
                    aux = aux*.suivant
                    ent++
                } 
                num = saisir_entre(1,ent)
                ent = 1
                while (aux!= NULL && !trouve)
                {
                    if(num==ent)
                    {
                        trouve = vrai
                    }
                    aux = aux*.suivant
                    ent++
                }
                if(trouve)
                {
                    //AppelJouerCarte(p, aux)
                }  ;
        case 2: PiocherCarte(p, aux);
                
        case 3: printf("Quelle carte souhaitez vous défausser ?")
                ent = 1
                while (aux!= NULL)
                {
                    printf(ent)
                    printf(aux)
                    aux = aux*.suivant
                    ent++
                } 
                num = saisir_entre(1,ent)
                ent = 1
                while (aux!= NULL && !trouve)
                {
                    if(num==ent)
                    {
                        trouve = vrai
                    }
                    prec = aux
                    aux = aux*.suivant
                    ent++
                }
                if(trouve)
                {
                    prec*.suivant = aux*.suivant
                    free(aux)
                    aux = prec*.suivant
                }; 
                
                  
        default: printf("Erreur saisie");
    }
        


}