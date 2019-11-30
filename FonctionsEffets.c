void EffetTotem(TCarte Carte, TPartie * Partie)
{
    switch(Carte.type)
    {
        case 1: //Coyote
        int idJ;
        do
        {
            idJ = SaisirEntre(0, 2);
        }while(idJ != (* Partie).joueurActuel);
        VolerTotem(Partie, idJ);
        break; //Aigle
        case 2:

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
}