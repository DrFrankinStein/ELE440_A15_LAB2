#include <cstdlib>
#include <iostream>
#include <string>

#include "../Header/hash.hpp"

using namespace std;

hash::hash()
{
    for(int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;
        
        
    }
}

int hash::Hash(string key)
{
    int index;
    
    int hash = 0;
    
    for (int i = 0; i < key.length(); i++)
    {
        hash = hash + (int)key[i];
    }
    
    index = hash % tableSize;
    
    return index;
}

void hash::AddItem(string name, string drink)
{
    int index = Hash(name);
    if (HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else
    {
        item* Ptr = HashTable[index];
        item* n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;
        while(Ptr->next != NULL)
        {
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}

int hash::NumberOfItemsInIndex(int index)
{
    int count = 0;
    if(HashTable[index]->name == "empty")
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

void hash::PrintTable()
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

void hash::PrintItemsInIndex(int index)
{
    item* Ptr = HashTable[index];
    
    if(Ptr->name == "empty")
    {
        cout << "index = " << index << "is empty";
    }
    else
    {
        cout << "index " << index << endl;
        
        while (Ptr != NULL)
        {
            cout << "-----------------\n";
            cout << Ptr->name << endl;
            cout << Ptr->drink << endl;
            cout << "-----------------\n";
            Ptr = Ptr->next;
        }
    }
}