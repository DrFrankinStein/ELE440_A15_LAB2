/* 
 * File:   main.cpp
 * Author: Julien
 *
 * Created on 9 octobre 2015, 09:56
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>

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
int * LoadT1(const char* address, int* N , int* R, int* D)
{
    FILE * textfile;
    char c;
    int index=0;
    int tmp;
    int * T1;
    string buffer="";
    
    textfile = fopen (address,"r");
    if (textfile == NULL) 
        perror ("Error opening file");
    else 
    {
        do 
        {
            c = fgetc (textfile);
            if(c != EOF)
            {
                if(c>='0'&& c<='9')
                {
                    buffer+=c;
                }
                else
                {
                    if(buffer!="")
                    {
                        sscanf(buffer.c_str(),"%i",&tmp); 
                        switch(index)
                        {
                            case 0 :
                                *N = tmp;
                                T1 = new int[tmp];
                                break;
                            case 1 :
                                *R = tmp;
                                break;
                            case 2 :
                                *D = tmp;
                                break;
                            default :
                                T1[index-3] = tmp;
                                break;
                        }
                        buffer="";
                        index++;
                    }    
                }
            }
        } 
        while (c != EOF);
    fclose (textfile);
    }
    return T1;
}

int * LoadT2(const char* address, int* N)
{
    FILE * textfile;
    char c;
    int index=0;
    int tmp;
    int * T2;
    string buffer="";
    
    textfile = fopen (address,"r");
    if (textfile == NULL) 
        perror ("Error opening file");
    else 
    {
        do 
        {
            c = fgetc (textfile);
            if(c != EOF)
            {
                if(c>='0'&& c<='9')
                {
                    buffer+=c;
                }
                else
                {
                    if(buffer!="")
                    {
                        sscanf(buffer.c_str(),"%i",&tmp); 
                        switch(index)
                        {
                            case 0 :
                                *N = tmp;
                                T2 = new int[tmp];
                                break;
                   
                            default :
                                T2[index-1] = tmp;
                                break;
                        }
                        buffer="";
                        index++;
                    }    
                }
            }
        } 
        while (c != EOF);
    fclose (textfile);
    }
    return T2;
}
/*
/*
 * 
 */
int main(int argc, char** argv) 
{
    Testing T(argc,argv);
    /*int tableau[20] = {30,24,3,5,66,7,9,11,15,28,29,40,42,54,67,68,69,400,2043,5000};
    BinaryTree tree;
    int i;
    
    for (i = 0; i < 20; i++)
    {
        tree.addnode(tableau[i],i);
    }
    int cle = tree.findNode(40);
    
    cout << "tableau = [" << cle << "] => " << tableau[cle] << endl;*/
    /*int *T1 , *T2;
    int N, R, D;
    int K;
    
    T1 = LoadT1("C:/Users/Julien/Desktop/ressources/donnees.txt", &N, &R, &D);
    T2 = LoadT2("C:/Users/Julien/Desktop/ressources/requete.txt", &K);
    printf("%i \n\n\r",K);
    for(int i =0;i<10;i++)
    {
        printf("%i ", T2[i]);
    }
    printf("\n\n\r");*/
    return 0;
}

