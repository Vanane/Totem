//*********************************************
//         Prototypes des fonctions
//*********************************************


//************************************
//        Fonction SaisirEntre
//************************************

int SaisirEntre(int min, int max)
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

bool SaisirReponse(char message[128]) //Retourn Vrai ou Faux selon la réponse de l'utilisateur (o ou n)
{
    char c;
    do
    {
        if(c !='o' && c != 'n' && c != '\n')
            printf("%s\n", message);
        scanf("%c", &c);
    }while(c !='o' && c != 'n');
    return c =='o';
}

TCarte TrouverCarteMain(TPartie Partie, int pos, int joueur) //Retourne une carte à une position dans une main d'un joueur
{
    TCell * aux;
    int count = 1;
    aux = Partie.Joueurs[joueur].main.debut;
    while(count < pos)
    {
        aux = (* aux).suivant;
        count++;
    }
    return (* aux).carte;
}

TCarte TrouverCarteListe(TListeCarte l, int pos)
{
    TCell * aux;
    int count = 1;
    aux = l.debut;
    while(count < pos)
    {
        aux = (* aux).suivant;
        count++;
    }
    return (* aux).carte;
}

int TrouverPositionCarte(TPartie Partie, TCarte carte, int joueur)
{
    TCell * aux;
    int count = 0;
    aux = Partie.Joueurs[joueur].main.debut;
    while(aux!= carte)
    {
        aux = (*aux).suivant;
        count++;
    }
    return count;

}

void AjouterCarteMain(TPartie * Partie, TCarte carte, int joueur) //Ajoute une carte à la main d'un joueur
{
    TCell * new;
    new = malloc(sizeof(TCell));
    (* new).carte = carte;
    (* new).suivant = (*Partie).Joueurs[joueur].main.debut;
    (*Partie).Joueurs[joueur].main.debut = new;
}

void AjouterCarteliste(TCarte carte, TListeCarte l) //Ajoute une carte à la main d'un joueur
{
    TCell * new;
    new = malloc(sizeof(TCell));
    (* new).carte = carte;
    (* new).suivant = l.debut;
    l.debut = new;
}


int CompteCartesMain(TPartie Partie, int joueur) // Retourne le nombre de carte d'une main d'un joueur
{
    TCell * aux = Partie.Joueurs[joueur].main.debut;
    int count = 0;
    while(aux != NULL)
    {
        aux = (* aux).suivant;
        count++;
    }
    return count;
}

int ComptePile(TPile pile)
{
    int count = 0;
    while(!EstPileVide(pile))
    {
        pile = Depiler(pile);
        count++;
    }
    return count;
}

void SupprimerCarteMain(TPartie * Partie, int pos, int joueur) //Supprime la carte d'une main d'un joueur à une position donnée.
{
    TCell * aux, * prec;
    int count = 1;
    prec = (* Partie).Joueurs[joueur].main.debut;
    aux = (* Partie).Joueurs[joueur].main.debut;

    while(count < pos)
    {
        prec = aux;
        aux = (* aux).suivant;
        count++;
    }
    if(prec == aux)
    {
        (* Partie).Joueurs[joueur].main.debut = (* aux).suivant;
    }
    else
    {
        (* prec).suivant = (* aux).suivant;
    }
    free(aux);
}

void SupprimerAPosition(TListeCarte l, int pos)
{
    TCell * aux, * prec;
    int count = 1;
    prec = l.debut;
    aux = l.debut;

    while(count < pos)
    {
        prec = aux;
        aux = (* aux).suivant;
        count++;
    }
    if(prec == aux)
    {
        l.debut = (* aux).suivant;
    }
    else
    {
        (* prec).suivant = (* aux).suivant;
    }
    free(aux);
}

int Random(int min, int max) //Retourne un nombre entier entre min et max
{
    return rand() % (max - min + 1) + min;
}

