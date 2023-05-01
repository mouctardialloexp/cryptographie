#include <stdio.h>

long unsigned le_carre_polynome(long unsigned a) {
  long unsigned carre = 0; 
  int i = 0; // pour le décalage gauche
  while (a > 0) { // tant que le polynôme a n'est pas nul
    if (a & 1) { // si le bit de poids faible du polynôme est 1
      carre ^= 1 << (2 * i); // on ajoute au carré le bit 1 décalé vers la gauche de deux fois i rangs
      //en insérant un zéro entre chaque chiffre
    }
    a >>= 1; // on décale le polynôme d'un rang vers la droite
    i++; 
  }
  return carre; // on renvoie le carré du polynôme
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
  long unsigned a = 0x1a; // le polynôme donné en hexadécimal (X + X^3 + X^4)
  printf("Le carre du polynome est %lx\n", le_carre_polynome(a));
  int y=le_carre_polynome(a);
  PrintPol(y);
}