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
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include "../Header/sequentielle.hpp"
#include "../Header/binaire.hpp"
#include "../Header/hash.hpp"
#include "../Header/arbre.hpp"
#include "../Header/optimisee.hpp"

#include "../Header/CommonFunc.hpp"
#include "../Header/TriFusion.hpp"
#include "../Header/TriInsertion.hpp"
#include "../Header/TriBase.hpp"


//void test(void);

using namespace std;

// -a/--auto -N {X} -R {X} -D {X} {SearchFile} -algo [OutputFile] //11
// -l/--load {InputFile} {SearchFile} -algo [OutputFile] //6
// -ml/--manload {InputFile} -algo //4
// -ma/--manauto -N {X} -R {X} -D {X} -algo //9
// -?/--help  //2

class Testing
{
public: 
    Testing(void);
    //Testing(int argc, char** argv);
    
    void EnterConfig(void);
    void StartTest(void);
    
    ~Testing(void);
        
private:
    
    //int nbArg;
    //char** listArg;
    
    int *DataTable;//T1
    int *SearchTable;//T2
    int *ResultTable;//T3
    int K, N, R, D;
    int count;
    
    //all (static here???)
    enum command_t {AUTO_SHORT=0, AUTO_LONG, LOAD_SHORT, LOAD_LONG, 
                    HELP_SHORT, HELP_LONG, MANUAL_AUTO_SHORT, MANUAL_AUTO_LONG, 
                    MANUAL_LOAD_SHORT, MANUAL_LOAD_LONG, END_COMMAND_T};
    const char* command_list_t[END_COMMAND_T] = {   "-a", "--auto","-l","--load",
                                                    "-?", "--help","-ma","--manauto",
                                                    "-ml","--manload"};
    command_t cmd = END_COMMAND_T;
    
    enum algo_t {SEQ_SHORT=0, SEQ_LONG, HASH_SHORT, HASH_LONG, BIN_SHORT, 
                BIN_LONG, TREE_SHORT, TREE_LONG, OPTIMIZE_SHORT, OPTIMIZE_LONG,
                END_ALGO_T};
    const char* algo_list_t[END_ALGO_T] = { "-s","--seq","-h","--hash",
                                            "-b","--bin","-t","--tree",
                                            "-o","--op"};
    algo_t algo = END_ALGO_T;
    
    string outputFile = "INIT";
    string methodeTri = "Pas de tri";
    
    //auto mode
    /*enum option_t {NBR_DATA=0,RANK_DATA,DISPERTION_RATE,END_OPTION_T};
    const char* option_list_t[END_OPTION_T] = {"-N","-R","-D"};
    option_t option = END_OPTION_T;*/
    
    //load mode
    /*void LoadModeConfig(void);
    void AutoModeConfig(void);
    void AutoModeOptionConfig(int iDArg);
    void ManualLoadConfig(void);
    void ManualAutoConfig(void);*/
    
    bool LoadT1(const char* address);
    bool LoadT2(const char* address);
    void SaveT3(const char* address);
    
    
    void SetData(void);
    void SetNRD(void);
    void SetDataFileAddress(void);
    void SetSearch(void);
    void SetSearchFileAddress(void);
    void SetOutputFileAddress(void);
    void SetAlgo(void);
    
    void AutoRequest(void);
    void ManualRequest(void);
    
    
    
};

#endif	/* TEST_HPP */

