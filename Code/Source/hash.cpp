#include <cstdlib>
#include <iostream>
#include <string>

#include "../Header/hash.hpp"

using namespace std;

hashH::hashH(void)
{
    for(int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->cle = -1;
        HashTable[i]->i = -1;
        HashTable[i]->next = NULL;
        
        
    }
}

int hashH::Hashing(int cle)
{
    
    int index;
    
    index = cle % tableSize;
    
    return index;
}

void hashH::AddItem(int cle, int i)
{
    int index = Hashing(cle);
    if (HashTable[index]->cle == -1)
    {
        HashTable[index]->cle = cle;
        HashTable[index]->i = i;
    }
    else
    {
        item* Ptr = HashTable[index];
        item* n = new item;
        n->cle = cle;
        n->i = i;
        n->next = NULL;
        while(Ptr->next != NULL)
        {
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}

int hashH::NumberOfItemsInIndex(int index)
{
    int count = 0;
    if(HashTable[index]->cle == -1)
    {
        return count;
    }
    else
    {
        count++;
        item* Ptr = HashTable[index];
        while(Ptr->next != NULL)
        {
            count++;
            Ptr = Ptr->next;
        }
        return count;
    }
}

void hashH::PrintTable()
{
    int number;
    for(int i = 0; i < tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        cout << "---- index " << i << " ----" << endl;
        cout << "# of items = " << number << endl;
        
        PrintItemsInIndex(i);
        
        cout << "---- end of index " << i << " ----" << endl;
    }
}

void hashH::PrintItemsInIndex(int index)
{
    item* Ptr = HashTable[index];
    
    if(Ptr->cle == -1)
    {
        cout << "index = " << index << "is empty";
    }
    else
    {
        cout << "index " << index << endl;
        
        while (Ptr != NULL)
        {
            cout << "-----------------\n";
            cout << Ptr->cle << endl;
            cout << Ptr->i << endl;
            cout << "-----------------\n";
            Ptr = Ptr->next;
        }
    }
    
    
}

int hashH::RechercheHash(int *tableau, int cle, int N)
    {
        int index;
        int i;
        
        for(i = 0; i < N; i++)
        {
            AddItem(tableau[i],i);
        }
        
        index = Hashing(cle);
        
        item* Ptr = HashTable[index];
        
        while(Ptr->cle != cle && Ptr->cle != -1)
        {
            Ptr = Ptr->next;
        }
        
        if (Ptr->cle == -1)
        {
            return -1;
        }
        
        return Ptr->i;
    }