/* 
 * File:   main.cpp
 * Author: Julien
 *
 * Created on 9 octobre 2015, 09:56
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "../Header/Test.hpp"
#include "../Header/hash.hpp"
#include "../Header/binaire.hpp"
#include "../Header/arbre.hpp"
#include "../Header/sequentielle.hpp"

// -a/--auto [-N {X}] [-R {X}] [-D {X}] -algo [OUTPUTFILENAME]
// -l/--load {INPUT FILE} -algo [OUTPUTFILENAME]

//enum command_t {AUTO_SHORT,AUTO_LONG, LOAD_SHORT,LOAD_LONG ,END_COMMAND_T};
//const char* command_list_t[END_COMMAND_T] = {"-a","--auto","-l","--load"};

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    Testing T(argc,argv);
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



