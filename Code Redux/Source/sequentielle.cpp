#include <cstdlib>
#include <iostream>
#include <string>
#include "../Header/sequentielle.hpp"

using namespace std;

/**
 * Cherche  la valeur "cle" dans les valeurs de "tableau"
 * @param tableau Tableau des donnees
 * @param cle Valeur a chercher dans le tableau
 * @param N Nombre de donnees dans le tableau
 * @return Index de la valeur ou -1 si non trouvee
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
    return -1; // Retourner -1 si la cle n'a pas ete trouvee dans le tableau.
}