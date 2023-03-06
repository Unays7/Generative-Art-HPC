#include "RandomFunctions.hpp"

namespace po = boost::program_options;

void linspace(cosnt float start, const float end, const int count, float* result){
    float dx = (end - start) / (count - 1);
    for (size_t i = 0; i < count; i++){
        result[i] = start + dx*i
    }
}

float ploy(const float x, const float* args){
    return x * (args[0] * x + args[1]) + args[2];
}

