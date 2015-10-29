/* 
 * File:   optimisee.hpp
 * Author: PPoucH
 *
 * Created on 23 octobre 2015, 20:37
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

#include "../Header/sequentielle.hpp"
#include "../Header/TriFusion.hpp"
#include "../Header/arbre.hpp"
#include "../Header/binaire.hpp"
#include "../Header/TriInsertion.hpp"
#include "../Header/TriBase.hpp"

using namespace std;

#ifndef OPTIMISEE_HPP
#define	OPTIMISEE_HPP

void InitRechercheOptimisee(int *tableau, int N, int R, int D, string* methodeTri);
int RechercheOptimisee(int *tableau, int cle, int N, int R, int D);

#endif	/* OPTIMISEE_HPP */

