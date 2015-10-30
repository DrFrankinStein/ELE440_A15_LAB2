#include <cstdlib>
#include <iostream>
#include <string>

#include "../Header/hash.hpp"

using namespace std;

/**
 * Constructeur de hashH
 * @param N : Taille de la table de hashage
 */
hashH::hashH(int N)
{
    barometre.instructions=1;
    tableSize = N;
    HashTable = new item*[tableSize];
    for(int i = 0; i < tableSize; i++)
    {
        barometre.instructions++;
        HashTable[i] = new item;
        HashTable[i]->cle = -1;
        HashTable[i]->i = -1;
        HashTable[i]->next = NULL;
    }
}

/**
 * Fonction pour placer la clé dans le bon bucket
 * @param cle : valeur à classer
 * @return l'index où cette valeur doit être classer
 */
int hashH::Hashing(int cle)
{
    int index;
    barometre.instructions++;
    index = cle % tableSize;
    
    return index;
}

/**
 * Ajoute une valeur dans la table de hashage
 * @param cle Valeur à ajoutée dans la table
 * @param i Index de la valeur
 */
void hashH::AddItem(int cle, int i)
{
    barometre.instructions++;
    int index = Hashing(cle);
    if (HashTable[index]->cle == -1)
    {
        barometre.instructions++;
        HashTable[index]->cle = cle;
        HashTable[index]->i = i;
    }
    else
    {
        barometre.instructions++;
        item* Ptr = HashTable[index];
        item* n = new item;
        n->cle = cle;
        n->i = i;
        n->next = NULL;
        while(Ptr->next != NULL)
        {
            barometre.instructions++;
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}

/**
 * Retourne le nombre d'item à l'index indiqué
 * @param index Index à vérifier
 * @return Nombre d'item à l'index indiqué
 */
int hashH::NumberOfItemsInIndex(int index)
{
    barometre.instructions++;
    int count = 0;
    if(HashTable[index]->cle == -1)
    {
        barometre.instructions++;
        return count;
    }
    else
    {
        barometre.instructions++;
        count++;
        item* Ptr = HashTable[index];
        while(Ptr->next != NULL)
        {
            barometre.instructions++;
            count++;
            Ptr = Ptr->next;
        }
        return count;
    }
}

/**
 * Imprime la Hash Table
 */
void hashH::PrintTable(void)
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

/**
 * Imprime les items de la hash table à l'index choisi
 * @param index Index de la hashtable à imprimer
 */
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

/**
 * Recherche la valeur "cle" dans la table de hashage
 * @param cle Valeur à rechercher
 * @return L'index où se trouve la valeur ou -1 si non présente
 */
int hashH::RechercheHash(int cle)
{
    barometre.instructions++;
    int index;
    bool exit= false;
        
    index = Hashing(cle);
        
    item* Ptr = HashTable[index];
        
    while(Ptr->cle != cle && Ptr->cle != -1 && exit!=true)
    {
        barometre.instructions++;
        if(Ptr->next==NULL)
            exit = true;
        else
            Ptr = Ptr->next;
    }
        
    barometre.instructions++;
    if (Ptr->cle == -1 || exit == true)
    {
        return -1;
    }
    else    
        return Ptr->i;
}

/**
 * Retourne et remet à zéro le compte du nombre d'instructions
 * @return 
 */
int hashH::RetourneBarometreInstructions(void)
{
    int tmp = barometre.instructions;
    barometre.instructions=0;
    
    return tmp;    
}