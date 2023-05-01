#include <stdio.h>

long unsigned Multiplication_de_polynome(long unsigned u, long unsigned v) {
  long unsigned LE_PRODUIT = 0; 
  int i = 0; 
  while (u > 0) {
    if (u & 1) { // si le bit de poids faible du premier polynôme est 1
      LE_PRODUIT ^= v << i; // on ajoute au produit le second polynôme décalé vers la gauche de i rangs
    }
    u >>= 1; // on décale le premier polynôme d'un rang vers la droite
    i++; 
  }
  return LE_PRODUIT; 
}
/*-----------------------------------------------------------------------------------------------------------------*/
void PrintPol(long unsigned x) {// Fonction qui trannsforme hexa en poly
  int Le_degre = 0; 
  int premier = 1; 
  while (x > 0) { 
    if (x & 1) { 
      if (!premier) { 
        printf("+"); 
      }
      if (Le_degre == 0) { 
        printf("1"); 
      } else if (Le_degre == 1) { 
        printf("X"); 
      } else { 
        printf("X^%d", Le_degre); 
      }
      premier = 0; 
    }
    x >>= 1; 
    Le_degre++; 
  }
}


int main() {
  long unsigned u = 0xA2; // (X + X^5 + X^7)
  //long unsigned v = 0xA2; // (X + X^5 + X^7) pour le produit du meme polynôme
  long unsigned v = 0x225; // (1 + X^2 + X^5 + X^9)
  // on affiche le résultat de la fonction PolMul avec a et b comme arguments en hexadécimal (%lx)
  printf("Le produit de (X + X^5 + X^7) et (1 + X^2 + X^5 + X^9) de polynomes est %lx\n",Multiplication_de_polynome(a,b)); 
  int y=Multiplication_de_polynome(a,b);
  PrintPol(y);
}