/* 
 * File:   arbre.hpp
 * Author: PPoucH
 *
 * Created on 21 octobre 2015, 15:00
 */

#include <cstdlib>
#include <iostream>
#include <string>

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
    bool hasLeftChild = false, hasRightChild = false;
    
    Node(int key, int number);
    ~Node(void);
};

class BinaryTree
{
private :
    Node * root;
    bool hasRoot=false;
public :
    void addnode(int key, int number);
    int findNode(int key);
};



#endif	/* ARBRE_HPP */

