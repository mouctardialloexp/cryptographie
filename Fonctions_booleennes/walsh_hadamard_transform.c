#include <stdio.h>
#include <stdlib.h>

void walsh_hadamard_transform(int* f, int n) {
    int N = 1 << n; //calcule la taille N du tableau f.
    for (int k = 1; k < N; k <<= 1) {
        for (int i = 0; i < N; i += k << 1) {
            for (int j = i; j < i + k; j++) {
                int x = f[j];
                int y = f[j + k];
                f[j] = x + y;
                f[j + k] = x - y;
            }
        }
    }

}

int hamming_weight(int* f, int n) {
    int N = 1 << n;
    int weight = 0;
    for (int i = 0; i < N; i++) {
        weight += (f[i] == 0) ? 1 : 0;
    }
    return weight;
}

/*
La variable "N" est initialisée à 2^n, comme dans le code précédent.

La fonction "for" externe parcourt tous les entiers k tels que 2^k <= N. 
La fonction "for" intermédiaire parcourt tous les entiers i tels que i + k < N. 
la fonction "for" interne parcourt tous les entiers j tels que i <= j < i + k.

À chaque itération, la fonction calcule la somme et la différence de f[j] et f[j + k], stocke la somme dans f[j], et stocke la différence dans f[j + k]. Cette opération est répétée pour chaque paire d'éléments de f à une distance de k.
*/

int main()
{
    int n, N;
    printf("La taille de la fonction : ");
    scanf("%d", &n);

    N = 1 << n;
    int f[N];

    printf("Entrez la table de vérité de la fonction (séparés par des espaces) :\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &f[i]);
    }

    walsh_hadamard_transform(f, n);

    


    printf("La transformation de Walsh-Hadamard de la fonction est : \n");
    for (int i = 0; i < N; i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

    return 0;
    
    int hamming = hamming_weight(f, n);
    printf("Le poids d'Hamming de la transformation de Walsh-Hadamard est : %d\n", hamming);
}

