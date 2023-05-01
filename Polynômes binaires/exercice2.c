#include <stdio.h>
#include <math.h>

void PrintPol(long unsigned x) {
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
  printf("le polynôme binaire représenté par 0x123 est :\n");
  long unsigned x = 0x123; //en Hexa
  PrintPol(x);
}