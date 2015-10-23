#include <cstdlib>
#include <iostream>
#include <string>

#include "../Header/arbre.hpp"

using namespace std;

class Node
{
public :
    
    int key;
    int number;
    Node *  leftChild;
    Node * rightChild;
    
    Node(int key, int number)
    {
        this->key = key;
        
        this->number = number;
    }
    ~Node(void)
    {
        delete leftChild;
        delete rightChild;
    }
};



class BinaryTree
{
private :
    Node * root;
public :
    void addnode(int key, int number)
    {
        Node * newNode = new Node(key, number);
        
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node * focusNode = root;
            
            Node * parent;
            
            while(true)
            {
                parent = focusNode;
                
                if(key < focusNode->key)
                {
                    focusNode = focusNode->leftChild;
                    
                    if(focusNode == NULL)
                    {
                        parent->leftChild = newNode;
                        return;
                    }
                }
                else
                {
                    focusNode = focusNode->rightChild;
                    
                    if (focusNode == NULL)
                    {
                        parent->rightChild = newNode;
                        return;
                    }
                }
            }
            
        }
    }
    
    int findNode(int key)
    {
        Node * focusNode = root;
        
        while(focusNode->key != key)
        {
            if(key < focusNode->key)
            {
                focusNode = focusNode->leftChild;
            }
            else
            {
                focusNode = focusNode->rightChild;
            }
            
            if(focusNode == NULL)
            {
                return NULL;
            }
        }
        return focusNode->number;
    }
    
};
    
    
