#include <stdio.h>


// Fonction pour calculer le poids binaire d'un mot machine
int poids(unsigned int x)
{
    // Initialisation de la variable pour stocker le poids binaire
    int poids_binaire = 0;
    
    // Boucle pour compter le nombre de bits à 1 dans x
    while (x != 0)
    {
        // Si le bit de poids faible est à 1, on l'ajoute au poids binaire
        if (x & 1)
        {
            poids_binaire++;
        }
        
        // Décalage de x vers la droite pour passer au bit suivant
        x >>= 1;
    }
    
    // Retourne le poids binaire calculé
    return poids_binaire;
}


/*-------------------------------------------------------------------------------------------------------*/


// Fonction pour calculer le degré d'une fonction booléenne
int degre(int* f, int n)
{
    // Initialisation de la variable pour stocker le degré
    int degre_f = 0;
    
    // Boucle sur les variables booléennes de la fonction
    for (int i = 0; i < n; i++)
    {
        // Variable pour stocker la valeur de la variable i dans les lignes où la sortie est à 1
        unsigned int valeurs_1 = 0;
        // Variable pour stocker la valeur de la variable i dans les lignes où la sortie est à 0
        unsigned int valeurs_0 = 0;
        // Boucle sur les lignes du tableau de vérité
        for (int j = 0; j < (1 << n); j++)
        {
            // Si la sortie est à 1 dans cette ligne
            if (f[j])
            {
                // Si la variable i est à 1 dans cette ligne, on ajoute sa valeur au masque "valeurs_1"
                if (j & (1 << i))
                {
                    valeurs_1 |= (1 << j);
                }
                // Sinon, on ajoute sa valeur au masque "valeurs_0"
                else
                {
                    valeurs_0 |= (1 << j);
                }
            }
        }
        // Si la variable i a une influence sur la sortie de la fonction, on incrémente le degré
        if (poids(valeurs_1) > 0 && poids(valeurs_0) > 0)
        {
            degre_f++;
        }
    }
    
    // Retourne le degré calculé
    return degre_f;
}
/*-------------------------------------------------------------------------------------------------------*/



int main()
{
    // Exemples d'utilisation des lignes de commandes
    unsigned int x = 0x55; // 01010101 en binaire

    printf("x = %x\n", x);

    x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
    printf("a) x = %x\n", x);

    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    printf("b) x = %x\n", x);

    x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
    printf("c) x = %x\n", x);

    x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
    printf("d) x = %x\n", x);
    
    // Exemples d'utilisation de la fonction poids()
    printf("poids(0) = %d\n", poids(0));
    printf("poids(1) = %d\n", poids(1));
    printf("poids(9) = %d\n", poids(9));


    // Exemple d'utilisation de la fonction degre()
    int f1[]={0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,0}
    //int f1[] = {0,1,1,0,0,1,0,1}; 
    int n = 4; // Nombre de variables booléennes de la fonction
    int d = degre(f1, n); // Calcul du degré de la fonction
    printf("Le degre de la fonction est %d\n", d);
    
    return 0;
}
