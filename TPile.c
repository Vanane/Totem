typedef struct _TElem{
  TCarte elem;
  struct _TElem * suivant;
}TElem;

typedef struct _TPile{
  TElem * debut;
}TPile;

TPile PileVide(); //Renvoie une pile vierge
TPile Empiler(TCarte E, TPile P); //Renvoie une pile dont le dernier élément est E
TPile Depiler(TPile P); //Renvoie une pile dont le dernier élément posé a été enlevé
TCarte Sommet(TPile P); //Renvoie le dernier élément posé d'une pile
bool EstPileVide(TPile P); //Regarde si la pile est vide ou non
void AfficherPile(TPile P); //Affiche une pile sur l'écran
void DesallouerPile(TPile * P); //Désalloue une pile de la mémoire


/* Fonction Main de test avec des entiers
int main(){
  TPile pile, pile2;
  pile = PileVide();

  //Axiome 1 : EstVide(PileVide()) = true;
  printf("Vide : %d\n", EstPileVide(PileVide()));
  //Axiome 2 : 
  printf("Vide : %d\n", EstPileVide(Empiler(0, pile)));
  //Axiome 3 :
  pile = Empiler(4, pile);
  pile = Empiler(5, pile);
  pile = Empiler(1, pile);

  pile2 = Depiler(Empiler(0, pile));
  AfficherPile(pile);
  AfficherPile(pile2);

  printf("Dépiler : %d\n", Sommet(pile) == Sommet(pile2));

  //Axiome 4 : 
  printf("Sommet : %d\n", Sommet(Empiler(0, pile)) == 0);

  DesallouerPile(&pile);
  DesallouerPile(&pile2);
  return 0;
}
*/

TPile PileVide(){
  //Renvoie une pile vierge
  TPile P;
  P.debut = NULL;
  return P;
}


TPile Empiler(TCarte E, TPile P){
//Renvoie une pile dont le dernier élément est E  
  TElem * new = malloc(sizeof(TElem));
  (* new).elem = E;
  (* new).suivant = P.debut;
  P.debut = new;
  return P;
} 


TPile Depiler(TPile P){
  //Renvoie une pile dont le dernier élément posé a été enlevé
  TElem * aux = P.debut;
  P.debut = (* P.debut).suivant;
  free(aux);
  return P;
}


TCarte Sommet(TPile P){
  //Renvoie le dernier élément posé d'une pile
  if(P.debut == NULL){
    fprintf(stderr, "Erreur ! Sommet() retourne une erreur, la pile est vide. Sortie du programme.");
    exit(EXIT_FAILURE);
  }
  return (* P.debut).elem;
}


bool EstPileVide(TPile P){
  //Regarde si la pile est vide ou non
  if(P.debut == NULL)
    return true;
  else return false;
}

/*
void AfficherPile(TPile P){
  //Affiche une pile sur l'écran
  TElem * aux = P.debut;

  while(aux != NULL){
    printf("%d | ", (* aux).elem);
    aux = (* aux).suivant;
  }
  printf("\n");
}
*/


void DesallouerPile(TPile * P){
  //Désalloue une pile de la mémoire
  TElem * aux;

  while((* P).debut != NULL){
    aux = (* P).debut;
    (* P).debut =(* (* P).debut).suivant;
    free(aux);
  }
}