/* 
 * File:   main.cpp
 * Author: Julien
 *
 * Created on 9 octobre 2015, 09:56
 */

#include <cstdlib>
#include <iostream>
#include <string.h>
#include "../Header/Test.hpp"

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
    /*int cmd = -1;
    if(argc>1)
    {
        for(int i = 0;i<END_COMMAND_T;i++)
        {
            if(!strcmp(argv[1],command_list_t[i]))
            {
                cmd = i;
            }
        }
    }
    
    switch (cmd) {
        case AUTO_SHORT:
        case AUTO_LONG:
            cout << "\n\r" << "Use automatic generated values" << "\n\n\r";
            break;

        case LOAD_SHORT:
        case LOAD_LONG:
            cout << "\n\r" << "Use values loaded from a file" << "\n\n\r";
            break;

        default:
            cout << "\n\r" << "HelloWorld" << "\n\n\r";
            break;
    }
    int * p;
    for(int i=0; i<1000000; i++)
    {    
        delete p;
        p = new int(i);
        cout << p << " " <<*p << "\n\r";
    }*/
    //test();
    return 0;
}



