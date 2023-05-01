#include <stdio.h>

int Degree(long unsigned a) {
  int degre = -1; 
  while (a > 0) { 
    a >>= 1; 
    degre++; 
  }
  return degre; 
}

int main() {
  long unsigned a = 0x203; 
  printf("Le degre du polynome est %d\n", Degree(a)); 
}