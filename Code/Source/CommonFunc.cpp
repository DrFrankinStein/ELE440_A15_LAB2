#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>

#include "../Header/CommonFunc.hpp"

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

int randInt(int min, int max)
{
    srand(time(NULL));
    int range = max-min+1;
    return (rand()%range)+min; 
}

void printIntArray(int* T, int n)
{
    for(int i =0;i<n;i++)
    {
        printf("%i ", T[i]);
    }
    printf("\n\n\r");
}

void GenererDonnees (int *tableau, int N, int R, int D)
{
    if (R >= N)
    {
        
        int step = R/N;
        
        int last = 0;
        
        for (int i = 0; i < N; i++)
        {
            tableau[i] = last;
            last = last + step;
            
        }
        
        // Les données sont triées
        
        // mettre les données en désordre.
        
        int m;
        int M = N/2;
        int i;
        int k;
        int L;
        int Tp[M];
        int iExchange;
        
        for (i = 1; i <= M; i++)
        {
            Tp[i-1] = i;
        }
        
        m = M;
        
        for (i = 1; i <= ((M*D)/100); i++)
        {
            k = (rand() % m);
            L = Tp[k];
            Tp[k]=Tp[m-1];
            m = m - 1;
            
            iExchange = tableau[M-L];
            
            tableau[M-L] = tableau[M+L-1];
            
            tableau[M+L-1] = iExchange;
        }
        
    }
}
