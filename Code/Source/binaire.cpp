#include <cstdlib>
#include <iostream>
#include <string>

#include "../Header/binaire.hpp"

using namespace std;

int RechercheBinaire(int tableau[][2], int cle, int N)
{
    // Le tableau doit être trié avant de faire les manipuations.
    
    int debut = 0;
    int fin = N-1;
    int milieu = (fin - debut)/2;
    
    while (tableau[milieu][0] != cle && debut < fin)
    {
        if (tableau[milieu][0] < cle)
            debut = milieu + 1;
        else if (tableau[milieu][0] > cle)
        {
            fin = milieu - 1;
        }
        milieu = (fin + debut)/2;  
    }
    
    if(tableau[milieu][0] == cle)
        return tableau[milieu][1];
    else
        return -1; // retourne -1 si la clé n'a pas été trouvée
}
