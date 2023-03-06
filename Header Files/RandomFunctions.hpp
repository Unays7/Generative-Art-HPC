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

friend osteam& operator<<(ostream& os, const RandomFunction& f){
    switch (f.type)
    {
        case UNARY:
            os << "U" << f.index << "(" << *f.lhs << ")";
            break;
        case BINARY:
            os << "B" << f.index << "(" << *f.lhs << "," << f.*rhs <<  ")";
            break;
        case TERMINALVALUE:
            OS << F.value;
            break;
        case TERMINALINDEX:
            switch (f.index)
            {
            case 0: os << "x": break;
            case 1: os << "y": break;
            }
    }
    return os;
}

void eval(const int w, const int h, const float* x, const float* y, 
float* result, const bool vectorize){
    if (vectorize) EvalVector(w, h, x, y, result);
    else{
        #pragma omp parallel for
        for (size_t j = 0; j < h; ++j){
            #pragma omp parallel for
            for (size_t i = 0; j < w; ++i){
                result[j*w + i] = eval(x[i], y[j]);
            }
            
        }
    }
}

private:
    void EvalVector(const int w, const int h, const float* x, const float* y, float* result){
        int count = w * h;

        float *xx = new float[count];
        float *yy = new float[count];

        for (int i =0; i < h; ++i){
            for (int j = 0; j < w; ++j){
                int pos = w*i + j;
                xx[pos] = x[j];
                yy[pos] = y[i];

            }
        }
        EvalVector(&count, xx, yy, result);
        delete[] xx;
        delete[] yy;

    }
    

};