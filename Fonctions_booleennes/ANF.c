#include <stdio.h>
#include <stdlib.h>


unsigned Anf(int* f, int n)
{
    unsigned int nn;
    unsigned int jj;
    int i;
    nn=1<<n; // nn recoit 2 puissance n;
    jj=nn>>1; // j recoit nn divis� par 2;
      do{ i=0;
        do{
        f[i+jj]=f[i]^f[i+jj];
        i++;
        if((i&(jj-1))==0) i=i+jj;
         }

       while( i<nn );
       jj>>=1;
      }

    while(jj!=0);
}

int main()
{
   int f[200];
   int n;
   int i,z;
   printf("inserer le nombre de variables\n"); scanf("%d",&n);
   z=1<<n;
   for(i=0; i<z;i++)
   {
       printf("ins�rer la %d valeur de f attention soit 0 ou 1\n",i); scanf("%d",&f[i]);
   }
   Anf(f,n);
   printf("la forme algebrique normale de la fonction f est \n");
   for(i=0; i<(1<<n);i++)
    printf("%d; ",f[i]);
    return 0;
}
