#include<stdio.h>
#include<stdlib.h>
#define L 9
int Etat[L] ;
int Polynome[L]={1,0,0,1,0,0,1,1,0};

// initialisation de l’état initial avec une table d’entiers donnée
void Initialise(int *e){
    int i;
    for (i=0;i<L;i++) Etat[i]=e[i];
}

// affichage de l’état interne du LFSR
void AfficheEtat(){
    int i;
    for (i=L-1;i>=0;i--) 
        printf("%2d",Etat[i]);
    printf("\n");
}

void Avance(){
    int newInput = 0;
    for(int i = 0; i<L; i++) 
        newInput = newInput ^ (Etat[i] * Polynome[i]);
    for(int i=0; i<L-1; i++) 
        Etat[i] = Etat[i+1];
    Etat[L-1] = newInput;
}

int SontEgaux(int *a, int *b){
    for(int i = 0; i<L; i++){
        if (a[i] != b[i]) 
            return 0;
    }
    return 1;
}

int main(void){
    int EtatInitial[L]={1,0,0,0,0,0,0,0,0};
    Initialise(EtatInitial);
    printf("Etat Initial: ");
    AfficheEtat();
    int i=1;
    while(1){
        Avance();
        printf("Etat %d: ", i);
        AfficheEtat();
        if(SontEgaux(Etat, EtatInitial)) break;
        i++;
    }
    printf("Periode : %d\n", i);
    //AfficheEtat();
    return 0;
}
