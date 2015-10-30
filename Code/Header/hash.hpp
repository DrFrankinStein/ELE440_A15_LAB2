/* 
 * File:   hash.hpp
 * Author: PPoucH
 *
 * Created on 16 octobre 2015, 10:12
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_HPP
#define	HASH_HPP

/**
 * Classe pour créer la table de hashage
 */
class hashH
{
private:
    
    int tableSize;
    
    struct item
    {
        int cle;
        int i;
        item* next;
    };
    
    //item* HashTable[tableSize];    
    item **HashTable;
    
public:
    hashH(int N);
    int Hashing(int cle);
    void AddItem(int cle, int i);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    int RechercheHash(int cle);

};
//

#endif	/* HASH_HPP */

