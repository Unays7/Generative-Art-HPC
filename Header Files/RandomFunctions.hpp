#pragma once
//#include "functions.h"

#define randfloat ((float)rand() / (float)RAND_MAX)
#define randfloat2 ((2*randfloat) - 1.f)
#define UNARY 0
#define BINARY 1
#define TERMINALINDEX 2
#define TERMINALVALUE 3



class RandomFunction{

int type;
int index;
float value;
bool vectorize;
int unaryFuncCount;
int binaryFuncCount;
RandomFunction *lhs;
RandomFunction *rhs;
int v;
int g;
int h;

public:
    RandomFunction(int count, int depth, bool vectorize){
    }





};


