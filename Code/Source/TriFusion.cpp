#include "../Header/TriFusion.hpp"

//LIVRE p. 27+30
Barometre Fusion(int *Donnees, int indexPremier, int indexDernier, int indexMilieu)
{
    Barometre barometre;
    barometre.instructions=1;
    int i,j,k;
    int n1= indexMilieu-indexPremier+1;
    int n2= indexDernier-indexMilieu;
    
    int L[n1];
    int R[n2];
    
    barometre.memory=(8+n1+n2)*sizeof(int)+(3)*sizeof(int*);
    
    for(i=0; i<=n1-1;i++)
    {    
        L[i]=Donnees[indexPremier+i];
        barometre.instructions++;
    }
    for(j=0; j<=n2-1;j++)
    {
        R[j]=Donnees[indexMilieu + 1 +j];
        barometre.instructions++;
    }
    
    i=0;
    j=0;
    for(k=indexPremier;k<=indexDernier;k++)
    {
        barometre.instructions++;
        if(L[i]<=R[j])
        {
            if(i<n1)
            {
                Donnees[k]=L[i];
                i++; 
            }
            else
            {
                Donnees[k]=R[j];
                j++;
            }
            barometre.instructions++;
        }
        else
        {
            if(j<n2)
            {
                Donnees[k]=R[j];
                j++; 
            }
            else
            {
                Donnees[k]=L[i];
                i++;
            }
            barometre.instructions++;
        }    
    }
    return barometre;
}

Barometre TriParFusion(int *Donnees, int indexPremier, int indexDernier)
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