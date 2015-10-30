#include "../Header/TriBase.hpp"

//https://www.cs.usfca.edu/~galles/visualization/RadixSort.html
Barometre TriParBase(int Donnees[][2],int taille, int nbreChiffre)
{
    Barometre barometre;
    barometre.instructions=1;
    int positifChiffre[10], negatifChiffre[10],chiffre, base=1;
    int tmpDonnees[taille][2];
    barometre.memory=(2+10+10+2+taille+2)*sizeof(int)+4*sizeof(int*);

    // Pour toutes les puissances de 10
    for(int i=0; i<nbreChiffre;i++)
    {
        // initialiser le tableaux de comptage a zero.
        barometre.instructions++;
        // Pour j allant de 0 a 9
        for(int j =0; j<10;j++)//Initialisation des bases
        {
            //initialiser a valeur a zero
            barometre.instructions++;
            positifChiffre[j]=0; 
            negatifChiffre[j]=0;
        }
        
        int tmp1, tmp2;
        // Pour tout les nombres a trier
        for(int j=0; j<taille;j++)//Comptage des bases
        {
            barometre.instructions++;
            // Trouver le chiffre de la puissance de 10 correspondante
            tmp1 = Donnees[j][0];
            tmp2 = Donnees[j][1];
            chiffre = (Donnees[j][0]/base)%10;
            // Si le nombre est positif
            if(Donnees[j][0]>=0)
            {
                // Incrementer de 1 la case correspondant du tableau de compteurs
                positifChiffre[chiffre]++;
            }
            else
            {
                negatifChiffre[-chiffre]++;
            }
            barometre.instructions++;
        }
        
        // 
        for(int k=9;k>0;k--)//comptage des index negatifs
        {
            barometre.instructions++;
            negatifChiffre[k-1]+=negatifChiffre[k];
        }
        
        positifChiffre[0]= positifChiffre[0]+negatifChiffre[0]; //index des 0 positifs
        
        // Pour toutes les cases du tableau de compteurs 
        for(int k=1; k<10; k++) //comptage des index positifs
        {
            // additionner la valeur de la case (i) avec celle de la case adjacente (i+1))
            barometre.instructions++;
            positifChiffre[k]+=positifChiffre[k-1];
        }
        
        // Pour toutes les donnees a trier,
        for(int j=taille-1; j>=0;j--)
        {
            barometre.instructions++;
            // Trouver le chiffre de la puissance de 10 correspondante 
            chiffre = (Donnees[j][0]/base)%10;
            if(Donnees[j]>=0)
            {
                // diminuer la valeur de la case du tableau de compteurs de 1
                positifChiffre[chiffre]--;
                // Placer la donnee complete dans la nouvelle matrice a la case precise par le nombre de la case du tableau de compteur.
                tmpDonnees[positifChiffre[chiffre]][0]=Donnees[j][0];
                tmpDonnees[positifChiffre[chiffre]][1]=Donnees[j][1];
            }
            else
            {
                negatifChiffre[-chiffre]--;
                tmpDonnees[negatifChiffre[-chiffre]][0]=Donnees[j][0];
		tmpDonnees[negatifChiffre[-chiffre]][1]=Donnees[j][1];
            }
            barometre.instructions++;
        }
        // augmenter le facteur de 10 de 1.
        base*=10;
        
        for(int j =0; j<taille;j++)
        {
            barometre.instructions++;
            tmp1 = Donnees[j][0];
            tmp2 = Donnees[j][1];
            swap(&Donnees[j][0],&tmpDonnees[j][0]);
            swap(&Donnees[j][1],&tmpDonnees[j][1]);
            tmp1 = Donnees[j][0];
            tmp2 = Donnees[j][1];
        }
    }
    return barometre;
}