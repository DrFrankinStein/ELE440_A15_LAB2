#include "../Header/TriInsertion.hpp"

//source : https://fr.wikipedia.org/wiki/Tri_par_insertion
Barometre TriParInsertion(int Donnees[][2],int taille)
{
    int tmp[2], j;
    Barometre barometre;
    barometre.instructions=1;
    barometre.memory = 4*sizeof(int)+sizeof(int*);
    for(int i=1; i<=taille-1; i++)
    {
        barometre.instructions++;
        tmp[0]=Donnees[i][0];
		tmp[1]=Donnees[i][1];
        j=i;
        while(j>0&&Donnees[j-1][0]>tmp[0])
        {
            barometre.instructions++;
            Donnees[j][0]=Donnees[j-1][0];
			Donnees[j][1]=Donnees[j-1][1];
            j--;
        }
        Donnees[j][0]=tmp[0];
		Donnees[j][1]=tmp[1];
    }
    return barometre;
}
	