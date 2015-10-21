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
    int tableau[20] = {0,2,3,5,6,7,9,11,15,28,29,40,42,54,67,68,69,400,2043,5000};
    int cle = RechercheSequentielle(tableau, 40, 20);
    
      cout << "tableau = [" << cle << "] => " << tableau[cle] << endl;
    
    return 0;
}

