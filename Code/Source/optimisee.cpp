#include <cstdlib>
#include <iostream>
#include <string>

#include "../Header/optimisee.hpp"
#include "../Header/sequentielle.hpp"
#include "../Header/TriFusion.hpp"
#include "../Header/arbre.hpp"
#include "../Header/binaire.hpp"

using namespace std;

int RechercheOptimisee(int *tableau, int cle, int N, int R, int D) 
{
    int index;
    // Pour un très petit nombre de données, la recherche séquentielle est la meilleure puisqu'on a pas besoin de trier les donner ou créer et balancer un arbre.
    if (N <= 20)
    {
        cout << "sequentielle" << endl;
        index = RechercheSequentielle(tableau, cle, N);
    }
    else if(D == 50 || R > N + (N * 0.25))
    {
        // Si la quantité de désordre est à 50% il n'y aura pas beaucoup besoin de balancer l'arbre.
        cout << "arbre" << endl;
        BinaryTree arbre;
        // construire l'arbre
        for(int i = 0; i < N; i++)
        {
            arbre.addnode(tableau[i], i);
        }
        
        index = arbre.findNode(cle);
    }
    else
    {
        // Pour tout le reste, celui ci est meilleur lors que les écarts entre les valeurs sont semblable.
        cout << "binaire" << endl;
        int BigDataTable[N][2];
        int i;
        for (i = 0; i < N; i++)
        {
            BigDataTable[i][0] = tableau[i]; // Premiere rangée = clé
            BigDataTable[i][1] = i; // Deuxième rangée = position dans la liste non triée
        }

        TriParFusion(BigDataTable, 0, N-1);
        index = RechercheBinaire(BigDataTable, cle, N);
    }
    return index;
}