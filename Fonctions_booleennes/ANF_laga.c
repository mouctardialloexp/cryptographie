#include <stdio.h>
#include <math.h>

// Calcule la forme algébrique normale de f
void ANF(int f[], int n, int a[])
{
    int i, j, k;
    int M = 1 << n; // Taille de la matrice de Walsh-Hadamard
    int H[M][n];
    // Construit la matrice de Walsh-Hadamard
    for (i = 0; i < M; i++) {
        for (j = 0; j < n; j++) {
            H[i][j] = (i & (1 << j)) >> j;
        }
    }

    // Calcule les coefficients aS
    for (i = 0; i < M; i++) {
        a[i] = 0;
        for (j = 0; j < M; j++) {
            int x = 1;
            for (k = 0; k < n; k++) {
                x = x * pow(-1, H[j][k] * H[i][k]);
            }
            a[i] = a[i] + x * f[j];
        }
        a[i] = a[i] % 2;
    }
}
/*
void FFF(int f[], int n, int int a[])
{
    int i, j , k;
    int M=1<<n;
    int H[M][n];    
    for (i = 0; i < count; i++)
    {
        
    }
    

}


*/


int main()
{
    int n;
    printf("Entrez le nombre de variables : ");
    scanf("%d", &n);
    int M = 1 << n;
    int f[M];
    int a[M];

    printf("Entrez la table de vérité de la fonction (séparés par des espaces) :\n");
    for (int i = 0; i < M; i++) {
        scanf("%d", &f[i]);
    }

    ANF(f, n, a);

    printf("La forme algébrique normale de f est :\n");
    for (int i = 0; i < M; i++) {
        if (a[i] == 1) {
            printf("%d", i);
            for (int j = n-1; j >= 0; j--) {
                if (i & (1 << j)) {
                    printf("1");
                } else {
                    printf("0");
                }
            }
            printf(" + ");
        }
    }
    printf("0\n");
    return 0;
}