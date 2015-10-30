#include <cstdlib>
#include <iostream>
#include <string>

#include "../Header/binaire.hpp"

using namespace std;

/**
 * Fonction de recherche binaire... Attention de bien trier les donnees avant d'utiliser cette fonction
 * @param tableau Tableau de donnees e inspecter
 * @param cle Valeur e chercher dans le tableau
 * @param N Nombre de valeur dans le tableau
 * @return L'index dans ou se trouve la valeur ou -1 si non presente
 */
int RechercheBinaire(int tableau[][2], int cle, int N, Barometre &barometre)
{
    // Le tableau doit être trie avant de faire les manipuations.
    barometre.instructions++;
    int debut = 0;
    int fin = N-1;
    int milieu = (fin - debut)/2;
    
    while (tableau[milieu][0] != cle && debut < fin)
    {
        barometre.instructions++;
        if (tableau[milieu][0] < cle)
        {
            barometre.instructions++;
            debut = milieu + 1;
        }
        else if (tableau[milieu][0] > cle)
        {
            barometre.instructions++;
            fin = milieu - 1;
        }
        milieu = (fin + debut)/2;  
    }
    
    barometre.instructions++;
    if(tableau[milieu][0] == cle)
    {
        return tableau[milieu][1];
    }
    else
    {
        return -1; // retourne -1 si la cle n'a pas ete trouvee
    }
}
