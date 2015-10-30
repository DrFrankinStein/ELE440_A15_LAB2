#include "../Header/TriFusion.hpp"

//LIVRE p. 27+30
Barometre Fusion(int Donnees[][2], int indexPremier, int indexDernier, int indexMilieu)
{
    Barometre barometre;
    barometre.instructions=1;
    int i,j,k;
    int n1= indexMilieu-indexPremier+1;
    int n2= indexDernier-indexMilieu;
    
    int L[n1][2];
    int R[n2][2];
    
    barometre.memory=(8+n1+n2)*sizeof(int)+(3)*sizeof(int*);
    
    for(i=0; i<=n1-1;i++)
    {    
        L[i][0]=Donnees[indexPremier+i][0];
        L[i][1]=Donnees[indexPremier+i][1];
        barometre.instructions++;
    }
    for(j=0; j<=n2-1;j++)
    {
        R[j][0]=Donnees[indexMilieu + 1 +j][0];
        R[j][1]=Donnees[indexMilieu + 1 +j][1];
        barometre.instructions++;
    }
    
    i=0;
    j=0;
    for(k=indexPremier;k<=indexDernier;k++)
    {
        barometre.instructions++;
        if(L[i][0]<=R[j][0])
        {
            if(i<n1)
            {
                Donnees[k][0]=L[i][0];
                Donnees[k][1]=L[i][1];
                i++; 
            }
            else
            {
                Donnees[k][0]=R[j][0];
                Donnees[k][1]=R[j][1];
                j++;
            }
            barometre.instructions++;
        }
        else
        {
            if(j<n2)
            {
                Donnees[k][0]=R[j][0];
                Donnees[k][1]=R[j][1];
                j++; 
            }
            else
            {
                Donnees[k][0]=L[i][0];
                Donnees[k][1]=L[i][1];
                i++;
            }
            barometre.instructions++;
        }    
    }
    return barometre;
}

Barometre TriParFusion(int Donnees[][2], int indexPremier, int indexDernier)
{
    Barometre barometre;
    barometre.instructions=1;
    barometre.memory=(2)*sizeof(int)+(1)*sizeof(int*);
    
    if(indexPremier<indexDernier)
    {
        Barometre tmp1, tmp2;
        
       barometre.instructions++;
       barometre.memory+=sizeof(int);
       tmp1=barometre;
       
       int indexMilieu=(indexPremier+indexDernier)/2;
       
       tmp2=TriParFusion(Donnees,indexPremier, indexMilieu);
       barometre.instructions+=tmp2.instructions;
       barometre.memory = barometre.memory>tmp2.memory ? barometre.memory:tmp1.memory+tmp2.memory ;
       
       tmp2=TriParFusion(Donnees,indexMilieu+1, indexDernier);
       barometre.instructions+=tmp2.instructions;
       barometre.memory = barometre.memory>tmp2.memory ? barometre.memory:tmp1.memory+tmp2.memory ;
       
       
       tmp2=Fusion(Donnees,indexPremier,indexDernier,indexMilieu);
       barometre.instructions+=tmp2.instructions;
       barometre.memory = barometre.memory>tmp2.memory ? barometre.memory:tmp1.memory+tmp2.memory ;
    }
    return barometre;
}