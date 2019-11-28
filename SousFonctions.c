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
    choix = saisir_entre(1,3);
    trouve = false;

    //TODO: Comment est-ce qu'on récupère le joueur qui joue actuellement ?
    aux = (* p).Joueurs[(* p).joueurActuel].main.debut;
    prec = (* p).Joueurs[(* p).joueurActuel].main.debut;

    switch(choix)
    {
    case 1:
    printf("Quelle carte souhaitez vous jouez ?");
    ent = 1;
    while (aux!= NULL)
    {
    printf("%d", ent);
    //TODO: Changer le printf(aux) en quelque chose qui affiche vraiment.
    //printf("%d", aux);
    aux = ((*aux)).suivant;
    ent++;
    } 
    num = saisir_entre(1,ent);
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
    }  ;
    case 2:
    PiocherCarte((*p));

    case 3:
    printf("Quelle carte souhaitez vous défausser ?");
    ent = 1;
    while (aux!= NULL);
    {
    printf("%d", ent);
    //TODO: Changer le printf(aux) en quelque chose qui affiche vraiment.
    //printf("%d", aux);
    aux = ((*aux)).suivant;
    ent++;
    } 
    num = saisir_entre(1,ent);
    ent = 1;
    while (aux!= NULL && !trouve)
    {
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