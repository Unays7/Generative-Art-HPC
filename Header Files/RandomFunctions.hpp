#pragma once
#include "functions.h"

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
        //unaryFuncCount = vectorize ? unaryVectorFunctions.size() : unaryFunction;
        //binaryFuncCount = vectorize ? binaryVectorFunctions.size() : unaryFunction;
    

    lhs = nullptr;
    rhs = nullptr;
    int r = rand() % 100;
    if (depth < 2 ){
        if (r < 10){
            value = randfloat2;
            type = TERMINALINDEX;
        }
        else{
            index = rand() % count;
            type = TERMINALINDEX;
        }
    }
    else{

        if (r < 2){
            index = rand() % count;
            type = TERMINALINDEX;
        }
        else if (r > 50 && depth < 4){
            do {
                delete lhs;
                lhs = new RandomFunction(count, depth - 1, vectorize);
            }while (lhs->type == TERMINALINDEX);
        }
        else{
            do {
                delete lhs;
                delete rhs;
                lhs = new RandomFunction(count, depth - 1, vectorize);
                rhs = new RandomFunction(count, depth - 1, vectorize);
            }while ((*lhs == *rhs) || (lhs->type == TERMINALINDEX && rhs->type == TERMINALINDEX));
            type = BINARY;
            index = rand() % binaryFuncCount;
        }
    }
}

~RandomFunction(){
    delete lhs;
    delete rhs;

}


bool operator==(const RandomFunction& other){
    if (type != other.type) return false;
    switch (type){
        case UNARY:
            return index == other.index && *lhs == *other.lhs;
        case BINARY:
            return index == other.index && *lhs == *other.lhs && *rhs == *other.rhs;
        case TERMINALINDEX:
            return value == other.value;
    }
    return false;
}

float eval(float input){
    std::vector<float> d;
    d.push_back(input);
    return eval(d);
}

float eval(float x, float y){
    std::vector<float> d;
    d.push_back(x);
    d.push_back(y);
    return eval(d);
}

};