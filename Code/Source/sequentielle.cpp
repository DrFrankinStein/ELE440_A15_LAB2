#include <cstdlib>
#include <iostream>
#include <string>
#include "../Header/sequentielle.hpp"

using namespace std;

/**
 * Cherche  la valeur "cle" dans les valeurs de "tableau"
 * @param tableau Tableau des données
 * @param cle Valeur à chercher dans le tableau
 * @param N Nombre de données dans le tableau
 * @return Index de la valeur ou -1 si non trouvée
 */
int RechercheSequentielle (int *tableau, int cle, int N, Barometre &barometre)
{
    barometre.instructions++;
    
    int i;
    for (i = 0; i < N; i++)
    {
        barometre.instructions++;
        if(tableau[i] == cle)
        {
            barometre.instructions++;
            return i;
        }
        
    }
    
    return -1; // Retourner -1 si la clé n'a pas été trouvée dans le tableau.
}