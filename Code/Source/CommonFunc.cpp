#include "../Header/CommonFunc.hpp"

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
