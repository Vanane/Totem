#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void IntervertirTotems(TPartie * Partie);
void CartePillage(TPartie * Partie, int joueurPille);
void CadeauTotem(TPartie * Partie, int vitime, int gagnant);

void EffetPouvoir(TCarte Carte, TPartie * Partie)
{
    switch(Carte.type)
    {
        case 8:{
            //Esprit Farceur
            IntervertirTotems(Partie);
        }
        break;
        case 9:{
            //Bison Dingo
            int idJ;
            
            printf("Quel joueur voulez-vous Detruire ?\n Joueur : ");

            do{
                //Tant que le joueur choisi est le joueur actuel :
                idJ = SaisirEntre(0, 2); //Demander le joueur à voler
            if((* Partie).joueurActuel == idJ) //Si le joueur choisi est lui-même, on dit non.
                printf("Vous ne pouvez pas vous auto-détruire !");
            }while((* Partie).joueurActuel == idJ);            

            DetruireEtage(Partie, idJ);
        }
        break;
        case 10:{
            //Faux Pas
            //A réfléchir
            //TODO: Faux Pas
        }
        break;
        case 11:{
            //Pillage
            //Voler un totem et mettre la carte dans la main du voleur. Si son nbTotem < 4, rejouer.
            int idJ;
            
            printf("Quel joueur voulez-vous voler ?\n Joueur : ");

            do{
                //Tant que le joueur choisi est le joueur actuel :
                idJ = SaisirEntre(0, 2); //Demander le joueur à voler
            if((* Partie).joueurActuel == idJ) //Si le joueur choisi est lui-même, on dit non.
                printf("Vous ne pouvez pas vous voler !");
            }while((* Partie).joueurActuel == idJ);            

            CartePillage(Partie, idJ);
        }
        break;
        case 12: {
            //Cadeau
            //Voler un totem et le donner à un adversaire, puis piocher une carte.            
            int victime, gagnant;
            printf("Quel joueur voulez-vous voler ?\n Joueur : ");

            do{
                //Tant que le joueur choisi est le joueur actuel :
                victime = SaisirEntre(0, 2); //Demander le joueur à voler
            if((* Partie).joueurActuel == victime) //Si le joueur choisi est lui-même, on dit non.
                printf("Vous ne pouvez pas vous voler !");
            }while((* Partie).joueurActuel == victime);        

            printf("A qui voulez-vous donner le totem volé ? \n");

            do{
                //Tant que le joueur choisi est le joueur actuel :
                gagnant = SaisirEntre(0, 2); //Demander le joueur à voler
            if((* Partie).joueurActuel == gagnant) //Si le joueur choisi est lui-même, on dit non.
                printf("Vous ne pouvez pas vous voler !");
            }while((* Partie).joueurActuel == gagnant);            
    
            CadeauTotem(Partie, victime, gagnant);
        }
        break;
        case 13:{
            //Eau De Feu
            for(int i = 0; i < 2; i++)
            {
                PiocherCarte(Partie, (* Partie).joueurActuel);
                (* Partie).prochainJoueur = (* Partie).joueurActuel;
            }
            //Piocher 2 cartes et rejouer immédiatement.
        }
        break;
    }
}


void IntervertirTotems(TPartie * Partie)
{
    int nbJoueurs = 3;
    TPile cartes = PileVide();
    for(int i = 0; i < nbJoueurs; i++)
    {
        //Pour chaque joueur, on ajoute le totem le plus haut à une pile, puis on dépile cette carte du joueur.
        cartes = Empiler(Sommet((* Partie).Joueurs[i].totem), cartes);
        Depiler((* Partie).Joueurs[i].totem);
    }

    for(int i = 0; i < nbJoueurs; i++)
    {
        //Puis pour chaque joueur, en décalé, on empile cette carte dans sa pile.
        (* Partie).Joueurs[i].totem = Empiler(Sommet(cartes), (* Partie).Joueurs[(i - 1) % 3].totem); //(i - 1) % 3 équivaut à dire : Pour i de 0 à 1, décalé de -1.
        Depiler(cartes);
    }
    DesallouerPile(&cartes);
}

void CadeauTotem(TPartie * Partie, int victime, int gagnant)
{
    (* Partie).Joueurs[gagnant].totem = Empiler(Sommet((* Partie).Joueurs[victime].totem), (* Partie).Joueurs[gagnant].totem);
    (* Partie).Joueurs[victime].totem = Depiler((* Partie).Joueurs[victime].totem);
    PiocherCarte(Partie, (* Partie).joueurActuel);
}

void CartePillage(TPartie * Partie, int joueurVictime)
{
    //On ajoute la carte du sommet de la pile du joueur victime à la main du joueur actuel.
    AjouterCarteMain(Partie, Sommet((* Partie).Joueurs[joueurVictime].totem), (* Partie).joueurActuel);
    //Puis on dépile cette carte de la pile de la victime.
    (* Partie).Joueurs[joueurVictime].totem = Depiler((* Partie).Joueurs[joueurVictime].totem);

    if(ComptePile((* Partie).Joueurs[(* Partie).joueurActuel].totem) < 4)
    {
        (* Partie).prochainJoueur = (* Partie).joueurActuel;
    }
}