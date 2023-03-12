#include "stdio.h"
#include <stdlib.h>
#include <math.h>

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

int Poids(unsigned x)
{
x=(x&0x55555555)+((x>>1)&0x55555555);
x=(x&0x33333333)+((x>>2)&0x33333333);
x=(x&0x0f0f0f0f)+((x>>4)&0x0f0f0f0f);
x=(x&0x00ff00ff)+((x>>8)&0x00ff00ff);
return(x&0x0000ffff)+(x>>16);
}

int Degre (int *f,int n){
  int d, w, i;
  w=0;
  ANF(f, n);
  for(i=(1<<n)-1; i>=0; --i){
    if(f[i]!=0)
      w=Poids(i);
    if(w>d) d=w;
  }
  return d;
}

int Prod_Scal (int *x,int *y,int n){
  int i;
  int res=0;
  for(i=0;i<=n;i++){
    res+=x[i]*y[i];
  }
  return res;
}

int convert_base2 (int n){
  int i;
  if (n==0 || n==1) return n;
  else return n=n/2;
}

int Parite (unsigned x)
{
  x^=(x>>16);
  x^=(x>>8);
  x^=(x>>4);
  x^=(x>>2);
  return(x^(x>>1))&1;
}

int main (){
  int f1[8]={0,1,1,0,0,0,1,1};
  int f[8]={0,1,1,0,0,1,0,1};
  int n=3, i, j;
  int x=9;
  int y=312;
  
  ANF(f1,n);
  ANF(f,n);
 // Prod_Scal(x, y, n);
  for(i=0; i<(1<<n); i++) printf("%d\n", f1[i]);
  for(i=0; i<(1<<n); i++) printf("%d\n", f[i]);
  
  printf("Le degre de f est: %d\n", Degre(f, n));
  printf("Le poids de x est: %d\n", Poids(x));
  
  //printf("Le produit scalaire de x et y est: %d\n", x[i]*y[i]);
  
  printf("La parité de x est: %d\n", Parite(x));
  printf("Le produit scalaire de x et y est: %d\n", Parite(x&y));
  printf("n en base 2: %d\n", convert_base2(2));
  
  return 0;
}
