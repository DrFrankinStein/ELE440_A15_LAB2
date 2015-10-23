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

class hash
{
public:
    hash();
    int Hash(string key);
    void AddItem(string name, string drink);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    
private:
    
    static const int tableSize = 10;
    
    struct item
    {
        string name;
        string drink;
        item* next;
    };
    
    item* HashTable[tableSize];
};


#endif	/* HASH_HPP */

