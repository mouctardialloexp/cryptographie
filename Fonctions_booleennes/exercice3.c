#include <stdio.h>

unsigned int ProdScal1(unsigned int x[], unsigned int y[]) {
    unsigned int p = 0;
    int i;
    for (i = 0; i < 32; i++) {
        p += x[i] * y[i];
    }
    return p;
}

int main() {
    unsigned int x[32] = {1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
    unsigned int y[32] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1};
    unsigned int prod = ProdScal1(x, y);
    printf("Le produit scalaire est %u\n", prod);
    return 0;
}

