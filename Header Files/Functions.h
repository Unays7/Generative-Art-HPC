#pragma once
#include <vector>
typedef std::function<float(float)> unaryFunction;
typedef std::function<float(float, float)> binaryFunction;


inline std::vector<unaryFunction> initUnaryFucntion(){
        std::vector<unaryFunction> result {sinf, cosf, expf, logf, sinhf, coshf, tanhf};
        result.push_back([](float x) {return -x;});
        result.push_back([](float x) {return x*x;});
        result.push_back([](float x) {return x*x*x;});
        return result;

}

inline std::vector<std::function<float(float, float)>> initBinaryFunctions(){
        std::vector<binaryFunction> result;
        result.push_back([](float a, float b) {return a + b;});
        result.push_back([](float a, float b) {return a - b;});
        result.push_back([](float a, float b) {return a * b;}); 
        return result;       
}

const std::vector<unaryFunction> unaryFunctions = initUnaryFucntion();
const std::vector<binaryFunction> binaryFunctions = initBinaryFunctions();





 