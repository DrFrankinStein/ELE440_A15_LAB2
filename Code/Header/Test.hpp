/* 
 * File:   Test.hpp
 * Author: Julien
 *
 * Created on 9 octobre 2015, 12:02
 */

#ifndef TEST_HPP
#define	TEST_HPP

#include <cstdlib>
#include <iostream>
#include <string.h>

//void test(void);

using namespace std;

// -a/--auto [-N {X}] [-R {X}] [-D {X}] -algo [OUTPUTFILENAME]
// -l/--load {INPUT FILE} -algo [OUTPUTFILENAME]
// -?/--help

class Testing
{
public: 
    //Testing(void);
    Testing(int argc, char** argv);
    ~Testing(void);
        
private:
    
    int nbArg;
    char** listArg;
    
    //all (static here???)
    enum command_t {AUTO_SHORT=0, AUTO_LONG, LOAD_SHORT, LOAD_LONG, 
                    HELP_SHORT, HELP_LONG, END_COMMAND_T};
    const char* command_list_t[END_COMMAND_T] = {   "-a","--auto","-l","--load",
                                                    "-?", "--help"};
    command_t cmd = END_COMMAND_T;
    
    enum algo_t {SEQ_SHORT=0, SEQ_LONG, HASH_SHORT, HASH_LONG, BIN_SHORT, 
                BIN_LONG, TREE_SHORT, TREE_LONG, OPTIMIZE_SHORT, OPTIMIZE_LONG,
                END_ALGO_T};
    const char* algo_list_t[END_ALGO_T] = { "-s","--seq","-h","--hash",
                                            "-b","--bin","-t","--tree",
                                            "-o","--op"};
    algo_t algo = END_ALGO_T;
    
    char* outputFile = (char*)"INIT";
    
    //auto mode
    enum option_t {NBR_DATA=0,RANK_DATA,DISPERTION_RATE,END_OPTION_T};
    const char* option_list_t[END_OPTION_T] = {"-N","-R","-D"};
    option_t option = END_OPTION_T;
    
    int N=1000;
    int R=1000;
    int D=50;
    
    //load mode
    char* inputFile;
    
    void LoadModeConfig(void);
    void AutoModeConfig(void);
    void AutoModeOptionConfig(int iDArg);
};

#endif	/* TEST_HPP */

