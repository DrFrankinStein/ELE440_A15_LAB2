#include <cstdlib>
#include <iostream>
#include <string>

#include "../Header/arbre.hpp"

using namespace std;

Node::Node(int key, int number)
{
	this->key = key;
	this->number = number;
}
Node::~Node(void)
{
	delete leftChild;
	delete rightChild;
}

void BinaryTree::addnode(int key, int number)
{
    //Node * newNode = new Node(key, number);
    bool exit=false;
    
    if(root==NULL)
    {
        root = new Node(key, number);
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
                if(focusNode->leftChild!=NULL)
                focusNode = focusNode->leftChild;
				
                else if(focusNode->leftChild == NULL)
                {
                    parent->leftChild = new Node(key, number);
                    exit=true;
		}
            }
            else
            {
                if(focusNode->rightChild!=NULL)
                    focusNode = focusNode->rightChild;
				
		else if (focusNode->rightChild == NULL)
		{
                    parent->rightChild = new Node(key, number);
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
            focusNode = focusNode->leftChild;
	}
	else
	{
            focusNode = focusNode->rightChild;
	}
		
        if(focusNode == NULL)
	{
            return -1;
	}
    }
    return focusNode->number;
}


