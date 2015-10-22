/* 
 * File:   main.cpp
 * Author: Julien
 *
 * Created on 9 octobre 2015, 09:56
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "../Header/hash.hpp"
#include "../Header/binaire.hpp"
#include "../Header/arbre.hpp"
#include "../Header/sequentielle.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    int tableau[20] = {30,24,3,5,66,7,9,11,15,28,29,40,42,54,67,68,69,400,2043,5000};
    BinaryTree tree;
    int i;
    
    for (i = 0; i < 20; i++)
    {
        tree.addnode(tableau[i],i);
    }
    int cle = tree.findNode(40);
    
      cout << "tableau = [" << cle << "] => " << tableau[cle] << endl;
    
    return 0;
}

