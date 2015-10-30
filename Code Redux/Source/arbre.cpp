#include <cstdlib>
#include <iostream>
#include <string>

#include "../Header/arbre.hpp"

using namespace std;

/**
 * Constructeur de noeud pour l'arbre
 * @param key Valeur a enregistrer
 * @param number Index de la valeur
 */
Node::Node(int key, int number, Barometre &barometre)
{
    barometre.instructions++;
    this->key = key;
    this->number = number;
    hasLeftChild = false; hasRightChild = false;
}

/**
 * Destructeur de Noeud
 */
Node::~Node(void)
{
    delete leftChild;
    delete rightChild;
}

/**
 * Constructeur de l'arbre binaire
 */
BinaryTree::BinaryTree(void)
{
    barometre.instructions=1;
    hasRoot=false;
}

/**
 * Ajoute un noeud dans l'arbre
 * @param key Valeur a ajouter
 * @param number Index de la valeur a ajoutee
 */
void BinaryTree::addnode(int key, int number)
{
    barometre.instructions++;
    bool exit=false;
    
    if(hasRoot==false)
    {
        barometre.instructions++;
        root = new Node(key, number, barometre);
        hasRoot=true;
    }
    else
    {
    	
        barometre.instructions++;
        Node * focusNode = root;	
    	Node * parent;
		
    	while(!exit)
    	{
            barometre.instructions++;
            parent = focusNode;
		
            barometre.instructions++;
            if(key < focusNode->key)
            {
                
                if(focusNode->hasLeftChild)
                    focusNode = focusNode->leftChild;
				
                else
                {
                    parent->leftChild = new Node(key, number, barometre);
                    parent->hasLeftChild = true;
                    exit=true;
				}
                
            }
            else
            {
                
                if(focusNode->hasRightChild)
                    focusNode = focusNode->rightChild;
				
				else
				{
                    parent->rightChild = new Node(key, number, barometre);
                    parent->hasRightChild = true;
                    exit = true;
				}
            }
		}	
    }
}

/**
 * Cherche une valeur dans l'arbre
 * @param key Valeur a chercher
 * @return Index de la valeur, ou -1 si non presente
 */
int BinaryTree::findNode(int key)
{
    Node * focusNode = root;
    barometre.instructions++;
    while(focusNode->key != key)
    {
    	barometre.instructions++;
        if(key < focusNode->key)
    	{
            barometre.instructions++;
            if(focusNode->hasLeftChild)
            {
                focusNode = focusNode->leftChild;
            }
            else
            {
                return -1;
            }
		}
		else
		{
            barometre.instructions++;
            if(focusNode->hasRightChild)
                focusNode = focusNode->rightChild;
            else
                return -1;
		}
    }
    return focusNode->number;
}

/**
 * Retourne et remet a zero le compte du nombre d'instructions
 * @return 
 */
int BinaryTree::RetourneBarometreInstructions(void)
{
    int tmp = barometre.instructions;
    barometre.instructions=0;
    
    return tmp;    
}


