#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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
  TCarte t;
  if(P.debut == NULL){
    return t;
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
void ViderPile(TPile * p)
{
  while(!EstPileVide(* p))
  {
    *p = Depiler(* p);
  }
}

void DesallouerPile(TPile * P){
  //Désalloue une pile de la mémoire
  TElem * aux;

  while((* P).debut != NULL){
    aux = (* P).debut;
    (* P).debut =(* (* P).debut).suivant;
    free(aux);
  }
}