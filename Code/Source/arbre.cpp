#include <cstdlib>
#include <iostream>
#include <string>

#include "../Header/arbre.hpp"

using namespace std;

Node::Node(int key, int number)
{
    this->key = key;
    this->number = number;
    hasLeftChild = false; hasRightChild = false;
}
Node::~Node(void)
{
    delete leftChild;
    delete rightChild;
}

BinaryTree::BinaryTree(void)
{
    hasRoot=false;
}

void BinaryTree::addnode(int key, int number)
{
    //Node * newNode = new Node(key, number);
    bool exit=false;
    
    if(hasRoot==false)
    {
        root = new Node(key, number);
        hasRoot=true;
    }
    else
    {
    	Node * focusNode = root;	
    	Node * parent;
		
    	while(!exit)
    	{
            parent = focusNode;
			
            if(key < focusNode->key)
            {
                if(focusNode->hasLeftChild)
                    focusNode = focusNode->leftChild;
				
                else
                {
                    parent->leftChild = new Node(key, number);
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
                    parent->rightChild = new Node(key, number);
                    parent->hasRightChild = true;
                    exit = true;
		}
            }
	}	
    }
}

int BinaryTree::findNode(int key)
{
    Node * focusNode = root;
	
    while(focusNode->key != key)
    {
    	if(key < focusNode->key)
    	{
            if(focusNode->hasLeftChild)
                focusNode = focusNode->leftChild;
            else
                return -1;
	}
	else
	{
            if(focusNode->hasRightChild)
                focusNode = focusNode->rightChild;
            else
                return -1;
	}
    }
    return focusNode->number;
}


