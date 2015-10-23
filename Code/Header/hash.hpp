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

class hashH
{
private:
    
    static const int tableSize = 100;
    
    struct item
    {
        int cle;
        int i;
        item* next;
    };
    
    item* HashTable[tableSize];    
    
public:
    hashH(void);
    int Hashing(int cle);
    void AddItem(int cle, int i);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    int RechercheHash(int cle, int N);

};
//

#endif	/* HASH_HPP */

