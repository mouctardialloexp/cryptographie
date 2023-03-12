#include "stdio.h"
#include <stdlib.h>
#include <math.h>

void Fourier (int *f, int n){
  unsigned int nn; /*taille tableau*/
  unsigned int jj; /*taille sous fonction*/
  int i,s;
  nn=1<<n;
  jj=nn>>1;
  do{
    i=0;
    do{
      s=f[i+jj];
      f[i+jj]=f[i]-f[i+jj];
      f[i]=f[i]+s;
      i++;
      if ((i&(jj-1))==0) i=i+jj;
    }
    while(i<nn);
    jj>>=1;
  }
  while(jj!=0);
}

void Walsh (int *f,int n) {
  unsigned int nn;
  unsigned int jj;
  int i,s;
  nn=1<<n;
  jj=nn>>1;
  do{ i=0;
    do{
      s=f[i+jj];
      f[i+jj]=f[i]-f[i+jj];
      f[i]=f[i+jj]+s;
      i++;
      if((i&(jj-1))==0) i=i+jj;
    }
    
    while( i<nn );
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

int resil__(int *f,int n){
  int i,r,w;
  r=n;
  Walsh(f,n);
  for(i=(1<<n)-1;i>=0;--i){
    if(f[i]!=0){
      w=Poids(i);
      if (w<r) r=w;
    }
  }
  return r-1;
}

int main (){
  int f[8]={0,1,1,0,1,0,0,1};
  int f1[16]={0,0,1,1,0,0,1,0,0,1,1,0,0,1,1,1};
  int n=3, i, j;
  Fourier (f,n);
   printf("La tranformé de Fourier de f est :\n");
  for(i=0; i<(1<<n); i++) printf("%d\n", f[i]);
  f[i]=1-2*f[i];
  Walsh(f,n);
  printf("La tranformé de Walsh de f est :\n");
  for (i=0; i<(1<<n); i++) printf("%d\n", f[i]);
  Walsh(f,n);
  printf("La resilience de f est: %d\n", resil__(f, n));
}
