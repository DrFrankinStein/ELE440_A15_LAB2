#include "../Header/optimisee.hpp"

//Variables globales
BinaryTree * arbre;
int(*BigDataTable)[2];

/**
 * Fonction servant à initialiser les données selon le type de données à analyser
 * @param tableau Tableau contenant les données qu'il faut analyser
 * @param N Nombre de données dans le tableau
 * @param R Intervalle de données dans le tableau
 * @param D Taux de désordre des données
 * @param methodeTri Pointeur d'une string pour fin d'enregistrement du type de tri
 */
Barometre InitRechercheOptimisee(int *tableau, int N, int R, int D, string* methodeTri)
{
    Barometre barometrePrep;
    barometrePrep.instructions=1;
    // Pour un très petit nombre de données, la recherche séquentielle est la meilleure puisqu'on a pas besoin de trier les donner ou créer et balancer un arbre.
    if (N <= 20)
        barometrePrep.instructions++;
    
    // Si la quantité de désordre est à 50% il n'y aura pas beaucoup besoin de balancer l'arbre.
    else if(D == 50 || (R > (N + (N * 0.25))))
    {   
        barometrePrep.instructions++;
        arbre = new BinaryTree();
        // construire l'arbre
        for(int i = 0; i < N; i++)
        {
            arbre->addnode(tableau[i], i);
        }
        barometrePrep.instructions = arbre->RetourneBarometreInstructions();
    }

    // Pour tout le reste, celui ci est meilleur lors que les écarts entre les valeurs sont semblable.
    else
    {
        BigDataTable = new int[N][2];
        
        //Copier les données dans le nouveau tableau avec leur position
        for (int i = 0; i < N; i++)
        {
            barometrePrep.instructions++;
            BigDataTable[i][0] = tableau[i]; // Premiere rangée = clé
            BigDataTable[i][1] = i; // Deuxième rangée = position dans la liste non triée
        }

        //Si le taux de désordre est 0, ou si le taux de désordre est plus petit que 5% et que le nombre 
        //de données est plus petit que 2000
        if(D==0 || (D<5 && N<2000))
        {
            *methodeTri = "Tri par Insertion";
            barometrePrep.instructions+=TriParInsertion(BigDataTable,N).instructions;
        }
        
        //Si l'intervalle des données est plus petit que 10^6
        else if(R<1000000)
        {
            int nbChiffre;
            nbChiffre=(int)log10(R)+1;
            *methodeTri = "Tri par Base";
            barometrePrep.instructions+=TriParBase(BigDataTable,N,nbChiffre).instructions;
        }
        
        //Dans tout les autres cas
        else
        {
            *methodeTri = "Tri par Fusion";
            barometrePrep.instructions+=TriParFusion(BigDataTable, 0, N-1).instructions;
        }
    }
    return barometrePrep;
}

/**
 * 
 * @param tableau Tableau contenant les données qu'il faut analyser
 * @param cle La valeur à chercher dans le tableau
 * @param N Nombre de données dans le tableau
 * @param R Intervalle de données dans le tableau
 * @param D Taux de désordre des données
 * @return L'index où se trouve la valeur dans le tableau ou -1 si non présent
 */
int RechercheOptimisee(int *tableau, int cle, int N, int R, int D, Barometre &barometre) 
{
    int index;
    // Pour un très petit nombre de données, la recherche séquentielle est la meilleure puisqu'on a pas besoin de trier les donner ou créer et balancer un arbre.
    if (N <= 20)
    {
        index = RechercheSequentielle(tableau, cle, N, barometre);
    }
    // Si la quantité de désordre est à 50% il n'y aura pas beaucoup besoin de balancer l'arbre.
    else if(D == 50 || R > N + (N * 0.25))
    {
        index = arbre->findNode(cle);
        barometre.instructions+=arbre->RetourneBarometreInstructions();
    }
    // Pour tout le reste, celui ci est meilleur lors que les écarts entre les valeurs sont semblable.
    else
    {
        index = RechercheBinaire((int(*)[2])BigDataTable, cle, N,barometre);
    }
    return index;
}