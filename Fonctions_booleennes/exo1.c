#include "stdio.h"
#include <stdlib.h>
#include <math.h>

//Exercice 1
void ANF(int *f, int n){
  unsigned int nn; /*taille tableau*/
  unsigned int jj; /*taille sous fonction*/
  int i;
  nn=1<<n;
  jj=nn>>1;
  do{
    i=0;
    do{
      f[i+jj]=f[i]^f[i+jj];
      i++;
      if ((i&(jj-1))==0) i=i+jj;
    }
    while(i<nn);
    jj>>=1;
  }
  while(jj!=0);
}
//Exercice 2
int Poids(unsigned x)
{
x=(x&0x55555555)+((x>>1)&0x55555555);
x=(x&0x33333333)+((x>>2)&0x33333333);
x=(x&0x0f0f0f0f)+((x>>4)&0x0f0f0f0f);
x=(x&0x00ff00ff)+((x>>8)&0x00ff00ff);
return(x&0x0000ffff)+(x>>16);
}

int main()
{
    int f1[8]={0,1,1,0,0,1,0,1};
    int n=3, i, j;
    x=9;
    ANF(f1,n);
    for(i=0; i<(1<<n); i++) printf("%d\n", f1[i]);
    printf("Le poids de x est: %d\n", Poids(x));
    return 0;

}