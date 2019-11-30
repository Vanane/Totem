void EffetTotem(TCarte Carte, TPartie * Partie)
{
    switch(Carte.type)
    {
        case 1: //Coyote
            bool Choix = SaisirReponse("Voulez-vous voler le totem d'un joueur ?");            
            if(Choix)
            {                
                int idJ;
                do
                {
                    idJ = SaisirEntre(0, 2);
                }while(idJ != (* Partie).joueurActuel);
                        
                VolerTotem(Partie, idJ);
            }
            break;
        case 2: //Aigle

        break;
        case 3: //Loup

        break;
        case 4: //Corbeau

        break;
        case 5: //Lynx

        break;
        case 6: //Tortue

        break;
        case 7: //Ours

        break;
        default:
        printf("La carte donnée en paramètre d'EffetTotem (id : %d) n'est pas reconnue comme totem.", Carte.type);
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