/* 
 * File:   arbre.hpp
 * Author: PPoucH
 *
 * Created on 21 octobre 2015, 15:00
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "../Header/CommonFunc.hpp"

using namespace std;

#ifndef ARBRE_HPP
#define	ARBRE_HPP

class Node
{
public :
    
    int key;
    int number;
    Node *  leftChild;
    Node * rightChild;
    bool hasLeftChild, hasRightChild;
    
    Node(int key, int number, Barometre &barometre);
    ~Node(void);
};

class BinaryTree
{
private :
    Node * root;
    bool hasRoot;
    Barometre barometre;
public :
    BinaryTree(void);
    void addnode(int key, int number);
    int findNode(int key);
    int RetourneBarometreInstructions(void);
};



#endif	/* ARBRE_HPP */

