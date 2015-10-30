/* 
 * File:   CommonFunc.h
 * Author: Julien
 *
 * Created on 24 septembre 2015, 08:58
 */

#ifndef COMMONFUNC_H
#define	COMMONFUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Barometres
{
    unsigned long long instructions;
    unsigned long long memory;
}Barometre;

void swap(int *a, int *b);
int randInt(int min, int max);
void printIntArray(int* T, int n);
void GenererDonnees (int *tableau, int N, int R, int D);

#endif	/* COMMONFUNC_H */

