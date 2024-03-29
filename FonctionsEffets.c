#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void VolerTotem(TPartie * Partie, int JoueurVictime);
void ImmuniteVol(TPartie * Partie);
void VolerCarteNum(TPartie * Partie, int numCarte, int numJoueur);

void EffetTotem(TCarte Carte, TPartie * Partie)
{
    switch(Carte.pouvoir)
    {
        case 1: {
            //Coyote
            int idJ;
            bool Immunise;
            bool Voler = SaisirReponse("Voulez-vous voler un joueur ?");
            
            if(Voler)
            {
                printf("Quel joueur voulez-vous voler ?\n Joueur : ");
                
                do{
                    //Tant que le joueur choisi est immunisé ou est le joueur actuel :
                idJ = SaisirEntre(0, 2); //Demander le joueur à voler
                    Immunise = (* Partie).Joueurs[idJ].estProtegeVol; //On regarde si le joueur choisi est immunisé

                if((* Partie).joueurActuel == idJ) //Si le joueur choisi est lui-même, on dit non.
                    printf("Vous ne pouvez pas vous voler !");
                }while((* Partie).joueurActuel == idJ || Immunise);            
                VolerTotem(Partie, idJ);
            }
        }               
        break;
        case 2:{
            //Aigle
            ImmuniteVol(Partie);
        }
        break;
        case 3:{
            //Loup
            int idJ;
            bool Voler = SaisirReponse("Voulez-vous voler un joueur ?");
            
            if(Voler)
            {
                printf("Quel joueur voulez-vous voler ?\n Joueur : ");

                do{
                    //Tant que le joueur choisi est le joueur actuel :
                    idJ = SaisirEntre(0, 2); //Demander le joueur à voler
                if((* Partie).joueurActuel == idJ) //Si le joueur choisi est lui-même, on dit non.
                    printf("Vous ne pouvez pas vous voler !");
                }while((* Partie).joueurActuel == idJ);            

                for(int i = 0; i < 2; i++)
                {
                    int r = Random(1, CompteCartesMain(* Partie, idJ));
                    VolerCarteNum(Partie, r, idJ);
                }
            }
        }
        break;
        case 4:{
            //Corbeau
            int idJ;
            bool Echanger = SaisirReponse("Voulez-vous échanger votre main avec un joueur ?");
            if(Echanger)
            {
                printf("Avec quel joueur voulez-vous échanger vos cartes ?");

                do{
                    //Tant que le joueur choisi est le joueur actuel :
                    idJ = SaisirEntre(0, 2); //Demander le joueur à voler
                if((* Partie).joueurActuel == idJ) //Si le joueur choisi est lui-même, on dit non.
                    printf("Vous ne pouvez pas vous voler !");
                }while((* Partie).joueurActuel == idJ);            

                int idJ = SaisirEntre(0,2);
                EchangerMain(Partie, idJ);
            }
        }
        break;
        case 5:{
            //Lynx
            //TODO: l'effet se trigger à chaque fin de tour, le faire dans une autre fonction incluse dans JouerTour ?
        }
        break;
        case 6:{
            //Tortue
            ImmuniteDestr(Partie);
        }
        break;
        case 7:{
            //Ours
            int idJ;
            bool Detruire = SaisirReponse("Voulez-vous Detruire un joueur ?");
            
            if(Detruire)
            {
                printf("Quel joueur voulez-vous Detruire ?\n Joueur : ");

                do{
                    //Tant que le joueur choisi est le joueur actuel :
                idJ = SaisirEntre(0, 2); //Demander le joueur à voler
                if((* Partie).joueurActuel == idJ) //Si le joueur choisi est lui-même, on dit non.
                    printf("Vous ne pouvez pas vous auto-detruire !");
                }while((* Partie).joueurActuel == idJ);

                int idJ = SaisirEntre(0,2);
                DetruireEtage(Partie, idJ);
            }
        }
        break;
        default:{
            printf("La carte donnée en paramètre d'EffetTotem (id : %d) n'est pas reconnue comme totem.", Carte.pouvoir);
        }
        break;
    }
}


void VolerTotem(TPartie * Partie, int JoueurVictime)
{
    /*
    TElem * pivot = (* Partie).Joueurs[JoueurVictime].totem.debut; //Premier Element de la pile du totem du joueur victime
    (* Partie).Joueurs[JoueurVictime].totem.debut = (* Partie).Joueurs[(* Partie).joueurActuel].totem.debut;
    */
    TPile pivot = (* Partie).Joueurs[JoueurVictime].totem;
    (* Partie).Joueurs[JoueurVictime].totem = (* Partie).Joueurs[(* Partie).joueurActuel].totem;
    (* Partie).Joueurs[(* Partie).joueurActuel].totem = pivot; 
}

void ImmuniteVol(TPartie * Partie)
{
    (* Partie).Joueurs[(* Partie).joueurActuel].estProtegeVol = true;
}

void ImmuniteDestr(TPartie * Partie)
{
    (* Partie).Joueurs[(* Partie).joueurActuel].estProtegeDestr = true;
}

void VolerCarteNum(TPartie * Partie, int numCarte, int numJoueur)
{
    AjouterCarteMain(Partie, TrouverCarteMain(* Partie, numCarte, numJoueur), numJoueur);
    SupprimerCarteMain(Partie, numCarte, numJoueur);
}

void EchangerMain(TPartie * Partie, int numJoueur) //Echange la main du joueur courant avec le joueur passé en params
{
    TCell * pivot = (* Partie).Joueurs[numJoueur].main.debut;
    (* Partie).Joueurs[numJoueur].main.debut = (* Partie).Joueurs[(* Partie).joueurActuel].main.debut;
    (* Partie).Joueurs[(* Partie).joueurActuel].main.debut = pivot;
}

void DetruireEtage(TPartie * Partie, int numJoueur)
{
    (* Partie).Joueurs[numJoueur].totem = Depiler((* Partie).Joueurs[numJoueur].totem);
}