#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int RechercheSequentielle (int *tableau, int cle, int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if(tableau[i] == cle)
        {
            return i;
        }
    }
    return -1; // Retourner -1 si la clé n'a pas été trouvée dans le tableau.
}