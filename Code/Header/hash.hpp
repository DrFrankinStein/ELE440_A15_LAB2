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
    
    static const int tableSize = 10;
    
    struct item
    {
        string name;
        string drink;
        item* next;
    };
    
    item* HashTable[tableSize];    
    
public:
    hashH(void);
    int Hashing(string key);
    void AddItem(string name, string drink);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    

};


#endif	/* HASH_HPP */

