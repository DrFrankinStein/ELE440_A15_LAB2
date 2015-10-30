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

using namespace std;

int main(int argc, char** argv) 
{
    Testing T;
    
    T.EnterConfig();
    T.StartTest();

    return 0;
}

