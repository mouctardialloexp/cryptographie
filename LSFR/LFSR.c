#include <stdio.h>
#include <stdlib.h>

#define L 9  // dimension du LFSR
int Etat[L];  // etat interne du LFSR (tableau de taille L)
/* avec la convention que Etat[i] contient la valeur de e_i . De même, le polynôme P sera
représenté par un tableau d’entiers  */
int Polynome[L] = {1,0,0,1,0,0,1,1,0}; // Le polynôme 1+X^3+X^6+X^7+X^9 (declaration du polynome)
/*avec la convention que Polynome[i] contient la valeur de c_i . L’initialisation et l’affichage
de l’état interne du LFSR s’effectueront au moyen des procédures suivantes*/

// initialisation de l’état initial avec une table d’entiers donnée
void Initialise(int* e){
  int i;
  for (i=0;i<L;i++)
    Etat[i]=e[i];
}
// affichage de l’état interne du LFSR
void AfficheEtat() {
  int i;
  for (i=L-1;i>=0;i--)
    printf("%2d", Etat[i]);
  printf("\n");
}



void Avance(){
  int i;
  int somme=0;
  for (i=0;i<L-1;i++)
    somme^=Polynome[i]&Etat[i];
  for (i=L-1;i>0;i--)
    Etat[i]=Etat[i-1];
  Etat[0]=somme;
}

int SontEgaux(int* a, int* b){
  int i;
  int res =1;
  for (i=0;i<L-1;i++)
    if (a[i]!=b[i])
      res = 0;
  return res;
}

int periode(int* init){
  int cpt = 1;
  Initialise(init);
  Avance();
  while(!SontEgaux(Etat,init)){
    Avance();
    cpt++;
  }
  return cpt;  
}

/*****************fonction principale*******************/

int main() {
  int i;
  int p;
  int EtatInitial[L]={1,0,0,0,0,0,0,0,0};
  //exo1
  Initialise(EtatInitial);
  for (i=0;i<40;i++){
    AfficheEtat();
    Avance();
  }
  p = periode(EtatInitial);
  printf("période = %d \n",p);

  //exo2
  
  return 0;
}
